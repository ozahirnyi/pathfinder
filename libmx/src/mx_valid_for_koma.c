#include "../inc/libmx.h"

int mx_valid_for_koma(char c, int *i) {
    if (c != ',')
        return 0;
    (*i)++;
    return 1;
}
