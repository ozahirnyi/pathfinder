#include "../inc/libmx.h"

static int check_duplicates(t_list **list, char *str) {
    t_list *buf = *list;

    while (buf != NULL) {
        if (mx_strcmp(buf->data, str) == 0)
            return 1;
        buf = buf->next;
    }
    return 0;
}

t_list  *mx_island_list(char **islands) {
    t_list *new_list = NULL;
    char *temp = NULL;
    char **temp_minus = NULL;
    char **temp_koma = NULL;

    for (int i = 1; islands[i] != NULL; i++) {
        temp_minus = mx_strsplit(islands[i], '-');
        if (!check_duplicates(&new_list, temp_minus[0])) {
            temp = mx_strdup(temp_minus[0]);
            mx_push_back(&new_list, temp);
        }
        temp_koma = mx_strsplit(temp_minus[1], ',');
        if (!check_duplicates(&new_list, temp_koma[0])) {
            temp = mx_strdup(temp_koma[0]);
            mx_push_back(&new_list, temp);
        }
        mx_del_strarr(&temp_minus);
        mx_del_strarr(&temp_koma);
    }
    return new_list;
}
