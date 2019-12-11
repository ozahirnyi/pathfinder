#include "../inc/libmx.h"

static int **default_deixtra_matrix(int *islands_value, int size, int current) {
    int **default_matrix = (int **)malloc(sizeof(int *) * 3);

    for (int j = 0; j < 3; j++) {
        default_matrix[j] = (int *)malloc(sizeof(int) * size);
        for (int i = 0; i < size; i++) {
            if (j == 0)
                default_matrix[j][i] = islands_value[i];
            else if (j == 1)
                default_matrix[j][i] = current;
            else
                default_matrix[j][i] = 0;
        }
    }
    return default_matrix;
}

static int is_min(int *path_price, int size) {
    int min = 2147483647;
    int i;
    int j = 0;

    for (i = 0; i < size; i++) {
        if (min > path_price[i] && path_price[i] != -1)
            min = path_price[i];
    }
    while (path_price[j] != min)
        j++;
    return j;
}
/*
static int is_done(int *path_price, int size) {
    for (int i = 0; i < size; i++) {
        if (path_price[i] == 0)
            return 0;
    }
    return 1;
}
*/
int **mx_deixtra(int **matrix) {
    int min;
    int current = 1;
    int **deixtra_matrix = default_deixtra_matrix(matrix[0], 4, current);

    //while (!is_done(deixtra_matrix[2], 4)) {
        for (int i = 0; i < 4; i++) {
            min = is_min(deixtra_matrix[0], 4);
            printf("MIN ========= %d\n", min);
            if (i == min) {
                current = deixtra_matrix[1][i];
                if (deixtra_matrix[0][i] > matrix[i][i + current] + deixtra_matrix[0][min]) {
                    deixtra_matrix[0][i] = matrix[i][i + current] + deixtra_matrix[0][min];
                    deixtra_matrix[1][i] = current;
                    deixtra_matrix[2][i] = 1;
                }
            }
        }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++)
            printf("%d   |   ", deixtra_matrix[i][j]);
        printf("\n");
    }
    return deixtra_matrix;
}
