#include "../inc/libmx.h"

static int **default_deixtra_matrix(int *islands_value, int size, int current) {
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

static int is_min(int **path_price, int size) {
    int min = 2147483647;
    int i;
    int j = 0;

    for (i = 0; i < size; i++) {
        if (min > path_price[0][i] && path_price[0][i] != -1 && path_price[2][i] != 1)
            min = path_price[0][i];
    }
    if (min == 2147483647)
        return -1;
    while (path_price[0][j] != min)
        j++;
    return j;
}

static int is_done(int *path_price, int size) {
    for (int i = 0; i < size; i++) {
        if (path_price[i] == 0)
            return 0;
    }
    return 1;
}

static void deixta_matrix_filling(int **deixtra_matrix, int **matrix, int size, int min) {
    for (int i = 0; i < size; i++) {
        if (matrix[min][i] != -1 && ((deixtra_matrix[2][i] != 1
            && deixtra_matrix[0][i] + matrix[min][i] < deixtra_matrix[0][i])
            || (deixtra_matrix[0][i] == -1 && deixtra_matrix[2][i] != 1))) {
            deixtra_matrix[0][i] = deixtra_matrix[0][min] + matrix[min][i];
            deixtra_matrix[1][i] = min;
            deixtra_matrix[2][i] = 1;
        }
    }
}

static int **mini_matrix_creator(int **matrix, int size) {
    int min;
    int current = 3;
    int **deixtra_matrix = default_deixtra_matrix(matrix[current], size, current);

    deixtra_matrix[2][current] = 1;
    while (!is_done(deixtra_matrix[2], size)) {
        min = is_min(deixtra_matrix, size);
        if (min != -1) {
            deixtra_matrix[2][min] = 1;
            printf("MIN ========= %d\n", min);
            deixta_matrix_filling(deixtra_matrix, matrix, size, min);
        }
    }
//    printf("\n");
//        printf("DEIXTRA MATRIX -===>\n");
//    for (int i = 0; i < 3; i++) {
//        for (int j = 0; j < size; j++)
//            printf("%d   |   ", deixtra_matrix[i][j]);
//        printf("\n");
//    }
//    printf("\n");
//        printf("DEFAULT MATRIX -===>\n");
//    for (int i = 0; i < size; i++) {
//        for (int j = 0; j < size; j++)
//            printf("%d   |   ", matrix[i][j]);
//        printf("\n");
//    }
    return deixtra_matrix;
}

mini_list   *mx_deixtra(int **matrix, int size) {
    mini_list *list = NULL;
    int **mini_matrix = mini_matrix_creator(matrix, size);
    mx_push_back_custom(&list, mini_matrix[0], mini_matrix[1]);
    for (int i = 0; i < size; i++) {
        printf("%d  |  ", list->value[i]);
    }
    printf("\n");
    for (int i = 0; i < size; i++) {
        printf("%d  |  ", list->path[i]);
    }
    printf("\n");
    mx_del_intarr(&mini_matrix, size);
//    for (int i = 0; i < 3; i++) {
//        for (int j = 0; j < size; j++)
//            printf("%d   |   ", mini_matrix[i][j]);
//        printf("\n");
//    }
    //printf("\n");
    return list;
}