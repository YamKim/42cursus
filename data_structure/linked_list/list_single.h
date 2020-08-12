#ifndef LIST_SINGLE_H
# define LIST_SINGLE_H

# include "list.h"

enum TYPE {
	TYPE_CHAR,
	TYPE_STR,
	TYPE_INT,
	TYPE_FLOAT
};

t_node	*create_node(void *data);
int		push_back(t_node **lst, void *data);
int		pop_back(t_node **lst);
int		get_size(t_node *cur);
void	*get_data(t_node *cur, int idx);
int		find_idx(t_node *cur, void *data, int (*cmp)());
int		ins_node(t_node **lst, void *data, int idx);
int		del_node(t_node **lst, int idx);
int		list_ins(t_node *lst, void *data, int idx);
void	list_clear(t_node *lst, enum TYPE t);
void	list_free(t_node **lst);

void	list_print(t_node *lst, enum TYPE t);

t_node	*list_sort(t_node *cur, int (*cmp)());
void	list_remove_if(t_node **lst, void *data_ref, int (*cmp)());



#endif

