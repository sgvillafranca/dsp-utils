# dsp
A C++ Digital Signal Processing toolset

## Building
In order to build the library, execute the following commands:

Create a new directory to locate the build
```bash
mkdir build && cd build
```
Configure build
```bash
cmake ..
```
Perform build
```bash
cmake --build .
```
Run main
```bash
./src/main
```

## Testing
In order to build and run the unit tests for this library, execute the following commands:

Create a new directory to locate the build
```bash
mkdir build && cd build
```
Configure build
```bash
cmake ..
```
Build unit tests
```bash
cmake --build . --target tests_library 
```
```bash
cmake --build . --target tests_utils
```
Run unit tests
```bash
./test/library/library_tests 
```
```bash
./test/library/utils_tests
```