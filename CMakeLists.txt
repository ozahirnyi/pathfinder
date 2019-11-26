cmake_minimum_required(VERSION 3.12)
project(pathfinder C)

set(CMAKE_C_STANDARD 99)

aux_source_directory(libmx/src LIB_SRC)
add_library(mx STATIC ${LIB_SRC})

#include_directories(libmx/inc)

add_executable(pathfinder main.c)
target_link_libraries(pathfinder mx)
