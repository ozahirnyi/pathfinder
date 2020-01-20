#include "pathfinder.h"

int mx_index_search(int *path) {
    int i = 0;
    int buf = -1;

    for (; path[i] < -2 || path[i] > -1; i++);
    buf = path[i];
    while (path[i] == buf)
        i--;
    return i;
}
