#include "../incs/push_swap.h"

void	free_stack_both(t_stack a, t_stack b)
{
	ft_lstclear(&(a.top), &free);
	ft_lstclear(&(b.top), &free);
}
