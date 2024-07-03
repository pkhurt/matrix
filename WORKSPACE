# This file could stay empty
# It tells bazel that this is the main directory of the project
workspace(name = "matrix_project")

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

# Fetch GoogleTest
http_archive(
    name = "gtest",
    urls = ["https://github.com/google/googletest/archive/release-1.11.0.tar.gz"],
    strip_prefix = "googletest-release-1.11.0",
)

# This allows us to use the gtest_main target in our BUILD files
bind(
    name = "gtest_main",
    actual = "@gtest//:main",
)
