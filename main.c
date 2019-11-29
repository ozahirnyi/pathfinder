#include "pathfinder.h"

int main(void) {
    char *str = mx_file_to_str("../qwe");
    //char **splitted = mx_strsplit(str, '\n');
    int **matrix = mx_matrix_creator(str);

    for (int i = 0; i < mx_atoi(str); i++) {
        for (int j = 0; j < mx_atoi(str); j++) {
            printf("%d  ", matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}
