#include "../inc/libmx.h"

int mx_count_parallel(mini_list **list, int index) {
    mini_list *buf = *list;
    int counter = 0;

    while (buf) {
        if (buf->value[index] == -1)
            counter++;
        buf = buf->next;
    }
    return counter;
}