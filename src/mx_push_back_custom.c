#include "pathfinder.h"

void mx_push_back_custom(mini_list **list, int *value, int *path, int size) {
    mini_list *new_node = mx_create_node_custom(value, path, size);
    mini_list *buf = *list;

    if (buf == NULL) {
        *list = new_node;
        return ;
    }
    while (buf->next != NULL)
        buf = buf->next;
    buf->next = new_node;
}
