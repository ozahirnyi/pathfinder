#include "../inc/libmx.h"

int mx_valid_for_1line(char *str) {
    int i = 0;

    if (!valid_for_digits(str, &i)) {
        return 0;
    }
    if (!valid_for_slashn(str[i], &i)) {
        return 0;
    }
    return 1;
}