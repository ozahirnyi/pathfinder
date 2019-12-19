#include "../inc/libmx.h"

void	mx_push_back_custom(mini_list **list, int *value, int * path) {
    mini_list *new_node = mx_create_node_custom(value, path);
    mini_list *buf = *list;

    if (buf == NULL) {
        *list = new_node;
        return ;
    }
    while (buf->next != NULL)
        buf = buf->next;
    buf->next = new_node;
}

