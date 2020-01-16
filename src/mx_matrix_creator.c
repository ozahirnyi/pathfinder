#include "pathfinder.h"

static int **matrix_filling(char **islands, int **matrix, t_list *list) {
    int *itoejitoe = (int *)malloc(sizeof(int) * 2);
    char **temp_minus;
    char **temp_koma;
    int value;

    for (int i = 1; islands[i]; i++) {
        temp_minus = mx_strsplit(islands[i], '-');
        itoejitoe[0] = mx_island_index(&list, temp_minus[0]);
        temp_koma = mx_strsplit(temp_minus[1], ',');
        itoejitoe[1] = mx_island_index(&list, temp_koma[0]);
        value = mx_atoi(temp_koma[1]);

        matrix[itoejitoe[0]][itoejitoe[1]] = value;
        matrix[itoejitoe[1]][itoejitoe[0]] = value;
        mx_del_strarr(&temp_minus);
        mx_del_strarr(&temp_koma);
    }
    free(itoejitoe);
    return matrix;
}

int **mx_matrix_creator(char **islands) {
    t_list *list = mx_island_list(islands);
    int size = mx_atoi(islands[0]);
    int **matrix = (int **)malloc(size * (sizeof(int *)));
    int i = 0;
    int j = 0;

    for (i = 0; i < size; i++) {
        matrix[i] = (int *)malloc(size * (sizeof(int)));
        for (j = 0; j < size; j++)
            matrix[i][j] = -1;
    }
    matrix = matrix_filling(islands, matrix, list);
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++)
            if (i == j)
                matrix[i][j] = -1;
    }
    while (list)
        mx_pop_front(&list);
    return matrix;
}
