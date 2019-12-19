#include "pathfinder.h"

int main(void) {
    char *str = mx_file_to_str("../qwe");
    int size = mx_atoi(str);
    char **islands = mx_strsplit(str, '\n');
    t_list *list = mx_island_list(islands);
    int **matrix = mx_matrix_creator(islands, list);
    mini_list *mini_list = mx_deixtra(matrix, size, mini_list);
    while (mini_list) {
        for (int i = 0; i < size; i++) {
            printf("%d  |  ", mini_list->value[i]);
        }
        printf("\n");
        for (int i = 0; i < size; i++) {
            printf("%d  |  ", mini_list->path[i]);
        }
        printf("\n");
        mini_list = mini_list->next;
        printf("\n");
    }

    //system("leaks pathfinder");
    //for (int i = 0; i < mx_atoi(str); i++) {
    //    for (int j = 0; j < mx_atoi(str); j++) {
    //        printf("%d  ", matrix[i][j]);
    //    }
    //    printf("\n");
    //}
    return 0;
}
