# Include directories
package(default_visibility = ["//visibility:public"])

cc_library(
    name = "matrix_lib",
    srcs = ["src/matrix.cpp"],
    hdrs = ["include/matrix.h"],
    copts = ["-Imatrix/include/"]
    visibility = ["//visibility:public"],
)

cc_binary(
    name = "matrix",
    srcs = ["src/main.cpp"],
    deps = [":matrix_lib"],
)

cc_test(
    name = "matrix_test",
    srcs = ["test/test.cpp"],
    deps = [
        ":matrix_lib",
        "@gtest//:gtest_main",
    ],
)
