#include "../inc/libmx.h"

void	mx_pop_front_mini(mini_list **head) {
    mini_list *buf = NULL;

    buf = (*head)->next;
    free(*head);
    *head = buf;
}