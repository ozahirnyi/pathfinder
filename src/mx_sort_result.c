#include "pathfinder.h"

static int mx_custom_cmp(const int *s1, const int *s2) {
    int len;
    int len1;

    for (len = 0; s1[len] < -2 || s1[len] > -1; len++);
    len -= 1;
    for (len1 = 0; s2[len1] < -2 || s2[len1] > -1; len1++);
    len1 -= 1;
    if (s1[len] != s2[len1])
        return s1[len] - s2[len1];
    else if (s1[0] != s2[0])
        return s1[0] - s2[0];
    else
        return 0;
}

static int mx_middle_cmp(const int *s1, const int *s2) {
    int len;
    int len1;

    for (len = 0; s1[len] < -2 || s1[len] > -1; len++);
    for (len1 = 0; s2[len1] < -2 || s2[len1] > -1; len1++);
    while ((s1[len - 1] >= 0) && (s2[len1 - 1] >= 0)
            && s1[len] == s2[len1]) {
        len--;
        len1--;
    }
    return s1[len] - s2[len1];
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
            buf = buf->next;
            i++;
        }
        i = 0;
        buf = list;
        j++;
    }
}

void mx_sort_result(t_list *lst) {
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
}
