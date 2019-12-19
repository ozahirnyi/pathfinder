#include "../inc/libmx.h"

mini_list	*mx_create_node_custom(int *value, int *path) {
    mini_list *node = (mini_list *)malloc(sizeof(mini_list));

    node->value = value;
    node->path = path;
    node->next = NULL;

    return node;
}
