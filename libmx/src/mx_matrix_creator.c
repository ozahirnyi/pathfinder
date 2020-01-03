#include "../inc/libmx.h"
/*
 *              LISHNYAAA PEREMENNAYA
                        ||
                        ||
                        ||
                        ||
                        ||
                        \/
*/
static int **matrix_filling(char **islands, int **matrix, t_list *list) {
    char **temp_minus;
    char **temp_koma;
    int itoe;
    int jitoe;
    int value;

    for (int i = 1; islands[i]; i++) {
        temp_minus = mx_strsplit(islands[i], '-');
        itoe = mx_island_index(&list, temp_minus[0]);
        temp_koma = mx_strsplit(temp_minus[1], ',');
        jitoe = mx_island_index(&list, temp_koma[0]);
        value = mx_atoi(temp_koma[1]);

        matrix[itoe][jitoe] = value;
        matrix[jitoe][itoe] = value;
        mx_del_strarr(&temp_minus);
        mx_del_strarr(&temp_koma);
    }
    return matrix;
}

int **mx_matrix_creator(char **islands, t_list *list) {
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
    return matrix;
}
