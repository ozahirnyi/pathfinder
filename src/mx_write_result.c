#include "pathfinder.h"
//
//void	bzero(void *s, int n)
//{
//    unsigned char *ptr;
//    ​
//    ptr = (unsigned char *)s;
//    while (n--)
//        *ptr++ = 0;
//}
//​
//t_pathlist *allocate_way_list(int len) {
//    t_pathlist *lst = NULL;
//    t_pathlist *iterator;
//    int i = 0;
//    ​
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
//​
//void add_to_way(t_list **head, void *data, int value)
//{
//    t_list *tmp;
//    ​
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
//​
//char *find_data(t_list *name, int order)
//{
//    int i = 0;
//    ​
//    while (i < order && name)
//    {
//        name = name->next;
//        i++;
//    }
//    return ((char *)name->data);
//}
//​
//void add_to_way_list(t_pathlist *head, t_list *list)
//{
//    while(!head->way)
//        head->way = list;
//    head->way = list;
//}
//​
//void clear_way(t_list **way)
//{
//    t_list *tmp = (*way);
//    t_list *buf;
//    ​
//    while(tmp)
//    {
//        buf = tmp;
//        tmp = tmp->next;
//        free(buf);
//    }
//    *way = NULL;
//}
//​
//int     count_size(int const *array)
//{
//    int size = 0;
//    ​
//    while (array[size] != -3)
//        size++;
//    return (size);
//}
//​
//void  print_dilim(void);
//​
//void output(t_pathlist *way_list);
//​
//int *calculate_ways_number(int **result_matrix, t_list *name)
//{
//    int i = 0;
//    int j = 1;
//    int k = 0;
//    int size = count_size(*result_matrix);
//    t_pathlist *way_list = allocate_way_list(size - 1);
//    t_list *way = NULL;
//    ​
//    while(result_matrix[VALUES][i] != -1 && result_matrix[WAYS][i] != -1)
//        i++;
//    char *start_name = find_data(name, result_matrix[NAME][i]);
//    int start_value = 0;
//    ​
//    while (j < size)
//    {
//        add_to_way(&way, start_name, start_value);//start;
//        add_to_way(&way, find_data(name, result_matrix[NAME][j]), result_matrix[VALUES][j]);//end;
//        while (result_matrix[WAYS][j] != -1)
//        {
//            k = size;
//            add_to_way(&way, find_data(name, result_matrix[NAME][j]), result_matrix[VALUES][j]);
//            while(k > 0)
//            {
//                if (result_matrix[NAME][k] == result_matrix[WAYS][j]) {
//                    j = k;
//                }
//                k--;
//            }
//        }
//        //put here add_to_way
////        else if (result_matrix[WAYS][j] == -1)
////            j++;
//        add_to_way_list(way_list, way);
//        clear_way(&way);
////        j++;
//    }
//    output(way_list);
//    return 0;
//}
//​
//void  print_dilim(void)
//{
//    size_t i = 0;
//    ​
//    while (i < 40)
//    {
//        mx_printchar('-');
//        i++;
//    }
//    mx_printchar('\n');
//}
//​
//t_list *find_end_at_way(t_list *way)
//{
//    way = way->next;//cause second - IT IS THE END!!!!
//    return (way);
//}
//​
//void output(t_pathlist *way_list)
//{
//    int sum = 0;
//    while (way_list && way_list->way)
//    {
//        print_dilim();
//        t_list *tmp = (way_list)->way;
//        t_list *end = find_end_at_way(tmp);
//        mx_printstr(PATH);
//        mx_printstr(tmp->data);
//        mx_printstr(" -> ");
//        mx_printstr(end->data);
//        mx_printchar('\n');
//        mx_printstr("Route: ");
//        while(tmp)
//        {
//            mx_printstr(tmp->data);
//            mx_printstr(" -> ");
//            tmp = tmp->next;
//        }
//        tmp = (way_list)->way;
//        mx_printstr("Distance: ");
//        while(tmp)
//        {
//            if (tmp->value >= 0) {
//                mx_printint(tmp->value);
//                sum += tmp->value;
//                mx_printstr(" + ");
//            }
//            tmp = tmp->next;
//        }//COSTILI on pre last elem!
//        mx_printstr(" = ");
//        mx_printint(sum);
//        mx_printstr("\n");
//        print_dilim();
//        way_list = (way_list)->next;
//    }
//}