file(GLOB_RECURSE SOURCE_FILES "*.cpp" "*.h")

# Define the library in utils
add_library(utils_module ${SOURCE_FILES})

# Include directories, if needed
target_include_directories(utils_module PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/Logger
    ${CMAKE_CURRENT_SOURCE_DIR}/Memory
    ${CMAKE_CURRENT_SOURCE_DIR}/Process
    ${CMAKE_CURRENT_SOURCE_DIR}/Parser
)

