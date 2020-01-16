#include "../inc/libmx.h"

int mx_valid_for_digits(char *str, int *i) {
    if (!mx_isdigit(str[(*i)]))
        return 0;
    while (mx_isdigit(str[(*i)]))
        (*i)++;
    return 1;
}
