# message("[Entry] -> src")
# message("Link Libraries ${LINKER_LIBRARY} -> ${PROJECT_NAME}")

add_executable(${PROJECT_NAME} main.cpp)

add_subdirectory(global)
target_link_libraries(${PROJECT_NAME} PRIVATE global_module)

add_subdirectory(utils)
target_link_libraries(${PROJECT_NAME} PRIVATE utils_module)
target_link_libraries(utils_module PRIVATE TinyXML2 global_module)

add_subdirectory(engine)
target_link_libraries(${PROJECT_NAME} PRIVATE engine_module)
target_link_libraries(engine_module PRIVATE SDL2 SDL2_image utils_module global_module)

add_subdirectory(scripts)
target_link_libraries(${PROJECT_NAME} PRIVATE scripts_module)
target_link_libraries(scripts_module PRIVATE utils_module engine_module global_module)

# Specify include directories for the main executable
target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/global
    ${CMAKE_CURRENT_SOURCE_DIR}/engine
    ${CMAKE_CURRENT_SOURCE_DIR}/utils
    ${CMAKE_CURRENT_SOURCE_DIR}/ui
    ${CMAKE_CURRENT_SOURCE_DIR}/scripts
)
