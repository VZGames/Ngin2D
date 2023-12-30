file(GLOB_RECURSE SOURCE_FILES "*.cpp" "*.h")

# Define the library in engine
add_library(engine_module ${SOURCE_FILES})

# Include directories, if needed
target_include_directories(engine_module PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/Base
    ${CMAKE_CURRENT_SOURCE_DIR}/Common
    ${CMAKE_CURRENT_SOURCE_DIR}/Control
    ${CMAKE_CURRENT_SOURCE_DIR}/Math
    ${CMAKE_CURRENT_SOURCE_DIR}/Scene
    ${CMAKE_CURRENT_SOURCE_DIR}/Tilemap
    ${CMAKE_CURRENT_SOURCE_DIR}/System
    ${CMAKE_CURRENT_SOURCE_DIR}/Physics
    ${CMAKE_CURRENT_SOURCE_DIR}/Graphics
    ${CMAKE_CURRENT_SOURCE_DIR}/ECS
    ${CMAKE_CURRENT_SOURCE_DIR}/ECS/Component
    ${CMAKE_CURRENT_SOURCE_DIR}/ECS/Entity
    ${CMAKE_CURRENT_SOURCE_DIR}/ECS/Systems
    ${CMAKE_CURRENT_SOURCE_DIR}/World
)
