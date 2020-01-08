#include "pathfinder.h"

int main(void) {
    char *str = mx_file_to_str("../qwe");
    int size = mx_atoi(str);
    char **islands = mx_strsplit(str, '\n');
    t_list *list = mx_island_list(islands);
    int **matrix = mx_matrix_creator(islands, list);
    mini_list *list1 = NULL;
//    while (list) {
//        printf("%s  |  ", list->data);
//        list = list->next;
//    }
    mx_deixtra_cycle(matrix, size, &list1);
    mx_result_matrix(&list1, size);
    printf("\n");
    while (list1) {
        for (int i = 0; i < size; i++) {
            printf("%d  |  ", list1->value[i]);
        }
        printf("\n");
        for (int i = 0; i < size; i++) {
            printf("%d  |  ", list1->path[i]);
        }
        printf("\n");
        list1 = list1->next;
        printf("\n");
    }

//    system("leaks pathfinder");
//    //for (int i = 0; i < mx_atoi(str); i++) {
//    //    for (int j = 0; j < mx_atoi(str); j++) {
//    //        printf("%d  ", matrix[i][j]);
//    //    }
//    //    printf("\n");
//    //}
//    return 0;
}
