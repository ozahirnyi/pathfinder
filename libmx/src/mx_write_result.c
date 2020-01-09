#include "../inc/libmx.h"

static void    result_matrix_filling(int ***result_matrix, int size, mini_list **list);

int ***mx_result_matrix(mini_list **list, int size) {
    int each_size = 0;
    int ***result_matrix = (int ***)malloc(sizeof(int **) * size);

        for (int big = 0; big < size - 1; big++) {
            result_matrix[big] = (int **) malloc(sizeof(int *) * 3);
            each_size = mx_count_parallel(list, big);
//            printf("%d  |  ", each_size);
//            printf("\n");
            for (int medium = 0; medium < 3; medium++) {
//                printf("SIZE * EACH_SIZE = %d", size * each_size);
//                printf("\n");
                result_matrix[big][medium] = (int *) malloc(sizeof(int) * (size * each_size) + 1);
                for (int index = 0; index < each_size * size; index++) {
                    result_matrix[big][medium][index] = -3;
                    result_matrix[big][medium][each_size * size] = -2;
                }
            }
        }
    result_matrix_filling(result_matrix, size, list);
    for (int q = 0; q < size - 1; q++) {
        printf("\n");
        for (int w = 0; w < 3; w++){
            for (int e = 0; result_matrix[q][w][e] != -2; e++)
                printf("%d | ", result_matrix[q][w][e]);
            printf("\n");
        }
    }
        return result_matrix;
}

static int check_for_duplicates(int **result_matrix, int value, int path, int index) {
    int flag = 0;
    printf("INDEX = %d\n", index);

    for (int i = 0; i < 2; i++) {
        for (int j = 0; result_matrix[i][j] != -2; j++) {
            if (value == result_matrix[0][j] && path == result_matrix[1][j] && result_matrix[2][j] == index)
                return 1;
//                if (result_matrix[2][j] != j)
//                    flag = 2;
            else if (value == result_matrix[0][j] && path != result_matrix[1][j])
                return 2;
        }
    }
    printf("FLAG = %d\n", flag);
    return flag;
}

static void push_on_place(int **result, int value, int path, int i) {
    int j = 0;

    printf("RESULT FOR %d = \n\n", i);
    for (int w = 0; w < 3; w++) {
        for (int q = 0; result[0][q] != -3; q++)
            printf("%d | ", result[w][q]);
        printf("\n");
    }
    printf("\n");

    printf("VALUE = %d\n", value);
    printf("PATH = %d\n", path);
    for (j = 0; result[0][j] != -3; j++);
//    printf("Start J = %d\n", j);
//    printf("I = %d\n", i);
    while (j > i) {
        result[0][j + 1] = result[0][j];
        result[1][j + 1] = result[1][j];
        result[2][j + 1] = result[2][j];
        j--;
    }
    j++;
//    printf("Finish J = %d\n", j);
    result[0][j] = value;
    result[1][j] = path;
    result[2][j] = i;
    printf("END = %d\n\n", i);
    for (int w = 0; w < 3; w++) {
        for (int q = 0; result[0][q] != -3; q++)
            printf("%d | ", result[w][q]);
        printf("\n");
    }
    printf("\n");
}

static void    result_matrix_filling(int ***result_matrix, int size, mini_list **list) {
    for (int current = 0; current < size - 1; current++) {
        mini_list *buf = *list;
        int i = 0;
        while (buf->value[current] == -1) {
            while (i < size) {
                if (!check_for_duplicates(result_matrix[current], buf->value[i], buf->path[i], i)) {
                    result_matrix[current][0][i] = buf->value[i];
                    result_matrix[current][1][i] = buf->path[i];
                    result_matrix[current][2][i] = i;
                }
                else if (check_for_duplicates(result_matrix[current], buf->value[i], buf->path[i], i) == 2) {
                    printf("I = %d\n", i);
                    push_on_place(result_matrix[current], buf->value[i], buf->path[i], i);
//                    result_matrix[current][0][i] = buf->value[i];
//                    result_matrix[current][1][i] = buf->path[i];
//                    result_matrix[current][2][i] = i;
                }
//                else if (check_for_duplicates(result_matrix[current], buf->value[i], buf->path[i]) == 2)
//                    push_on_place(result_matrix[current], buf->value[i], buf->path[i], i);
//                    printf("HYU\n");
                i++;
            }
                i = 0;
                buf = buf->next;
        }
    }
}