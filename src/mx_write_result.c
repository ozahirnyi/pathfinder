#include "pathfinder.h"

static char *island_by_index(t_list **island, int index) {
    t_list *buf = *island;
    char *cast = NULL;

    while (index > 0) {
        buf = buf->next;
        index--;
    }
    cast = buf->data;
    return cast;
}

static void path_n_route(t_list *island, int *result) {
    int start = mx_index_search(result);

    mx_printstr("========================================\nPath: ");
    mx_printstr(island_by_index(&island, result[start]));
    mx_printstr(" -> ");
    mx_printstr(island_by_index(&island, result[0]));
    mx_printstr("\nRoute: ");
    mx_printstr(island_by_index(&island, result[start]));
    if (start > 1) {
        for (int i = start - 1; i >= 0; i--) {
            mx_printstr(" -> ");
            mx_printstr(island_by_index(&island, result[i]));
        }
    }
    else {
        mx_printstr(" -> ");
        mx_printstr(island_by_index(&island, result[0]));
    }
}

static void destination(int *result, int **matrix) {
    int start = mx_index_search(result);

    mx_printstr("\nDistance: ");
    for (int i = 0; matrix[2][i] != -2; i++) {
        if (result[start - 1] == matrix[2][i]) {
            mx_printint(matrix[0][i]);
            break;
        }
    }
    if (start > 1) {
        int p = start - 2;
        for (; p >= 0; p--) {
            for (int j = 0; matrix[2][j] != -2; j++) {
                if (result[p] == matrix[2][j] && result[p + 1] == matrix[1][j]) {
                    mx_printstr(" + ");
                    mx_count_distance(matrix, matrix[1][j], matrix[2][j]);
                }
            }
        }
    }
}

static void print_result(t_list *island, int *result, int **matrix) {
    int start = mx_index_search(result);

    path_n_route(island, result);
    destination(result, matrix);
    if (start > 1) {
        mx_printstr(" = ");
        for (int i = 0; matrix[2][i] != -2; i++) {
            if(result[0] == matrix[2][i]) {
                mx_printint(matrix[0][i]);
                break;
            }
        }
    }
    mx_printstr("\n========================================\n");
}

void mx_write_result(t_list **result, char **islands, int ***matrix) {
    t_list *island = mx_island_list(islands);
    t_list *buf = *result;
    int i = -1;

    while (buf) {
        int *buf_cast = (int *)buf->data;
        if (buf_cast[mx_index_search(buf_cast)] != i)
            i++;
            print_result(island, buf->data, matrix[i]);
            mx_pop_front(&buf);
    }
    while (island)
        mx_pop_front(&island);
}
