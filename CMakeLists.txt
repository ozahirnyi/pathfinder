cmake_minimum_required(VERSION 3.12)
project(pathfinder C)

set(CMAKE_C_STANDARD 11)

aux_source_directory(src LIB_SRC)
add_library(mx STATIC ${LIB_SRC})

#include_directories(inc)

add_executable(pathfinder src/main.c inc/pathfinder.h )
target_link_libraries(pathfinder src/mx)