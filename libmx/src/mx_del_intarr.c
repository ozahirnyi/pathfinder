#include "pathfinder.h"

void	mx_del_intarr(int ***arr, size) {
    int **ar = (*arr);
    int i;

    for (i = 0; i < size; i++) {
        free(*ar[i]);
        (*ar[i]) = NULL;
    }
    free(*arr);
    *arr = NULL;
}
