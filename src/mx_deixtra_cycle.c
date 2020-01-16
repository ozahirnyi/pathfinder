#include "pathfinder.h"

static int **default_deixtra_matrix(int *islands_value, int size) {
    int **default_matrix = (int **)malloc(sizeof(int *) * 3);
    int i = 0;

    for (int j = 0; j < 3; j++) {
        default_matrix[j] = (int *)malloc(sizeof(int) * size + 1);
        for (i = 0; i < size; i++) {
            if (j == 0)
                default_matrix[j][i] = islands_value[i];
            else if (j == 1)
                default_matrix[j][i] = -1;
            else
                default_matrix[j][i] = 0;
        }
    }
    default_matrix[0][i] = -2;
    default_matrix[1][i] = -1;
    default_matrix[2][i] = 1;
    return default_matrix;
}

void mx_deixtra_cycle(int **matrix, int size, mini_list **list) {
    for (int current = 0; current < size - 1; current++) {
        int **deixtra_matrix = default_deixtra_matrix(matrix[current], size);
        deixtra_matrix[2][current] = 1;
        mx_deixtra(deixtra_matrix, matrix, size, list);
    }
}
