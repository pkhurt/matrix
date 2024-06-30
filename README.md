# What is this
This is a matrix project to test out different programming styles and build systems

## Setup with cmake
First of all you need to have cmake on the system.

The `CMakeLists.txt` defines the link of the header file and the executables to each other.

To build the project:
```
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