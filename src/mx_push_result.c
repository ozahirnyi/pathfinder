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

void mx_push_result(t_list **list, int *path) {
    int *dup_path = dup_int_arr(path);
    t_list *node = mx_create_node(dup_path);
    t_list *buf = *list;

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
