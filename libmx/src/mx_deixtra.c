#include "../inc/libmx.h"

static void algorithm(int **deixtra_matrix, int **matrix, int size, int min) {
    for (int i = 0; i < size; i++) {
        if (matrix[min][i] != -1 && ((deixtra_matrix[2][i] != 1
            && deixtra_matrix[0][min] + matrix[min][i] < deixtra_matrix[0][i])
            || (deixtra_matrix[0][i] == -1 && deixtra_matrix[2][i] != 1))) {
            deixtra_matrix[0][i] = deixtra_matrix[0][min] + matrix[min][i];
            deixtra_matrix[1][i] = min;
        }
    }
}

int **mx_deixtra(int **deixtra_matrix, int **matrix, int size, int current) {
    deixtra_matrix[2][current] = 1;
    while (!mx_is_done(deixtra_matrix[2], size)) {
        int min = mx_is_min(deixtra_matrix, size);
        if (min != -1) {
            deixtra_matrix[2][min] = 1;
            printf("MIN ========= %d\n", min);
            algorithm(deixtra_matrix, matrix, size, min);
        }
    }
    return deixtra_matrix;
}