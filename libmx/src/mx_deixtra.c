#include "../inc/libmx.h"

static int **default_deixtra_matrix(int *islands_value, int size) {
    int **default_matrix = (int **)malloc(sizeof(int **) * 3);

    for (int j = 0; j < 3; j++) {
        default_matrix[j] = (int *)malloc(sizeof(int *) * size);
        for (int i = 0; i < size; i++) {
            if (j == 0)
                default_matrix[j][i] = islands_value[i];
            else if (j == 1 && islands_value[i] == -1)
                default_matrix[j][i] = -1;
            else if (j == 2)
                default_matrix[j][i] = 0;
            else
                default_matrix[1][i] = 0;
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
    int **deixtra_matrix = default_deixtra_matrix(matrix[0], 4);
    system("leaks -q pathfinder");
    int min = -1;

    //while (!is_done(deixtra_matrix[2], 4)) {
        for (int i = 0; i < 4; i++) {
            min = is_min(deixtra_matrix[1], 4);
            printf("MIN ========= %d\n", min);
            if (deixtra_matrix[2][min] == 0) {
                deixtra_matrix[1][min] = min - 1;

            }
        }

    //}
    //printf("MIN ======= %d\n", is_min(deixtra_matrix[0], 4));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++)
            printf("%d   |    ", deixtra_matrix[i][j]);
        printf("\n");
    }
    return 0;
}
