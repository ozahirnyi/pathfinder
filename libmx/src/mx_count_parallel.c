#include "../inc/libmx.h"

int mx_count_parallel(mini_list **list, int index) {
    mini_list *buf = *list;
    int counter = 0;

    for (int current = 0; buf->value[current] == -1; current++) {
        while (buf->value[index] == -1) {
            if (buf->value[index] == -1)
                counter++;
            buf = buf->next;
        }
    }
    return counter;
}