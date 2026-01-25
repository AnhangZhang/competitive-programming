import sys
import os
import re
from pathlib import Path


PROJECT_ROOT = '~/dev/programming'

INCLUDE_PATHS = [
    Path.cwd(),                                     # 当前目录
    Path(PROJECT_ROOT).expanduser() / 'library',    # 项目下的 library
]

visited = set()

def resolve_include(header):
    for path in INCLUDE_PATHS:
        full_path = path / header
        if full_path.is_file():
            return full_path.resolve()
    return None

def expand_file(path):
    path = Path(path).resolve()
    if path in visited:
        return
    visited.add(path)

    display_name = path.name

    print(f'// BEGIN: {display_name}')
    print(f'#line 1 "{display_name}"')

    try:
        with open(path, 'r', encoding='utf-8') as f:
            for i, line in enumerate(f, start=1):
                line_content = line.strip()
                if line_content == "#pragma once":
                    continue

                m = re.match(r'#\s*include\s*"([^"]+)"', line)
                if m:
                    header = m.group(1)
                    resolved = resolve_include(header)
                    if resolved:
                        if resolved not in visited:
                            expand_file(resolved)
                        print(f'#line {i + 1} "{display_name}"')
                    else:
                        print(f'// [warning] include not found: {header}')
                elif re.match(r'#\s*include\s*<[^>]+>', line):
                    print(line, end='')
                else:
                    print(line, end='')
    except Exception as e:
        sys.stderr.write(f"// [error] Failed to read {path}: {e}\n")

    print(f'// END: {display_name}')

if __name__ == '__main__':
    if len(sys.argv) != 2:
        sys.stderr.write("Usage: python3 expander.py source.cpp > combined.cpp\n")
        sys.exit(1)

    source_arg = sys.argv[1]
    source_path = Path(source_arg).resolve()

    if not source_path.exists():
        sys.stderr.write(f"Error: File not found: {source_path}\n")
        sys.exit(1)

    expand_file(source_path)