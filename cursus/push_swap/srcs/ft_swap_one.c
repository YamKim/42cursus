#include "../incs/push_swap.h"

void	ft_swap_one(t_stack *stack)
{
	t_list	*list1;
	t_list	*list2;

	list1 = stack->top;
	if(!is_more_than_one_elem(list1))
		return ;
	list2 = list1->next;
	list1->next = list2->next;
	list2->prev = list1->prev;
	list1->prev = list2;
	list2->next = list1;
	stack->top = list2;
	if ((stack->flag & (NAME_A | PRINT_ON)) == stack->flag)
		ft_putstr_fd("sa\n", STDOUT_FILENO);
	if ((stack->flag & (NAME_B | PRINT_ON)) == stack->flag)
		ft_putstr_fd("sb\n", STDOUT_FILENO);
}
