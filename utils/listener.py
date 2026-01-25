import http.server
import json
import os
import sys
import shutil
from pathlib import Path

PORT = 10043
GLOBAL_ROOT = Path("~/dev/programming").expanduser()
SAMPLES_DIR = GLOBAL_ROOT / "samples"

class SingleShotHandler(http.server.BaseHTTPRequestHandler):
    def log_message(self, format, *args):
        return

    def do_POST(self):
        try:
            content_length = int(self.headers['Content-Length'])
            body = self.rfile.read(content_length).decode('utf-8')
            data = json.loads(body)
        except Exception as e:
            print(f"[ERROR] Error parsing JSON: {e}")
            return

        raw_problem = data.get('name', 'Unknown Problem')
        print(f"[INFO] >> Received: {raw_problem}")

        if SAMPLES_DIR.exists():
            shutil.rmtree(SAMPLES_DIR)
        SAMPLES_DIR.mkdir(parents=True, exist_ok=True)

        tests = data.get('tests', [])
        for i, test in enumerate(tests):
            in_name = f"{i+1}.in"
            out_name = f"{i+1}.out"
            
            with open(SAMPLES_DIR / in_name, 'w', newline='\n') as f:
                f.write(test.get('input', ''))
            with open(SAMPLES_DIR / out_name, 'w', newline='\n') as f:
                f.write(test.get('output', ''))
        
        print(f"[INFO] Saved {len(tests)} cases to '{SAMPLES_DIR}'")
        print()

        self.server.should_stop = True
        return

class SingleShotServer(http.server.HTTPServer):
    def serve_until_stopped(self):
        self.should_stop = False
        while not self.should_stop:
            self.handle_request()

if __name__ == '__main__':
    print(f"[INFO] Start listener...")
    
    try:
        server = SingleShotServer(('localhost', PORT), SingleShotHandler)
        server.serve_until_stopped()
        server.server_close()
    except KeyboardInterrupt:
        print("\n[INFO] Stopping listener.")