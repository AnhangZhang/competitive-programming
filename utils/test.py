import sys
import os
import subprocess
import time
from pathlib import Path
import difflib

SOURCE_FILE = Path("main.cpp")
SAMPLES_DIR = Path("samples")
TIMEOUT_SEC = 5.0  # 超时时间 (秒)

class Colors:
    GREEN = '\033[92m'
    RED = '\033[91m'
    YELLOW = '\033[93m'
    BLUE = '\033[94m'
    ENDC = '\033[0m'

def compile_source():
    print(f"[INFO] Compiling {SOURCE_FILE}...")
    
    exe_name = "sol_exec"
    if os.name == 'nt':
        exe_name += ".exe"
    
    compile_cmd = [
        "g++", 
        str(SOURCE_FILE), 
        "-o", exe_name,
        "-DLOCAL",
        "-std=c++2a", 
        "-O2",
        "-Wall",
        "-Wfatal-errors",
        "-D_GLIBCXX_DEBUG"
    ]

    try:
        subprocess.check_call(compile_cmd)
        return Path(exe_name)
    except subprocess.CalledProcessError:
        print(f"[ERROR] Compilation Failed!")
        sys.exit(1)

def normalize_output(text):
    if not text:
        return []
    return [line.strip() for line in text.strip().splitlines() if line.strip()]

def run_tests(exe_path):
    if not SAMPLES_DIR.exists():
        print(f"[ERROR] Samples directory not found: {SAMPLES_DIR}")
        return

    in_files = sorted(SAMPLES_DIR.glob("*.in"), key=lambda p: (len(p.name), p.name))

    if not in_files:
        print(f"{Colors.YELLOW}⚠️  No .in files found in {SAMPLES_DIR}{Colors.ENDC}")
        return

    print(f"[INFO] Running {len(in_files)} tests...\n")

    all_passed = True

    for in_file in in_files:
        print(f"{Colors.YELLOW}{'='*35}{Colors.ENDC}")
        out_file = in_file.with_suffix(".out")
        res_file = in_file.with_suffix(".res")
        
        test_name = in_file.name
        
        if not out_file.exists():
            print(f"{Colors.YELLOW}❓ {test_name}: Skipped (No corresponding .out file){Colors.ENDC}")
            continue

        with open(out_file, 'r', encoding='utf-8') as f:
            expected_text = f.read()

        start_time = time.time()
        try:
            with open(in_file, 'r', encoding='utf-8') as f_in:
                result = subprocess.run(
                    [str(exe_path.resolve())],
                    stdin=f_in,
                    capture_output=True,
                    text=True,
                    timeout=TIMEOUT_SEC
                )
                actual_text = result.stdout
                debug_test = result.stderr
                
                with open(res_file, 'w', encoding='utf-8') as f_res:
                    f_res.write(actual_text)
                
        except subprocess.TimeoutExpired:
            print(f"{Colors.RED} {test_name}: TLE (Time Limit Exceeded > {TIMEOUT_SEC}s){Colors.ENDC}")
            all_passed = False
            continue
        except Exception as e:
            print(f"{Colors.RED} {test_name}: Runtime Error ({e}){Colors.ENDC}")
            all_passed = False
            continue

        end_time = time.time()
        duration = (end_time - start_time) * 1000 # ms

        norm_actual = normalize_output(actual_text)
        norm_expected = normalize_output(expected_text)

        if norm_actual == norm_expected:
            print(f"{Colors.GREEN} {test_name}: AC ({duration:.0f}ms){Colors.ENDC}")
        else:
            print(f"{Colors.RED} {test_name}: WA {Colors.ENDC}")
            print(f"{Colors.YELLOW}--- Expected ---{Colors.ENDC}")
            print(expected_text.strip())
            print(f"{Colors.YELLOW}--- Actual (Saved to {res_file.name}) ---{Colors.ENDC}") # 提示已保存
            print(actual_text.strip())
            print()
            all_passed = False

        if debug_test.strip():
            print(debug_test)
        print()
        print()

    if exe_path.exists():
        os.remove(exe_path)

    if all_passed:
        print(f"{Colors.GREEN} All tests passed!{Colors.ENDC}")
    else:
        print(f"{Colors.RED} Some tests failed.{Colors.ENDC}")

if __name__ == "__main__":
    if not SOURCE_FILE.exists():
        print(f"Error: {SOURCE_FILE} not found.")
        sys.exit(1)
        
    exe = compile_source()
    run_tests(exe)