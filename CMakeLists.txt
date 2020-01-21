cmake_minimum_required(VERSION 3.12)
project(pathfinder C)

set(CMAKE_C_STANDARD 11)

include_directories("inc")
include_directories("libmx/inc")
#include("inc/pathfinder.h")

aux_source_directory(libmx/src LIB_SRC)
add_library(mx STATIC ${LIB_SRC})

#include_directories(inc)

add_executable(pathfinder src/main.c
                src/mx_count_parallel.c
                src/mx_create_node_custom.c
                src/mx_deixtra.c
                src/mx_deixtra_cycle.c
                src/mx_is_done.c
                src/mx_is_min.c
                src/mx_island_index.c
                src/mx_island_list.c
                src/mx_matrix_creator.c
                src/mx_pop_front_mini.c
                src/mx_push_back_custom.c
                src/mx_result_matrix.c
                src/mx_sort_result.c
                src/mx_valid_for_1line.c
                src/mx_valid_for_alpha.c
                src/mx_valid_for_digits.c
                src/mx_valid_for_koma.c
                src/mx_valid_for_minus.c
                src/mx_valid_for_slashn.c
                src/mx_validator.c
                src/mx_result_list_creator.c
                src/mx_push_result.c
                src/mx_create_struct.c
                src/mx_index_search.c
                src/mx_write_result.c
                src/mx_count_distance.c)
target_link_libraries(pathfinder mx)