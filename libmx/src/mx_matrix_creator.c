#include "../inc/libmx.h"

static int island_index(t_list *list, char *str) {
    int count = 0;
    t_list *buf = list;

    while (buf != NULL) {
        if (mx_strcmp(buf->data, str) == 0)
            return count;
        count++;
        buf = buf->next;
    }
    return -1;
}

static int check_duplicates(t_list **list, char *str) {
    t_list *buf = *list;

    while (buf != NULL) {
        if (mx_strcmp(buf->data, str) == 0)
            return 1;
        buf = buf->next;
    }
    return 0;
}

static t_list *islands_list(char **island) {
    t_list *new_list = NULL;
    char *temp = NULL;

    for (int i = 1; island[i] != NULL; i++) {
        char **temp_minus = mx_strsplit(island[i], '-');
            if (!check_duplicates(&new_list, temp_minus[0])) {
                temp = mx_strdup(temp_minus[0]);
                mx_push_back(&new_list, temp);
            }
        char **temp_koma = mx_strsplit(temp_minus[1], ',');
            if (!check_duplicates(&new_list, temp_koma[0])) {
                temp = mx_strdup(temp_koma[0]);
                mx_push_back(&new_list, temp);
            }
        mx_del_strarr(&temp_minus);
        mx_del_strarr(&temp_koma);
    }
    return new_list;
}

/*static char  **islands(char *str) {
    char **splitter_n = mx_strsplit(str, '\n');

    for (int i = 0; splitter_n[i]; i++)
        printf("%s\n", splitter_n[i]);
    return splitter_n;
}*/

int **mx_matrix_creator(int size, char **islands) {
    int **matrix = (int **)malloc(size * (sizeof(int **)));
    t_list *list = islands_list(islands);

    while (list != NULL) {
        printf("data = %s\n", list->data);
        printf("count = %d\n", list->count);
        list = list->next;
    }
    printf("%d\n", island_index(list, "Java"));
    for (int i = 0; i < size; i++) {
        matrix[i] = (int *)malloc(size * (sizeof(int *)));
        for (int j = 0; j < size; j++)
            matrix[i][j] = 1;
    }
    return matrix;
}