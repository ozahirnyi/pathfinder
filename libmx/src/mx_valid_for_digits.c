#include "../inc/libmx.h"

int valid_for_digits(char *str, int *i) {
    if (!mx_isdigit(str[0]))
        return 0;
    while (mx_isdigit(str[(*i)]))
        (*i)++;
    return 1;
}
