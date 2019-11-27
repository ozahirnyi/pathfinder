#include "../inc/libmx.h"

int **mx_matrix_creator(const char *file) {
    int size = mx_atoi(mx_file_to_str(file));
    system("leaks -q pathfinder");
    int **matrix = (int **)malloc(size * (sizeof(int **)));
    int i = 0;
    int j = 0;

    for (i = 0; i < size; i++) {
        matrix[i] = (int *)malloc(size * (sizeof(int *)));
        for (j = 0; j < size; j++) {
            matrix[i][j] = 1;
        }
    }
    return matrix;
}
