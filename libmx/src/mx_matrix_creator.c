#include "../inc/libmx.h"

static int island_index(t_list **list, char *str) {
    int count = 0;
    t_list *buf = *list;

    while (buf != NULL) {
        if (mx_strcmp(buf->data, str) == 0)
            return count;
        count++;
        buf = buf->next;
    }
    return -1;
}

static int check_duplicates(t_list **list, char *str) {
    t_list *buf = *list;

    while (buf != NULL) {
        if (mx_strcmp(buf->data, str) == 0)
            return 1;
        buf = buf->next;
    }
    return 0;
}

static t_list *islands_list(char **islands) {
    t_list *new_list = NULL;
    char *temp = NULL;
    char **temp_minus = NULL;
    char **temp_koma = NULL;

    for (int i = 1; islands[i] != NULL; i++) {
        temp_minus = mx_strsplit(islands[i], '-');
            if (!check_duplicates(&new_list, temp_minus[0])) {
                temp = mx_strdup(temp_minus[0]);
                mx_push_back(&new_list, temp);
            }
        temp_koma = mx_strsplit(temp_minus[1], ',');
            if (!check_duplicates(&new_list, temp_koma[0])) {
                temp = mx_strdup(temp_koma[0]);
                mx_push_back(&new_list, temp);
            }
        mx_del_strarr(&temp_minus);
        mx_del_strarr(&temp_koma);
    }
    return new_list;
}

static int **matrix_filling(char **islands, int **matrix, t_list *list) {
    char **temp_minus;
    char **temp_koma;
    int itoe;
    int jitoe;
    int value;

    for (int i = 1; islands[i]; i++) {
        temp_minus = mx_strsplit(islands[i], '-');
        itoe = island_index(&list, temp_minus[0]);
        temp_koma = mx_strsplit(temp_minus[1], ',');
        jitoe = island_index(&list, temp_koma[0]);
        value = mx_atoi(temp_koma[1]);

        matrix[itoe][jitoe] = value;
        matrix[jitoe][itoe] = value;
        mx_del_strarr(&temp_minus);
        mx_del_strarr(&temp_koma);
    }
    return matrix;
}
int **mx_matrix_creator(char **islands) {
    t_list *list = islands_list(islands);
    int size = mx_atoi(islands[0]);
    int **matrix = (int **)malloc(size * (sizeof(int **)));
    int i = 0;
    int j = 0;

    for (i = 0; i < size; i++) {
        matrix[i] = (int *)malloc(size * (sizeof(int *)));
        for (j = 0; j < size; j++)
            matrix[i][j] = -1;
    }
    matrix = matrix_filling(islands, matrix, list);
    return matrix;
}
