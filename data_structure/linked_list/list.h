#ifndef LIST_H
# define LIST_H

# include <stdlib.h>

typedef struct	s_node
{
	void			*data;
	struct s_node	*prev;
	struct s_node	*next;
}				t_node;

#endif
