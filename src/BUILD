cc_library(
    name = "matrix_lib",
    srcs = ["Matrix.cpp"],
    hdrs = ["../include/Matrix.h"],
    visibility = ["//visibility:public"],
)

cc_binary(
    name = "matrix_main",
    srcs = ["Main.cpp"],
    deps = [":matrix_lib"],
)
