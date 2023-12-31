set(CMAKE_VERBOSE_MAKEFILE ON)
cmake_minimum_required(VERSION 3.28.0)

project(Bee2D VERSION 0.1.0 DESCRIPTION "Game engine from BeeStudio" LANGUAGES C CXX)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(LIBRARY_DIR "${CMAKE_SOURCE_DIR}/libs")
set(INCLUDE_DIR "${CMAKE_SOURCE_DIR}/include")
set(LINKER_LIBRARY "-lmingw32")

message("SOURCE: ${CMAKE_SOURCE_DIR}")
message("Output: ${CMAKE_BINARY_DIR}")



# copy dynamic libraries
file(COPY
    "${CMAKE_SOURCE_DIR}/bin/SDL2.dll"
    "${CMAKE_SOURCE_DIR}/bin/SDL2_image.dll"
    DESTINATION ${CMAKE_BINARY_DIR})

# copy game assets into build/assets directory
file(COPY
    "${CMAKE_SOURCE_DIR}/assets/"
    DESTINATION ${CMAKE_BINARY_DIR}/assets)

include_directories(${INCLUDE_DIR})
link_directories(${LIBRARY_DIR})

add_subdirectory(src)

target_link_libraries(${PROJECT_NAME} PRIVATE ${LINKER_LIBRARY})

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)
