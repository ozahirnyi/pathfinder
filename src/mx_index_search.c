#include "pathfinder.h"

int mx_index_search(int *path, int start) {
    for (int i = 0; path[i] != start; i++);
    i++;
    return i;
}
