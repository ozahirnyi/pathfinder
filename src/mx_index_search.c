#include "pathfinder.h"

int mx_index_search(int *path) {
    int i = 0;

    while (path[i] != -2)
        i++;
    return i - 1;
}
