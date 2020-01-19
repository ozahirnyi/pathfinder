#include "pathfinder.h"

void mx_push_result(result_list **list, int *path) {
    result_list *node = (result_list *)malloc(sizeof(result_list));
    result_list *buf = *list;

    node->path = path;
    if (buf == NULL)
        *list = node;
    else {
        buf = *list;
        *list = node;
        node->next = buf;
    }
}
