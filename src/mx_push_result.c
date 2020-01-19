#include "pathfinder.h"

void mx_push_result(result_list *list, int *path) {
    result_list *node = (result_list *)malloc(sizeof(result_list));

    node->path = path;
    node->next = list;
    list = node;
}
