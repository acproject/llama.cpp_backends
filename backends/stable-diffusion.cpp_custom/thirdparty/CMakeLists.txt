set(Z_TARGET zip.cpp_custom)
add_library(${Z_TARGET}_cpp_custom OBJECT zip.c zip.h miniz.h)
target_include_directories(${Z_TARGET}_cpp_custom PUBLIC .)
