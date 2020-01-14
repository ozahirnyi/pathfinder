#include "../inc/libmx.h"

static int valid_for_digits(char *str, int *i) {
    if (!mx_isdigit(str[0]))
        return 0;
    while (mx_isdigit(str[(*i)]))
        (*i)++;
    return 1;
}

static int valid_for_alpha(char *str, int *i) {
    if (!mx_is_alpha(str[(*i)]))
        return 0;
    (*i)++;
    while (mx_is_alpha(str[(*i)]))
        (*i)++;
    return 1;
}

static int valid_for_minus(char c, int *i) {
    if (c != '-')
        return -1;
    (*i)++;
    return 1;
}

static int valid_for_slashn(char c, int *i) {
    if (c != '\n')
        return 0;
    (*i)++;
    return 1;
}

int mx_validator(char *str) {
    int i = 0;

    if (!valid_for_digits(str, &i)) {
        return 0;
    }
    if (!valid_for_slashn(str[i], &i)) {
        return 0;
    }
    if (!valid_for_alpha(str, &i)) {
        return 0;
    }
    if (!valid_for_minus(str[i], &i)) {
        return 0;
    }
    if (!valid_for_alpha(str, &i)) {
        return 0;
    }
    if (str[i] != ',')
        return 0;
    i++;
    if (!valid_for_digits(str, &i)) {
        return 0;
    }
    if (!valid_for_slashn(str[i], &i)) {
        return 0;
    }
    mx_printstr(str);
    return 0;
}
