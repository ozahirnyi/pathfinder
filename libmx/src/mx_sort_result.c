#include "../inc/libmx.h"

static int mx_custom_cmp(const char *s1, const char *s2) {
    int finishlen = mx_strlen(s1) - 1;
    int finishlen1 = mx_strlen(s2) - 1;

    if (s1[0] != s2[0])
        return s1[0] - s2[0];
    else if (s1[finishlen] != s2[finishlen1])
        return s1[finishlen] - s2[finishlen1];
    else
        return 0;
}

static int  mx_middle_cmp(const char *s1, const char *s2) {
    int i;

    i = 0;
    while (s1[i + 2] != '\0' && s2[i + 2] != '\0' && s1[i] == s2[i])
        i++;
    return s1[i] - s2[i];
}

static void swaper(t_list *lst) {
    void *buf = NULL;

    buf = lst->data;
    lst->data = lst->next->data;
    lst->next->data = buf;
}

static void sort_by_middle(t_list *list) {
    int size = mx_list_size(list);
    int i = 0;
    int j = 0;
    t_list *buf = list;

    while (j <= size) {
        while (i < size - 1) {
            if (!mx_custom_cmp(buf->data, buf->next->data)
                && mx_middle_cmp(buf->data, buf->next->data) > 0) {
                swaper(buf);
            }
            buf = buf -> next;
            i++;
        }
        i = 0;
        buf = list;
        j++;
    }
}

t_list *mx_sort_result(t_list *lst) {
    int size = mx_list_size(lst);
    int i = 0;
    int j = 0;
    t_list *start = lst;

    while (j <= size) {
        while (i < size - 1) {
            if (mx_custom_cmp(start->data, start->next->data) > 0)
                swaper(start);
            start = start->next;
            i++;
        }
        i = 0;
        start = lst;
        j++;
    }
    sort_by_middle(lst);
    return lst;
}