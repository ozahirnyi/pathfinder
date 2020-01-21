#include "pathfinder.h"

void mx_count_distance(int **matrix, int first, int second) {
    int i = 0;
    int len;

    for (i = 0; matrix[2][i] != -2; i++) {
        if (first == matrix[2][i]) {
            first = matrix[0][i];
            break;
        }
    }
    for (i = 0; matrix[2][i] != -2; i++) {
        if (second == matrix[2][i]) {
            second = matrix[0][i];
            break;
        }
    }
    len = second - first;
    mx_printint(len);
}
