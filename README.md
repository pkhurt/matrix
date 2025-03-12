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
| **Type**                    | Build system                                                                                          | Build and test system                                                                         |
| **Language Support**        | Primarily C/C++, but supports others through additional modules                                                 | Multi-language (Java, C++, Python, Go, etc.)                                                  |
| **Philosophy**              | Generates native build files (like Makefiles, Ninja build files, or Visual Studio project files)                | Emphasizes hermetic builds, reproducibility, and scalability, leveraging sandboxing and caching |
| **Configuration Language**  | CMakeLists.txt files using CMake scripting language                                                             | Starlark (a Python-like language) in BUILD and WORKSPACE files                                |         |
| **Community and Ecosystem** | Wide adoption in the C/C++ community, extensive support for various compilers and platforms                     | Since it's a rather new build system it's not widely used. Documentation is great, community grows.      |
| **Cross-Platform**          | Generates build files for different platforms (Windows, Linux, macOS)                                           | Supports builds across multiple platforms and environments                                    |
| **Modularity**              | Supports custom modules and user-defined functions                                                              | Supports custom modules and user-defined functions                                |
| **Flexibility**             | CMake language allows to include internal as well as external resources easily                              | Starlark allows to include internal and external resources. Efficiently rebuilds only what's necessary, leveraging robust caching. However, bazel build needs an internet connection.                          |
| **Legacy Projects**         | Good for projects with a long history or needing to integrate with various other build systems and tools        | Not typically used for legacy projects but for new, large-scale projects                      |
| **Hermetic Builds**         | No specific focus on hermetic builds                                                                             | Ensures builds are isolated from the host environment to guarantee reproducibility by downloading sources of libs and tools           |
|| **Remote Build Execution**  | Not a core feature, relies on underlying build system                                                           | Supports distributed builds to leverage remote compute resources                              |
| **Extensibility**           | Custom modules and user-defined functions                                                                       | Custom rules and user-defined functions (macros)                                                                       |
| **Use Case**                | C/C++ projects, legacy codebases, IDE integration, custom toolchains                                            | Large-scale projects, reproducibility, multi-language ecosystems, Google Cloud integration    |

# Further informatoin to bazel
Bazel general build command
```
bazel build //main:hello-world
```
* //main is the location directory where a bazel BUILD file is located. It's relative to the root of the workspace. Also, this is called the package name
* hello-world in this case is the target name in the BUILD file

**Execute the build binary without bazel:** `bazel-bin/main/hello-world`

## Bazel Build dependency graph
With this command one can print and dump the bazel build dependency graph
```bash
bazel query 'deps(//main:hello-world)' --otuput graph > graph.in
dot -Tpng < graph.in > graph.png
eog graph.png
```
To show the graph without implicit libs (external dependencies):
```bash
bazel query --noimplicit_deps 'deps(//main:hello-world)' --output_graph > graph.in
```

## The build file
The build file is using starlark language: https://bazel.build/rules/language/

Bazel for python: https://bazel.build/reference/be/python/

### Keyword visibility in a BUILD file
The keyword visibility in a BUILD file in bazel makes a traget explicitly visible for the package. 
This is because by default targets are only visible to other targets in the same BUILD file. Bazel uses target visibility to prevent issues such as libraries containing implementation details leaking into public APIs.


<hr>

<div style="text-align: center;">
<img src="./docu/logo.PNG" alt="logo image" style="width:30%;height:30%;">
</div>