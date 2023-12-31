# message("[Entry] -> src")
# message("Link Libraries ${LINKER_LIBRARY} -> ${PROJECT_NAME}")
# SDL2MAIN_LIBRARY is needed for Windows specific main function.

add_executable(${PROJECT_NAME} main.cpp)

add_subdirectory(utils)
target_link_libraries(${PROJECT_NAME} PRIVATE utils_module)
target_link_libraries(utils_module PRIVATE TinyXML2)

add_subdirectory(engine)
target_link_libraries(${PROJECT_NAME} PRIVATE engine_module)
target_link_libraries(engine_module PRIVATE utils_module SDL2)

add_subdirectory(scripts)
target_link_libraries(${PROJECT_NAME} PRIVATE scripts_module)
target_link_libraries(scripts_module PRIVATE utils_module engine_module)

# Specify include directories for the main executable
target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/engine
    ${CMAKE_CURRENT_SOURCE_DIR}/utils
    ${CMAKE_CURRENT_SOURCE_DIR}/ui
    ${CMAKE_CURRENT_SOURCE_DIR}/scripts
)
