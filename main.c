#include "pathfinder.h"

int main(int argc, char **argv) {
    char *str = mx_file_to_str("../qwe");
    int size = mx_atoi(str);
    char **islands = mx_strsplit(str, '\n');
    int **matrix = mx_matrix_creator(islands);
    mini_list *list2 = NULL;
//    while (list) {
//        printf("%s  |  ", list->data);
//        list = list->next;
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
//            if (list1->path[i] != -1)
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
    mx_result_matrix(&list2, size);

    system("leaks pathfinder");
}