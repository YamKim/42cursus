#include "../incs/push_swap.h"

int	ft_rotate_one(t_stack *stack)
{
	t_list	*last;
	t_list	*top;
	t_list	*list2;

	top = stack->top;
	if (!is_more_than_one_elem(top))
		return (0);
	list2 = top->next;
	last = ft_lstlast(top);
	top->next = last->next;
	top->prev = last;
	last->next = top;
	top = list2;
	stack->top = top;
	return (1);
}

