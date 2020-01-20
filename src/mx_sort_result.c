#include "pathfinder.h"

static int mx_custom_cmp(const int *s1, const int *s2) {
    int finishlen = mx_strlen(s1) - 1;
    int finishlen1 = mx_strlen(s2) - 1;

    if (s1[0] != s2[0])
        return s1[0] - s2[0];
    else if (s1[finishlen] != s2[finishlen1])
        return s1[finishlen] - s2[finishlen1];
    else
        return 0;
}

static int mx_middle_cmp(const int *s1, const int *s2) {
    int i;

    i = 0;
    while (s1[i + 1] != '\0' && s2[i + 1] != '\0' && s1[i] == s2[i])
        i++;
    return s1[i] - s2[i];
}

static void swaper(result_list *lst) {
    void *buf = NULL;

    buf = lst->path;
    lst->path = lst->next->path;
    lst->next->path = buf;
}

static void sort_by_middle(result_list *list) {
    int size = mx_list_size(list);
    int i = 0;
    int j = 0;
    result_list *buf = list;

    while (j <= size) {
        while (i < size - 1) {
            if (!mx_custom_cmp(buf->path, buf->next->path)
                && mx_middle_cmp(buf->path, buf->next->path) > 0) {
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

void mx_sort_result(result_list *lst) {
    int size = mx_list_size(lst);
    int i = 0;
    int j = 0;
    result_list *start = lst;

    while (j <= size) {
        while (i < size - 1) {
            if (mx_custom_cmp(start->path, start->next->path) > 0)
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
