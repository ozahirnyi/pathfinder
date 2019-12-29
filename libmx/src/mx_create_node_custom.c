#include "../inc/libmx.h"

mini_list	*mx_create_node_custom(int *value, int *path, int size) {
    mini_list *node = (mini_list *)malloc(sizeof(mini_list));
    int *buf_value = (int *)malloc(sizeof(int) * size);

    for (int i = 0; i < size; i++)
        buf_value[i] = value[i];
    free(value);
    int *buf_path = (int *)malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++)
        buf_path[i] = path[i];
    free(path);

    node->value = buf_value;
    node->path = buf_path;
    node->next = NULL;

    return node;
}
