#include "pathfinder.h"

static int *dup_int_arr(int *path) {
    int size = 0;
    int i = 0;

    while (path[i] < -2 || path[i] > -1) {
        size++;
        i++;
    }
    int *node = (int *)malloc(sizeof(int) * size + 1);
    for (i = 0; i < size; i++)
        node[i] = path[i];
    node[size] = -2;
    return node;
}

void mx_push_result(result_list **list, int *path) {
    result_list *node = (result_list *)malloc(sizeof(result_list));
    result_list *buf = *list;

    node->path = dup_int_arr(path);
//    free(path);
    if (buf == NULL) {
        *list = node;
        (*list)->next = NULL;
    }
    else {
        buf = *list;
        *list = node;
        node->next = buf;
    }
}
