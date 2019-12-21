#include "../inc/libmx.h"

int mx_is_min(int **path_price, int size) {
    int min = 2147483647;
    int i;
    int j = 0;

    for (i = 0; i < size; i++) {
        if (min > path_price[0][i] && path_price[0][i] != -1 && path_price[2][i] != 1)
            min = path_price[0][i];
    }
    if (min == 2147483647)
        return -1;
    while (path_price[0][j] != min || path_price[2][j] == 1)
        j++;
    return j;
}