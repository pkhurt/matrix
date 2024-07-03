cc_library(
    name = "matrix_lib",
    srcs = ["matrix.cpp"],
    hdrs = ["../include/matrix.h"],
    includes = ["../include"]
    visibility = ["//visibility:public"],
)

cc_binary(
    name = "main",
    srcs = ["main.cpp"],
    deps = [":matrix_lib"],
)
