#include "../incs/push_swap.h"

int	is_more_than_one(t_list *stack_head)
{
	if (!stack_head || !(stack_head->next))
	{
		printf("ft_swap_one::stack_has no or one elements\n");
		return (0);
	}
	return (1);
}
