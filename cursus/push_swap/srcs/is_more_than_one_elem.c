#include "../incs/push_swap.h"

int	is_more_than_one_elem(t_list *list_head)
{
	if (!list_head || !(list_head->next))
	{
		//printf("is_more_than_one_elem::stack_has no or one elements\n");
		return (0);
	}
	return (1);
}
