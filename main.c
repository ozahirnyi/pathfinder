#include "pathfinder.h"

int mx_custom_cmp(const char *s1, const char *s2) {
    int finishlen = mx_strlen(s1);
    int finishlen1 = mx_strlen(s2);

    if (s1[0] != s2[0])
        return s1[0] - s2[0];
    else if (s1[finishlen] != s2[finishlen1])
        return s1[finishlen] - s2[finishlen1];
}

bool cmp(void *a, void *b) {
    if (mx_strcmp((char *)a, (char *)b) > 0)
        return 1;
    else
        return 0;
}

int main(int argc, char **argv) {
//    char *str = mx_file_to_str("../qwe");
//    int size = mx_atoi(str);
//    char **islands = mx_strsplit(str, '\n');
//    int **matrix = mx_matrix_creator(islands);
//    mini_list *list232 = NULL;
    t_list *list2 = NULL;

    mx_push_back(&list2, "0321");
    mx_push_back(&list2, "0231");
    mx_push_back(&list2, "0324");
    mx_push_back(&list2, "0543");
    mx_push_back(&list2, "0523");
    mx_push_back(&list2, "0542");
    mx_push_back(&list2, "0325");

    t_list *buf = list2;
    while (buf) {
        printf("%s  |  ", buf->data);
        buf = buf->next;
    }
    mx_sort_result(list2, *cmp);
    printf("\n");
    while (list2) {
        printf("%s  |  ", list2->data);
        list2 = list2->next;
    }
//    mx_deixtra_cycle(matrix, size, &list2);
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
//    mx_result_matrix(&list2, size);

//    system("leaks pathfinder");
}