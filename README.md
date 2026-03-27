# ReCubed

TwoCubed created two years later, hopefully with better code.

# Installation

## Binaries

No binaries available yet.

## From Source

### Dependencies
- CMake ≥ 3.16
- C++17 compiler
- SFML 2.6

### Debian/Ubuntu (.deb)

```bash
sudo apt update
sudo apt install build-essential cmake libsfml-dev
```

### Fedora/RHEL (.rpm)

```bash
sudo dnf install cmake gcc-c++ SFML-devel
```

### Arch Linux

```bash
sudo pacman -S cmake sfml
```

### openSUSE

```bash
sudo zypper install cmake gcc-c++ sfml2-devel
```

### macOS (Homebrew)

```bash
brew install cmake sfml
```

### Windows
- Install CMake from https://cmake.org/download/
- Install Visual Studio with C++ workload from https://visualstudio.microsoft.com
- Install SFML from https://www.sfml-dev.org/download/sfml/2.6.2/

## Debug Build

In your desired directory, run:

```bash
git clone https://github.com/hpesoj5/ReCubed.git
cd ReCubed
cmake -B build/debug -DCMAKE_BUILD_TYPE=Debug
cmake --build build/debug
```

The executable will be found in `build/debug/ReCubed`.

## Release Build

In your desired directory, run:

```bash
git clone https://github.com/hpesoj5/ReCubed.git
cd ReCubed
cmake -B build/release -DCMAKE_BUILD_TYPE=Release
cmake --build build/release
```

The executable will be found in `build/release/ReCubed`.
