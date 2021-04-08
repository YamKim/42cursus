#include "../incs/push_swap.h"

int	ft_rrotate_one(t_stack *stack)
{
	t_list	*last;
	t_list	*top;

	top = stack->top;
	if (!is_more_than_one_elem(top))
		return (1);
	last = ft_lstlast(top);
	last->prev->next = last->next;
	last->prev = top->prev;
	top->prev = last;
	last->next = top;
	stack->top = last;
	if ((stack->flag & (NAME_A | PRINT_ON)) == stack->flag)
		ft_putstr_fd("rra\n", STDOUT_FILENO);
	if ((stack->flag & (NAME_B | PRINT_ON)) == stack->flag)
		ft_putstr_fd("rrb\n", STDOUT_FILENO);
	return (1);
}

