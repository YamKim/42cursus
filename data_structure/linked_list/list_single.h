#ifndef LIST_SINGLE_H
# define LIST_SINGLE_H

# include "list.h"

t_node	*create_node(void *data);
int		push_back(t_node **head, void *data);
int		get_size(t_node *head);

#endif

