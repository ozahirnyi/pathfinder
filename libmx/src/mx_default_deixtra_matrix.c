#include "../inc/libmx.h"

int **mx_default_deixtra_matrix(int *islands_value, int size) {
    int **default_matrix = (int **)malloc(sizeof(int *) * 3);

    for (int j = 0; j < 3; j++) {
        default_matrix[j] = (int *)malloc(sizeof(int) * size);
        for (int i = 0; i < size; i++) {
            if (j == 0)
                default_matrix[j][i] = islands_value[i];
            else if (j == 1)
                default_matrix[j][i] = -1;
            else
                default_matrix[j][i] = 0;
        }
    }
    return default_matrix;
}
