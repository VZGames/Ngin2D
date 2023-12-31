file(GLOB_RECURSE SOURCE_FILES "*.cpp" "*.h")

# Define the library in engine
add_library(global_module ${SOURCE_FILES})

set_target_properties(global_module PROPERTIES LINKER_LANGUAGE CXX)

# Include directories, if needed
target_include_directories(global_module PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
