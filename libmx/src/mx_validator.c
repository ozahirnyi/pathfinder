#include "../inc/libmx.h"

int mx_validator(char *str) {
    int i = 0;

    if (!mx_valid_for_1line(str)) {
        return 0;
    }
    i = 2;
    if (!mx_valid_for_alpha(str, &i)) {
        return 0;
    }
    if (!mx_valid_for_minus(str[i], &i)) {
        return 0;
    }
    if (!mx_valid_for_alpha(str, &i)) {
        return 0;
    }
    if (str[i] != ',')
        return 0;
    i++;
    if (!mx_valid_for_digits(str, &i)) {
        return 0;
    }
    if (!mx_valid_for_slashn(str[i], &i)) {
        return 0;
    }
    mx_printstr(str);
    return 0;
}
