#include "../incs/push_swap.h"

void	ft_rotate_one(t_list **stack_head)
{
	t_list	*last;

	if (!is_more_than_one_elem(*stack_head))
		return ;
	last = ft_lstlast(*stack_head);
	last->prev->next = last->next;
	last->prev = (*stack_head)->prev;
	(*stack_head)->prev = last;
	last->next = *stack_head;
	*stack_head = last;
}

