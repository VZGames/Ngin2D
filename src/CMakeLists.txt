message("[Entry] -> src")
message("Link Libraries ${LINKER_LIBRARY} -> ${PROJECT_NAME}")
# SDL2MAIN_LIBRARY is needed for Windows specific main function.

add_subdirectory(engine)
add_subdirectory(utils)
add_subdirectory(scripts)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} ${LINKER_LIBRARY})