#include "pathfinder.h"

int mx_valid_for_minus(char c, int *i) {
    if (c != '-')
        return 0;
    (*i)++;
    return 1;
}
