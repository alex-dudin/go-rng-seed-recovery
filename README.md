# Seed recovery library for Go PRNG

## How to build library and examples using Visual Studio 2019

1) Install the prerequisites
   - CMake 3.17+ (https://cmake.org/)
   - vcpkg (https://github.com/Microsoft/vcpkg/)

2) Generate Visual Studio solution
   ```bat
   cmake -G "Visual Studio 16 2019" -Thost=x64 -Ax64 -B build -S . -DCMAKE_TOOLCHAIN_FILE=%VCPKG_DIR%\scripts\buildsystems\vcpkg.cmake
   ```
 
3) Build Visual Studio solution
   ```bat
   cmake --build build --config Debug
   ```
   or
   ```bat
   cmake --build build --config Release
   ```

## How to build and run examples in a Docker container

1) Build image
   ```bat
   docker build -t go-rng-seed-recovery .
   ```

2) Create and run container
   ```bat
   docker run -it --rm go-rng-seed-recovery
   ```
