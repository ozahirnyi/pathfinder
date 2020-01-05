#include "../inc/libmx.h"

static int **copy_matrix(int **deixtra_matrix) {
    int size = 0;
    int **copy = NULL;

    for (;deixtra_matrix[0][size] != -2; size++);
    copy = (int **)malloc(sizeof(int *) * 3);
    for (int j = 0; j < 3; j++) {
        copy[j] = (int *)malloc(sizeof(int) * size + 1);
        for (int i = 0; i < size; i++)
            copy[j][i] = deixtra_matrix[j][i];
    }
    copy[0][size] = -2;
    copy[1][size] = -1;
    copy[2][size] = 1;
    return copy;
}

static void recursion(int **deixtra_matrix, int **matrix, int min, mini_list **list) {
    int size = 0;
    int **copy = NULL;

    for (size = 0; deixtra_matrix[0][size] != -2; size++);
    for (int i = 0; deixtra_matrix[0][i] != -2; i++) {
        if (matrix[min][i] != -1 && ((deixtra_matrix[2][i] != 1
            && deixtra_matrix[0][min] + matrix[min][i] == deixtra_matrix[0][i])
            || (deixtra_matrix[0][i] == -1 && deixtra_matrix[2][i] != 1))
            && deixtra_matrix[1][i] != min) {
            copy = copy_matrix(deixtra_matrix);
            copy[1][i] = min;
            mx_deixtra(copy, matrix, size, list);
        }
    }
}

static void algorithm(int **deixtra_matrix, int **matrix, int min, mini_list **list) {
    int size = 0;

    for (size = 0; deixtra_matrix[0][size] != -2; size++);
    for (int i = 0; deixtra_matrix[0][i] != -2; i++) {
        if (matrix[min][i] != -1 && ((deixtra_matrix[2][i] != 1
            && deixtra_matrix[0][min] + matrix[min][i] < deixtra_matrix[0][i])
            || (deixtra_matrix[0][i] == -1 && deixtra_matrix[2][i] != 1))) {
            deixtra_matrix[0][i] = deixtra_matrix[0][min] + matrix[min][i];
            deixtra_matrix[1][i] = min;
        }
    }
}

void    mx_deixtra(int **deixtra_matrix, int **matrix, int size, mini_list **list) {
    while (!mx_is_done(deixtra_matrix[2], size)) {
        int min = mx_is_min(deixtra_matrix, size);
        if (min != -1) {
            deixtra_matrix[2][min] = 1;
            algorithm(deixtra_matrix, matrix, min, list);
            recursion(deixtra_matrix, matrix, min, list);
        }
    }
    mx_push_back_filter(list, deixtra_matrix[0], deixtra_matrix[1], size);
    mx_del_intarr(&deixtra_matrix, size);
    free(deixtra_matrix[2]);
}