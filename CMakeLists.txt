set(CMAKE_VERBOSE_MAKEFILE ON)
cmake_minimum_required(VERSION 3.2.0)
project(Ngin2D VERSION 0.1.0 DESCRIPTION "Not yet!" LANGUAGES CXX)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

message("SOURCE: ${CMAKE_SOURCE_DIR}")
message("Output: ${CMAKE_BINARY_DIR}")


set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

add_subdirectory(src)

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_11)

