#include "../incs/push_swap.h"

void	ft_rrotate_one(t_stack *stack)
{
	t_list	*last;
	t_list	*top;

	top = stack->top;
	if (!is_more_than_one_elem(top))
		return ;
	last = ft_lstlast(top);
	last->prev->next = last->next;
	last->prev = top->prev;
	top->prev = last;
	last->next = top;
	stack->top = last;
	++(stack->cnt[CNT_RR]);
}

