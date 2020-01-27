#include "pathfinder.h"

int main(int argc, char **argv) {
    if (argc == 2) {
        char *str = mx_file_to_str(argv[1]);
        int size = mx_atoi(str);
        mini_list *list2 = NULL;
        char **islands = mx_strsplit(str, '\n');
        int **matrix = NULL;
        
        mx_validator(str, size, islands);
        matrix = mx_matrix_creator(islands);
        mx_deixtra_cycle(matrix, size, &list2);
        mx_result_matrix(&list2, size, islands);

    }
    else {
        mx_printerr("usage: ./pathfinder [filename]\n");
		exit(1);
	}
}
