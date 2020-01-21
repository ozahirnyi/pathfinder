#include "pathfinder.h"

int main() {
//    if (argc == 2) {
        char *str = mx_file_to_str("../qwe");
        int size = mx_atoi(str);
        char **islands = mx_strsplit(str, '\n');
        mx_validator(str, size, islands);
        int **matrix = mx_matrix_creator(islands);
        mini_list *list2 = NULL;
        //   t_list *list2 = NULL;
//
//    mx_push_back(&list2, "0321");
//    mx_push_back(&list2, "0231");
//    mx_push_back(&list2, "0324");
//    mx_push_back(&list2, "0523");
//    mx_push_back(&list2, "04513");
//    mx_push_back(&list2, "0542");
//    mx_push_back(&list2, "0325");
//
//    t_list *buf = list2;
//    while (buf) {
//        printf("%s  |  ", buf->data);
//        buf = buf->next;
//    }
//    mx_sort_result(list2);
//    printf("\n");
//    while (list2) {
//        printf("%s  |  ", list2->data);
//        list2 = list2->next;
//    }
        mx_deixtra_cycle(matrix, size, &list2);
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
//            if (list1->path[i] != -1 || (list1->path[i] <= 9 && list1->path[i] >= 0))
//                printf(" %d  |  ", list1->path[i]);
//            else
//                printf("%d  |  ", list1->path[i]);
//        }
//        printf("\n");
//        list1 = list1->next;
//        printf("\n");
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
        mx_result_matrix(&list2, size, islands);

    system("leaks -q pathfinder");
//    }
//    else
//        mx_printerr("usage: ./pathfinder [filename]\n");
}
