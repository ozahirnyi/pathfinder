#include "pathfinder.h"

int mx_valid_for_slashn(char c, int *i) {
    if (c != '\n')
        return 0;
    (*i)++;
    return 1;
}
