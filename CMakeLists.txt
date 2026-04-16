cmake_minimum_required(VERSION 3.16)
project(backends)

add_subdirectory(backends/llama.cpp)
add_subdirectory(backends/stable-diffusion.cpp)
add_subdirectory(backends/llama.cpp_custom)
add_subdirectory(backends/stable-diffusion.cpp_custom)

add_library(backends
    backends/llama.cpp
    backends/stable-diffusion.cpp
    backends/llama.cpp_custom
    backends/stable-diffusion.cpp_custom
)

target_link_libraries(backends
    backends/llama.cpp
    backends/stable-diffusion.cpp
    backends/llama.cpp_custom   
    backends/stable-diffusion.cpp_custom
)
