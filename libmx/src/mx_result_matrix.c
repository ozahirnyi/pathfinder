#include "../inc/libmx.h"

static int check_for_dup(int **result_matrix, int value, int path, int index) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; result_matrix[i][j] != -2; j++) {
            if (value == result_matrix[0][j]
                && path == result_matrix[1][j] && result_matrix[2][j] == index)
                return 1;
            else if (value == result_matrix[0][j] && path != result_matrix[1][j]
                    && result_matrix[2][j] == index) {
                int q = j;
                while (result_matrix[2][q] == index) {
                    if (value == result_matrix[0][q] && path == result_matrix[1][q]
                        && result_matrix[2][q] == index)
                        return 1;
                    q++;
                }
                return 2;
            }
        }
    }
    return 0;
}

static void push_on_place(int **result, int value, int path, int i) {
    int j = 0;

    for (j = 0; result[0][j] != -3; j++) {}
    while (i != result[2][j]) {
        result[0][j + 1] = result[0][j];
        result[1][j + 1] = result[1][j];
        result[2][j + 1] = result[2][j];
        j--;
    }
    j++;
    if (j == i + 1) {
        result[0][j + 1] = result[0][j];
        result[1][j + 1] = result[1][j];
        result[2][j + 1] = result[2][j];
    }
    result[0][j] = value;
    result[1][j] = path;
    result[2][j] = i;
}

static void result_matrix_filling(int ***result_matrix, int size, mini_list *list) {
    for (int current = 0; current < size - 1; current++) {
        int i = 0;
        while (list && list->value[current] == -1) {
            while (i < size) {
                if (!check_for_dup(result_matrix[current],
                list->value[i], list->path[i], i)) {
                    result_matrix[current][0][i] = list->value[i];
                    result_matrix[current][1][i] = list->path[i];
                    result_matrix[current][2][i] = i;
                }
                else if (check_for_dup(result_matrix[current],
                        list->value[i], list->path[i], i) == 2)
                    push_on_place(result_matrix[current],
                    list->value[i], list->path[i], i);
                i++;
            }
                i = 0;
                mx_pop_front_mini(&list);
        }
    }
}

int ***mx_result_matrix(mini_list **list, int size) {
    int each_size = 0;
    int ***result_matrix = (int ***)malloc(sizeof(int **) * size);

    for (int big = 0; big < size - 1; big++) {
        result_matrix[big] = (int **)malloc(sizeof(int *) * 3);
        each_size = mx_count_parallel(list, big);
        for (int medium = 0; medium < 3; medium++) {
            result_matrix[big][medium] =
            (int *)malloc(sizeof(int) * (size * each_size) + 1);
            for (int index = 0; index < each_size * size; index++) {
                result_matrix[big][medium][index] = -3;
                result_matrix[big][medium][each_size * size] = -2;
            }
        }
    }
    result_matrix_filling(result_matrix, size, *list);
    for (int q = 0; q < size - 1 ; q++) {
        printf("\n");
        for (int w = 0; w < 3; w++){
            for (int e = 0; result_matrix[q][w][e] != -2; e++) {
                if (result_matrix[q][w][e] >= 0 && result_matrix[q][w][e] < 10)
                    printf(" %d | ", result_matrix[q][w][e]);
                else if (result_matrix[q][w][e] == -1 || result_matrix[q][w][e] > 9)
                    printf("%d | ", result_matrix[q][w][e]);
            }
            printf("\n");
        }
    }
    return result_matrix;
}