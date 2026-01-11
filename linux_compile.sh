# Compile for Linux. This is for WSL,
# Since CLion and other IDEs generally help you with compiling.

mkdir "linux-build"
cmake -S . -B linux-build
cmake --build linux-build  --config Release