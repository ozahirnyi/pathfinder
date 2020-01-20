#include "pathfinder.h"

static int *path_creator(int island_count) {
    int *path = (int *)malloc(sizeof(int) * island_count + 1);

    for (int i = 0; i < island_count; i++)
        path[i] = -1;
    path[island_count] = -2;
    return path;
}

static int get_new_index(int **result_matrix, int island) {
    int i = 0;

    while (result_matrix[2][i] != island) {
        if (result_matrix[2][i] == island)
            break ;
        i++;
    }
    return i;
}

static void algorithm(result_struct *result, int island_index,
int dest, int path_index) {
    int new_dest = 0;

    result->path[path_index] = result->matrix[2][dest];
    path_index++;
    if (result->matrix[1][dest] == -1) {
        result->path[path_index] = island_index;
        mx_push_result(&result->islands, result->path);
    }
    else {
        new_dest = get_new_index(result->matrix, result->matrix[1][dest]);
        while (result->matrix[2][new_dest] == result->matrix[1][dest]) {
            algorithm(result, island_index, new_dest, path_index);
            new_dest++;
        }
    }
}

static void list_filler(result_struct *result, int island_index,
int **matrix, int island_count) {
    result->matrix = matrix;
    int j = 0;

    for (j = 0; matrix[2][j] != island_index; j++);
    int i = j + 1;
    for (; result->matrix[0][i] < -3
        || result->matrix[0][i] > -2; i++) {
        for (int q = 0; q < island_count; q++)
            result->path[q] = -1;
        result->path[island_count] = -2;
        algorithm(result, island_index, i, 0);
    }
}

void mx_result_list_creator(int ***result_matrix, int island_count) {
    result_struct *result = mx_create_struct();
    result->path = path_creator(island_count);

    for (int i = 0; i < island_count - 1; i++)
        list_filler(result, i, result_matrix[i], island_count);
    result_list *buf = result->islands;
    while (buf) {
        printf("INDEX = %d\n", mx_index_search(buf->path));
        for (int i = 0; buf->path[i] != -2; i++)
            printf("%d | ", buf->path[i]);
        printf("\n");
        buf = buf->next;
    }
//    mx_sort_result()
}
