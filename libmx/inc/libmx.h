#ifndef LIBMX_H
#define LIBMX_H

#include <unistd.h>
#include <wchar.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdbool.h>
#include <limits.h>

void	mx_printint(int n);
void	mx_printchar(char c);
void	mx_strdel(char **str);
void	mx_del_strarr(char ***arr);
void	mx_printstr(const char *s);
void	mx_del_intarr(int ***arr, size);
int	mx_strlen(const char *s);
int	mx_strcmp(const char *s1, const char *s2);
int mx_isdigit(char c);
int	mx_is_space(char c);
int mx_atoi(const char *str);
int	mx_strncmp(const char *s1, const char *s2, int n);
int	mx_is_space(char c);
int	mx_count_words(const char *str, char c);
int	mx_skip_substr_index(const char *str, const char *sub, int counter);
int	mx_count_substr(const char *str, const char *sub);
char mx_validator(void);
char	*mx_file_to_str(const char *file);
char	*mx_strnew(const int size);
char	*mx_strcpy(char *dst, const char *src);
char	*mx_strncpy(char *dst, const char *src, int len);
char	*mx_strtrim(const char *str);
char	*mx_strcat(char *restrict s1, const char *restrict s2);
char	*mx_strdup(const char *s1);
char	*mx_strndup(const char *s1, size_t n);
char	*mx_ultra_strtrim(const char *str, char c);
char	*mx_ultra_del_extra_spaces(const char *str, char c);
char	**mx_strsplit(const char *s, char c);

typedef struct s_list {
	char *data;
	struct s_list *next;
} t_list;

typedef struct q_list {
    int *value;
    int *path;
    struct q_list *next;
} mini_list;

mini_list   *mx_deixtra(int **mini_matrix, int size);
mini_list   *mx_create_node_custom(int *value, int *path);
t_list	*mx_create_node(void *data);
t_list  *mx_island_list(char **islands);
t_list	*mx_sort_list(t_list *lst, bool (*cmp)(void *, void *));
int	mx_list_size(t_list *list);
int mx_island_index(t_list **list, char *str);
int **mx_matrix_creator(char **islands, t_list *list);
void	mx_push_back_custom(mini_list **list, int *value, int *path);
void	mx_push_front(t_list **list, void *data);
void	mx_push_back(t_list **list, void *data);
void	mx_pop_front(t_list **head);
void	mx_pop_back(t_list **head);

#endif
