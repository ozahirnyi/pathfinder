#include "../inc/libmx.h"

void    mx_push_back_filter(mini_list **list, int *value, int *path, int size) {
    mini_list *buf = *list;
    int flag = 0;

    for (int i = 0; buf; i++) {
        for (int i = 0; i < size; i++) {
            if (value[i] != buf->value[i] || path[i] != buf->path[i])
                flag = 1;
        }
        if (flag == 0)
            return ;
        flag = 0;
        buf = buf->next;
    }
    mx_push_back_custom(list, value, path, size);
}
