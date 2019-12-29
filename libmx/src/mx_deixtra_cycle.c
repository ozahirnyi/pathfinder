#include "../inc/libmx.h"

static int **default_deixtra_matrix(int *islands_value, int size) {
    int **default_matrix = (int **)malloc(sizeof(int *) * 3);

    for (int j = 0; j < 3; j++) {
        default_matrix[j] = (int *)malloc(sizeof(int) * size);
        for (int i = 0; i < size; i++) {
            if (j == 0)
                default_matrix[j][i] = islands_value[i];
            else if (j == 1)
                default_matrix[j][i] = -1;
            else
                default_matrix[j][i] = 0;
        }
    }
    return default_matrix;
}

void    mx_deixtra_cycle(int **matrix, int size, mini_list *list) {
    for (int current = 0; current < size; current++) {
        int **deixtra_matrix = default_deixtra_matrix(matrix[current], size);
        int **mini_matrix = mx_deixtra(deixtra_matrix, matrix, size, current);
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < size; j++)
                printf("%d  |  ", mini_matrix[i][j]);
            printf("\n");
        }
        mx_push_back_custom(&list, mini_matrix[0], mini_matrix[1], size);
        mx_del_intarr(&mini_matrix, size);
        free(mini_matrix[2]);
    }
}
