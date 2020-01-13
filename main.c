#include "pathfinder.h"

void list_filler(t_list *list, mini_list *list1, char *str, int size) {
    char **islands = mx_strsplit(str, '\n');
    list = mx_island_list(islands);
    int **matrix = mx_matrix_creator(islands, list);

    mx_deixtra_cycle(matrix, size, &list1);
    mx_result_matrix(&list1, size);
}

int main(int argc, char **argv) {
    char *str = mx_file_to_str("../qwe");
    int size = mx_atoi(str);
    t_list *list = NULL;
    mini_list *list1 = NULL;

    list_filler(list, list1, str, size);
//    while (list) {
//        printf("%s  |  ", list->data);
//        list = list->next;
//    }
//    printf("\n");
//    mini_list *list1 = list2;
//    while (list1) {
//        for (int i = 0; i < size; i++) {
//            if (list1->value[i] != -1)
//                printf(" %d  |  ", list1->value[i]);
//            else
//                printf("%d  |  ", list1->value[i]);
//        }
//        printf("\n");
//        for (int i = 0; i < size; i++) {
//            if (list1->path[i] != -1)
//                printf(" %d  |  ", list1->path[i]);
//            else
//                printf("%d  |  ", list1->path[i]);
//        }
//        printf("\n");
//        list1 = list1->next;
//        printf("\n");
//    }

//    system("leaks pathfinder");
//    //for (int i = 0; i < mx_atoi(str); i++) {
//    //    for (int j = 0; j < mx_atoi(str); j++) {
//    //        printf("%d  ", matrix[i][j]);
//    //    }
//    //    printf("\n");
//    //}
//    return 0;
}
