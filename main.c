#include "pathfinder.h"

int main(void) {
    int **matrix = mx_matrix_creator("../qwe");

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d  ", matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}
