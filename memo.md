# zshrc or bashrc

- how to change g++-15 to g++

```
mkdir -p ~/bin
ln -s $(which g++-15) ~/bin/g++
export PATH="$HOME/bin:$PATH"
```

- competitive programming setup

```
# competitive programming setup
export CP_HOME="$HOME/dev/programming"
export CP_UTILS="$CP_HOME/utils"
export CP_LIB="$CP_HOME/library"
ulimit -s unlimited
function gen() {
    python "$CP_UTILS/listener.py"

    if [ $? -eq 0 ]; then
        if [ -f "main.cpp" ]; then
            mv main.cpp main.cpp.bak
            # echo "[INFO] Backed up main.cpp to main.cpp.bak"
        fi

        if [ -f "$CP_LIB/main.hpp" ]; then
            cp "$CP_LIB/main.hpp" main.cpp
        else
            echo "[ERROR] main.hpp template missing"
        fi
    else 
        echo "[ERROR] Listener was interrupted. main.cpp not generated."
    fi
}
function run() {
    python "$CP_UTILS/test.py"
    python "$CP_UTILS/expander.py" main.cpp > combined.cpp

    if [ ! -f "combined.cpp" ]; then
        echo "[Error] combined.cpp generation failed."
        return 1
    fi

    local file_path=""
    
    if [[ "$OSTYPE" == "darwin"* ]]; then
        # [MacOS]
        file_path="$HOME/dev/programming/combined.cpp"
        echo -n "$file_path" | pbcopy
        
    elif grep -q Microsoft /proc/version; then
        file_path=$(wslpath -w "$HOME/dev/programming/combined.cpp")
        echo -n "$file_path" | clip.exe
    fi
}
```