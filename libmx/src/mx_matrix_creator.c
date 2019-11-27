#include "../inc/libmx.h"

//static char **splitter(char *str) {

//}

static char  **islands(char *str) {
    char **splitter_n = mx_strsplit(str, '\n');
    char **splitter_
}

int **mx_matrix_creator(char *str) {
    int size = mx_atoi(str);
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
