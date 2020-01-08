#include "../inc/libmx.h"

void    result_matrix_filling(int ***result_matrix, int size, mini_list **list);

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

int check_for_duplicates(int **result_matrix, int value, int path) {
    int flag = 0;

    for (int i = 0; i < 2; i++) {
        for (int j = 0; result_matrix[i][j] != -2; j++)
            if (value == result_matrix[0][j] && path == result_matrix[1][j])
                flag = 1;
    }
    printf("FLAG = %d\n", flag);
    if (flag == 1)
        return 1;
    else
        return 0;
}

void    result_matrix_filling(int ***result_matrix, int size, mini_list **list) {
    for (int current = 0; current < size - 1; current++) {
        mini_list *buf = *list;
        int i = 0;
        while (buf) {
            if (buf->value[current] == -1) {
                if (!check_for_duplicates(result_matrix[current], buf->value[i], buf->path[i])) {
                    result_matrix[current][0][i] = buf->value[i];
                    result_matrix[current][1][i] = buf->path[i];
                    result_matrix[current][2][i] = i;
                }
                i++;
            }
                buf = buf->next;
        }
    }
}