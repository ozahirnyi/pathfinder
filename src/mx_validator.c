#include "pathfinder.h"

static void check_for_islands(int size, char **islands) {
    t_list *list = mx_island_list(islands);

    int list_size = mx_list_size(list);
    if (list_size != size) {
        mx_printerr("error: invalid number of islands");
        exit(1);
    }
    else
        return ;
}

static void print_line_err(int index) {
    mx_printerr("error: line ");
    mx_printerr(mx_itoa(index));
    mx_printerr(" is not valid");
}

static int first_valid(char *str, int *i, int line) {
    if (!mx_valid_for_alpha(str, i)) {
        print_line_err(line);
        return 0;
    }
    if (!mx_valid_for_minus(str[(*i)], i)) {
        print_line_err(line);
        return 0;
    }
    if (!mx_valid_for_alpha(str, i)) {
        print_line_err(line);
        return 0;
    }
    else
        return 1;
}

static int second_valid(char *str, int *i, int line) {
    if (!mx_valid_for_koma(str[(*i)], i)) {
        print_line_err(line);
        return 0;
    }
    if (!mx_valid_for_digits(str, i)) {
        print_line_err(line);
        return 0;
    }
    if (!mx_valid_for_slashn(str[(*i)], i)) {
        print_line_err(line);
        return 0;
    }
    else
        return 1;
}

int mx_validator(char *str, int size, char **islands) {
    int i = 0;
    int line = 2;

    if (!mx_valid_for_1line(str, &i)) {
        print_line_err(1);
        return 0;
    }
    while (str[i] != '\0') {
        if (!first_valid(str, &i, line))
            return 0;
        if (!second_valid(str, &i, line))
            return 0;
        line++;
    }
    check_for_islands(size, islands);
    mx_printstr(str);
    return 1;
}
