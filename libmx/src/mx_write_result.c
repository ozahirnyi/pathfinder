#include "../inc/libmx.h"

static void    result_matrix_filling(int ***result_matrix, int size, mini_list *list);

int ***mx_result_matrix(mini_list **list, int size) {
    int each_size = 0;
    int ***result_matrix = (int ***)malloc(sizeof(int **) * size);

        for (int big = 0; big < size - 1; big++) {
            result_matrix[big] = (int **)malloc(sizeof(int *) * 3);
            each_size = mx_count_parallel(list, big);
//            printf("%d  |  ", each_size);
//            printf("\n");
            for (int medium = 0; medium < 3; medium++) {
//                printf("SIZE * EACH_SIZE = %d", size * each_size);
//                printf("\n");
                result_matrix[big][medium] = (int *)malloc(sizeof(int) * (size * each_size) + 1);
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
            for (int e = 0; result_matrix[q][w][e] != -2; e++)
                printf("%d | ", result_matrix[q][w][e]);
            printf("\n");
        }
    }
        return result_matrix;
}

static int check_for_duplicates(int **result_matrix, int value, int path, int index) {
    int flag = 0;
//    printf("INDEX = %d\n", index);

    for (int i = 0; i < 2; i++) {
        for (int j = 0; result_matrix[i][j] != -2; j++) {
            if (value == result_matrix[0][j] && path == result_matrix[1][j] && result_matrix[2][j] == index)
                return 1;
//                if (result_matrix[2][j] != j)
//                    flag = 2;
            else if (value == result_matrix[0][j] && path != result_matrix[1][j] && result_matrix[2][j] == index) {
                int q = j;
                while (result_matrix[2][q] == index) {
//                    printf("Q == %d\n", q);
                    if (value == result_matrix[0][q] && path == result_matrix[1][q] && result_matrix[2][q] == index)
                        return 1;
                    q++;
                }
                return 2;
            }
        }
    }
//    printf("FLAG = %d\n", flag);
    return flag;
}

static void push_on_place(int **result, int value, int path, int i) {
    int j = 0;

//    if (result[0][1] == -1) {
//        printf("RESULT FOR %d = \n\n", i);
//        for (int w = 0; w < 3; w++) {
//            for (int q = 0; result[0][q] != -3; q++)
//                printf("%d | ", result[w][q]);
//            printf("\n");
//        }
//        printf("\n");


//        printf("VALUE = %d\n", value);
//        printf("PATH = %d\n", path);
//
//    }

    for (j = 0; result[0][j] != -3; j++) {}

//    if (result[0][1] == -1) {
//        printf("Start J = %d\n", j);
//        printf("I = %d\n", i);
//    }

    while (j > i) {
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
//        if (result[0][1] == -1) {
//            printf("Finish J = %d\n", j);
//        }
    result[0][j] = value;
    result[1][j] = path;
    result[2][j] = i;

//            if (result[0][1] == -1) {
//                printf("END = %d\n\n", i);
//                for (int w = 0; w < 3; w++) {
//                    for (int q = 0; result[0][q] != -3; q++)
//                        printf("%d | ", result[w][q]);
//                    printf("\n");
//                }
//                printf("\n");
//            }
}

static void    result_matrix_filling(int ***result_matrix, int size, mini_list *list) {
    for (int current = 0; current < size - 1; current++) {
        //mini_list *buf = *list;
        int i = 0;
        while (list->next && list->value[current] == -1) {
            while (i < size) {
                if (!check_for_duplicates(result_matrix[current], list->value[i], list->path[i], i)) {
                    result_matrix[current][0][i] = list->value[i];
                    result_matrix[current][1][i] = list->path[i];
                    result_matrix[current][2][i] = i;
                }
                else if (check_for_duplicates(result_matrix[current], list->value[i], list->path[i], i) == 2) {
//                    printf("CURRENT = %d\n", current);
                    push_on_place(result_matrix[current], list->value[i], list->path[i], i);
                }
                i++;
            }
                i = 0;
//            printf("\n");
//            mini_list *list1 = list;
//            while (list1) {
//                for (int i = 0; i < size; i++) {
//                    printf("%d  |  ", list1->value[i]);
//                }
//                printf("\n");
//                for (int i = 0; i < size; i++) {
//                    printf("%d  |  ", list1->path[i]);
//                }
//                printf("\n");
//                list1 = list1->next;
//                printf("\n");
//            }
                mx_pop_front_mini(&list);
//                buf = buf->next;
        }
    }
}