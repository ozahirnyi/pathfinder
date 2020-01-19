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
            return i;
        i++;
    }
    return 0;
}

static void algorithm(result_struct *result, int island_index, int dest, int path_index) {
    int new_dest = 0;

    result->path[path_index] = result->matrix[2][dest];
    path_index++;
    if (result->matrix[1][dest] == -1) {
        result->path[path_index] = result->matrix[2][island_index];
        mx_push_result(result->islands, result->path);
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
    result->path = path_creator(island_count);
    result->result_matrix = matrix;

    for (int i = 0; result->matrix[0][i] < -3
        || result->matrix[0][i] > -2; i++)
        algorithm(result, island_index, i, 0);
}

void mx_result_list_creator(int ***result_matrix, int island_count) {
    result_struct *result = mx_create_struct();

    for (int i = 0; i < island_count - 1; i++)
        list_filler(result, i, result_matrix[i], island_count);
//    result_list *buf = list;
//    while (buf) {
//        printf("%s\n", (char *)buf->data);
//        printf("\n");
//        buf = buf->next;
//    }
}
