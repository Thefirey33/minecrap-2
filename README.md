# Minecrap 2

This is an ongoing game project. It uses CMake to compile. This game is supposed to parody the current terrible minecraft parodies out there.

## Requirements

To build this game, you must have:

- CMake (Minimum 3.28.3)
- C++ (Version 20)


## Building

### Linux

#### Raylib

These are the dependencies you need for Raylib.
##### Ubuntu:
```
sudo apt install libasound2-dev libx11-dev libxrandr-dev libxi-dev libgl1-mesa-dev libglu1-mesa-dev libxcursor-dev libxinerama-dev libwayland-dev libxkbcommon-dev
```

##### Fedora:
```
sudo dnf install alsa-lib-devel mesa-libGL-devel libX11-devel libXrandr-devel libXi-devel libXcursor-devel libXinerama-devel libatomic
```

##### Arch Linux:
```
sudo pacman -S alsa-lib mesa libx11 libxrandr libxi libxcursor libxinerama
```

These are dependencies that you ***NEED*** to run this program.

*After you install the required dependencies,*

To build it on Windows, use `windows_compile.bat`

To build it on Linux, use `linux_compile.bat`

These files will automatically handle the process of building the game.


***Beware: This README is still heavy under construction. Don't rely on it.***