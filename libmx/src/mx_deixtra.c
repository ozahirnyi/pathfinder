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

static void algorithm(int **deixtra_matrix, int **matrix, int size, int min) {
    for (int i = 0; i < size; i++) {
        if (matrix[min][i] != -1 && ((deixtra_matrix[2][i] != 1
            && deixtra_matrix[0][i] + matrix[min][i] < deixtra_matrix[0][i])
            || (deixtra_matrix[0][i] == -1 && deixtra_matrix[2][i] != 1))) {
            deixtra_matrix[0][i] = deixtra_matrix[0][min] + matrix[min][i];
            deixtra_matrix[1][i] = min;
            //deixtra_matrix[2][i] = 1;
        }
    }
}

static int **deixtra_matrix_filling(int **matrix, int size, int current) {
    int **deixtra_matrix = default_deixtra_matrix(matrix[current], size, current);

    deixtra_matrix[2][current] = 1;
    while (!mx_is_done(deixtra_matrix[2], size)) {
        int min = mx_is_min(deixtra_matrix, size);
        if (min != -1) {
            deixtra_matrix[2][min] = 1;
//            for (int j = 0; j < 3; j++) {
//                for (int i = 0; i < size; i++) {
//                    printf("%d   |   ", deixtra_matrix[j][i]);
//                }
//                printf("\n");
//            }
//            printf("\n");
            printf("MIN ========= %d\n", min);
            algorithm(deixtra_matrix, matrix, size, min);
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

mini_list   *mx_deixtra(int **matrix, int size, mini_list *list) {
    for (int current = 0; current < size; current++) {
        int **mini_matrix = deixtra_matrix_filling(matrix, size, current);
        mx_push_back_custom(&list, mini_matrix[0], mini_matrix[1], size);
        mx_del_intarr(&mini_matrix, size);
        free(mini_matrix[2]);
    }

    //free(*mini_matrix);
//    for (int i = 0; i < size; i++) {
//        printf("%d  |  ", list->value[i]);
//    }
//    printf("\n");
//    for (int i = 0; i < size; i++) {
//        printf("%d  |  ", list->path[i]);
//    }
//    printf("\n");
    //mx_del_intarr(&mini_matrix, size);

//    for (int i = 0; i < 3; i++) {
//        for (int j = 0; j < size; j++)
//            printf("%d   |   ", mini_matrix[i][j]);
//        printf("\n");
//    }
    //printf("\n");
    return list;
}