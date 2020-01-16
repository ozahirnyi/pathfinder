#include "../inc/libmx.h"

int mx_valid_for_alpha(char *str, int *i) {
    if (!mx_is_alpha(str[(*i)]))
        return 0;
    (*i)++;
    while (mx_is_alpha(str[(*i)]))
        (*i)++;
    return 1;
}