mkdir "windows-build"
cmake -S . -B windows-build
cmake --build windows-build --config Release