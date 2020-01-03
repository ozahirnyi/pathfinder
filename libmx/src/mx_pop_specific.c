#include "../inc/libmx.h"

void    mx_pop_specific(mini_list **list, int n) {
    mini_list *head = *list;
    mini_list *temp = NULL;

    if (n == 0) {
        temp = head->next;
        free(head);
        *list = temp;
    }
    else {
        for (int i = 0; i < n - 1; i++) {
            if (head->next == NULL)
                return;
            head = head->next;
        }
        temp = head->next;
        head->next = temp->next;
        free(temp);
    }
}