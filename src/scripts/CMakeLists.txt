file(GLOB_RECURSE SOURCE_FILES "*.cpp" "*.h")

# Define the library in engine
add_library(scripts_module ${SOURCE_FILES})

# Include directories, if needed
target_include_directories(scripts_module PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
