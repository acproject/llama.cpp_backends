cmake_minimum_required(VERSION 3.16)
project(backends)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# include
include_directories(include)


add_subdirectory(backends/llama.cpp)
add_subdirectory(backends/stable-diffusion.cpp)
add_subdirectory(backends/llama.cpp_custom)
add_subdirectory(backends/stable-diffusion.cpp_custom)

# runtime core
add_library(runtime_core 
    runtime/dsipatcher/runner.cpp
    runtime/registry/backend_registry.cpp
)

# dummy backend
add_library(dummy_backends
    backends/dummy_backend/dummy_backend.cpp    
    # backends/stable-diffusion.cpp
    # backends/llama.cpp_custom
    # backends/stable-diffusion.cpp_custom
)

#CLI
add_executable(runtime_cli 
    apps/cli/main.cpp
)

target_link_libraries(runtime_cli
    runtime_core
    dummy_backends
)
