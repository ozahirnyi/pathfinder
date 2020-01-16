#include "pathfinder.h"

void mx_pop_front_mini(mini_list **head) {
    mini_list *buf = NULL;

    if (head != NULL) {
        buf = (*head)->next;
        free((*head)->path);
        (*head)->path = NULL;
        free((*head)->value);
        (*head)->value = NULL;
        free(*head);
        *head = buf;
    }
}
