#include "../inc/libmx.h"

//void	bzero(void *s, size_t n)
//{
//    unsigned char *ptr;
//
//    ptr = (unsigned char *)s;
//    while (n--)
//        *ptr++ = 0;
//}
//
//t_pathlist *allocate_way_list(size_t len) {
//    t_pathlist *lst = NULL;
//    t_pathlist *iterator;
//    size_t i = 0;
//
//    while (i < len)
//    {
//        if (!lst) {
//            lst = (t_pathlist *)malloc(sizeof(t_pathlist));
//            bzero(lst, sizeof(t_pathlist));
//        }
//        else {
//            iterator = lst;
//            while (iterator->next)
//                iterator = iterator->next;
//            iterator->next = (t_pathlist *)malloc(sizeof(t_pathlist));
//            bzero(iterator->next, sizeof(t_pathlist));
//        }
//        i++;
//    }
//    return (lst);
//}
//
//void add_to_way(t_list **head, void *data, int value)
//{
//    t_list *tmp;
//
//    tmp = (*head);
//    if (!(*head))
//    {
//        (*head) = (t_list *)malloc(sizeof(t_list));
//        bzero((*head), sizeof(t_list));
//        (*head)->data = data;
//        (*head)->value = value;
//    }
//    else {
//        while (tmp->next)
//            tmp = tmp->next;
//        tmp->next = (t_list *) malloc(sizeof(t_list));
//        tmp = tmp->next;
//        bzero(tmp, sizeof(t_list));
//        tmp->data = data;
//        tmp->value = value;
//    }
//}
//
//char *find_data(t_list *name, int order)
//{
//    int i = 0;
//
//    while (i < order && name)
//    {
//        name = name->next;
//        i++;
//    }
//    return ((char *)name->data);
//}
//
//int *calculate_ways_number(int ***result_matrix, t_list *name, int size)
//{
//    size_t i = 0;
//    size_t j = 0; // cause all the time fisrt elem IT'S A PLACE WHERE WE ARE STANDING!!!
//    size_t k = 0;
//    t_pathlist *way_list = allocate_way_list(size - 1);
//    t_list *way = NULL;
//
//
//    while (i < size - 1) // going at first dimension, looking for corresponding array, not including the last way.
//    {
//        add_to_way(&way, name->data, result_matrix[i][VALUES][j]);//adding a start point
//        while (result_matrix[i][VALUES][j] != -1)
//            j++;
//        j += 1; // next elem after -1, iterating trough the rooms.//and here we find a destination point
//        add_to_way(&way, find_data(name, result_matrix[i][NAME][j]), result_matrix[i][VALUES][j]);//TODO пока что сделаем так - что последний элемент на втором месте
//        while(result_matrix[i][WAYS][j] != -1)
//        {
//
//        }
//
//        i++;
//    }
//
//    return 0;
//}
//
//void  print_dilim(void)
//{
//    size_t i = 0;
//
//    while (i < 40)
//    {
//        mx_printchar('-');
//        i++;
//    }
//    mx_printchar('\n');
//}
//
//void output(int **ways, t_list *names, int size)
//{
//
//}