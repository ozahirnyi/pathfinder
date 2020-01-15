#include "../inc/libmx.h"

int valid_for_minus(char c, int *i) {
    if (c != '-')
        return -1;
    (*i)++;
    return 1;
}