#include "../inc/libmx.h"

t_list	*mx_create_node_count(void *data, int count) {
	t_list *node = (t_list *)malloc(sizeof(t_list));

	node->data = data;
	node->count = count;
	node->next = NULL;

	return node;
}
