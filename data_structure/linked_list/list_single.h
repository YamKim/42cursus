#ifndef LIST_SINGLE_H
# define LIST_SINGLE_H

# include "list.h"

t_node	*create_node(void *data);
int		push_back(t_node **head, void *data);
int		pop_back(t_node **head);
int		get_size(t_node *cur);
void	*get_data(t_node *cur, int idx);
int		find_idx(t_node *cur, void *data, int (*cmp)());

#endif

