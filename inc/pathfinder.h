#ifndef PATHFINDER_H
#define PATHFINDER_H

#include "libmx.h"

int mx_is_done(int *path_price, int size);
int mx_is_min(int **path_price, int size);
int mx_validator(char *str, int size, char **islands);
int mx_valid_for_1line(char *str, int *i);
int mx_valid_for_alpha(char *str, int *i);
int mx_valid_for_digits(char *str, int *i);
int mx_valid_for_minus(char c, int *i);
int mx_valid_for_slashn(char c, int *i);
int mx_valid_for_koma(char c, int *i);

typedef struct q_list {
    int *value;
    int *path;
    struct q_list *next;
} mini_list;

typedef struct w_list {
    int *path;
    struct w_list *next;
} result_list;

typedef struct e_list {
    result_list *islands;
    int *path;
    int **matrix;
} result_struct;

result_struct *mx_create_struct(void);
void mx_push_result(result_list **list, int *path);
void mx_pop_front_mini(mini_list **head);
void mx_result_list_creator(int ***result_matrix, int island_count);
void mx_sort_result(result_list *lst);
void mx_write_result(result_list *list);
void mx_deixtra_cycle(int **matrix, int size, mini_list **list);
void mx_deixtra(int **deixtra_matrix, int **matrix, int size, mini_list **list);
mini_list *mx_create_node_custom(int *value, int *path, int size);
t_list *mx_island_list(char **islands);
int mx_index_search(int *path)
int ***mx_result_matrix(mini_list **list, int size);
int mx_count_parallel(mini_list **list, int index);
int mx_island_index(t_list **list, char *str);
int **mx_matrix_creator(char **islands);
void mx_push_back_custom(mini_list **list, int *value, int *path, int size);

#endif
