#include "pathfinder.h"

int mx_valid_for_1line(char *str, int *i) {
    if (str[0] == 48) {
        mx_printerr("Ne uzai nol po bratski");
        exit(1);
    }
    if (!mx_valid_for_digits(str, i)) {
        return 0;
    }
    if (!mx_valid_for_slashn(str[(*i)], i)) {
        return 0;
    }
    return 1;
}
