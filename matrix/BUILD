cc_library(
    name = "matrix_lib",
    hdrs = ["include/matrix.h"],
    srcs = ["src/matrix.cpp"],
    includes = ["include"],
    visibility = ["//visibility:public"],
)

cc_binary(
    name = "main",
    srcs = ["src/main.cpp"],
    deps = [":matrix_lib"],
)

cc_test(
    name = "matrix_test",
    srcs = ["test/test.cpp"],
    deps = [
        "@gtest//:gtest_main",
        ":matrix_lib"
    ]
)