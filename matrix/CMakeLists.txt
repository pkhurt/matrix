cmake_minimum_required(VERSION 3.10)

project(Matrix)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories
include_directories(include)

# Create a library from the Matrix source files
add_library(MatrixLib src/matrix.cpp)

# Add the executable for the main program and link the library
add_executable(Matrix src/main.cpp)
target_link_libraries(Matrix MatrixLib)

# Include FetchContent module
include(FetchContent)

# Download and configure GoogleTest
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.11.0
)

# Fetch the content and make it available
FetchContent_MakeAvailable(googletest)

# Link GoogleTest with the test executable
add_executable(MatrixTest test/test.cpp)
target_link_libraries(MatrixTest MatrixLib gtest_main)

# Enable testing
enable_testing()

# Add a test
add_test(NAME MatrixTest COMMAND MatrixTest)
