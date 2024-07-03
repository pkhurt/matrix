# What is this
This is a matrix project to test out different programming styles and build systems

## Setup with cmake
First of all you need to have cmake on the system.

The `CMakeLists.txt` defines the link of the header file and the executables to each other.

To build the project:
```
cd matrix
mkdir build
cd build
cmake ..
make
```

To run the `main.cpp`: 
```
./matrix
```

To run the tests:
```
ctest
```

## Setup with Bazel
Execute these commands in the workspace root (where the WORKSPACE file is located).
```
bazel build //matrix:main
```

To execute the `main.cpp` program type
```
bazel run //matrix:main
```

Executing the tests (using gtest)
```
bazel test //matrix:matrix_test
```

### The bazel files
The executable of the bazel files can be found in `bazel-bin/matrix/main` 