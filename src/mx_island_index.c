#include "pathfinder.h"

int mx_island_index(t_list **list, char *str) {
    int count = 0;
    t_list *buf = *list;

    while (buf != NULL) {
        if (mx_strcmp(buf->data, str) == 0)
            return count;
        count++;
        buf = buf->next;
    }
    return -1;
}
