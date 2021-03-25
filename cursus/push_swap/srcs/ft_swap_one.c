#include "../incs/push_swap.h"

void	ft_swap_one(t_list **stack_head)
{
	t_list	*list1;
	t_list	*list2;

	if(!is_more_than_one_elem(*stack_head))
		return ;
	list1 = *stack_head;
	list2 = (*stack_head)->next;
	list1->next = list2->next;
	list2->prev = list1->prev;
	list1->prev = list2;
	list2->next = list1;
	*stack_head = list2;
}

