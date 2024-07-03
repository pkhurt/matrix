<div style="text-align: center;">
<img src="./docu/logo.PNG" alt="logo image" style="width:30%;height:30%;">
</div>

<hr>

# What is this
This is a matrix project to test out different programming styles and build systems. Currently it compares CMake with Bazel.

# Overview
1. [CMake Build and Run](#setup-with-cmake) 
2. [Bazel Build and Run](#setup-with-cmake)
3. [Comparison Bazel and CMake](#comparison-of-the-two-build-systems)

# Setup
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


# Comparison of the two build systems

| Feature/Aspect              | CMake                                                                                                           | Bazel                                                                                         |
|-----------------------------|-----------------------------------------------------------------------------------------------------------------|-----------------------------------------------------------------------------------------------|
| **Type**                    | Build system generator                                                                                          | Build and test system                                                                         |
| **Language Support**        | Primarily C/C++, but supports others through additional modules                                                 | Multi-language (Java, C++, Python, Go, etc.)                                                  |
| **Philosophy**              | Generates native build files (like Makefiles, Ninja build files, or Visual Studio project files)                | Emphasizes hermetic builds, reproducibility, and scalability, leveraging sandboxing and caching |
| **Configuration Language**  | CMakeLists.txt files using CMake scripting language                                                             | Starlark (a Python-like language) in BUILD and WORKSPACE files                                |
| **Integration**             | Works well with existing tools and workflows, particularly in C/C++ ecosystems                                   | Designed for large-scale projects, complex dependencies, speed, and reproducibility           |
| **Community and Ecosystem** | Wide adoption in the C/C++ community, extensive support for various compilers and platforms                     | Focused on scalability and reliability, extensive support for complex project structures      |
| **Cross-Platform**          | Generates build files for different platforms (Windows, Linux, macOS)                                           | Supports builds across multiple platforms and environments                                    |
| **Modularity**              | Supports custom modules and user-defined functions                                                              | Custom rules and macros can be defined to extend functionality                                |
| **Flexibility**             | Can be customized extensively to fit a variety of project structures and workflows                              | Efficiently rebuilds only what's necessary, leveraging robust caching                          |
| **Legacy Projects**         | Good for projects with a long history or needing to integrate with various other build systems and tools        | Not typically used for legacy projects but for new, large-scale projects                      |
| **Hermetic Builds**         | No specific focus on hermetic builds                                                                             | Ensures builds are isolated from the host environment to guarantee reproducibility            |
| **Incremental Builds**      | Depends on underlying build system (like Make, Ninja)                                                           | Efficiently rebuilds only what's necessary                                                    |
| **Remote Build Execution**  | Not a core feature, relies on underlying build system                                                           | Supports distributed builds to leverage remote compute resources                              |
| **Multi-language**          | Limited, primarily focused on C/C++                                                                             | Handles diverse codebases with multiple languages and platforms                               |
| **Extensibility**           | Custom modules and user-defined functions                                                                       | Custom rules and macros                                                                       |
| **Use Case**                | C/C++ projects, legacy codebases, IDE integration, custom toolchains                                            | Large-scale projects, reproducibility, multi-language ecosystems, Google Cloud integration    |

<hr>

<div style="text-align: center;">
<img src="./docu/logo.PNG" alt="logo image" style="width:30%;height:30%;">
</div>