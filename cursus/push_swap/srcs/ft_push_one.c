#include "../incs/push_swap.h"

int	ft_push_one(t_stack *src, t_stack *dst)
{
	t_list	*tmp;

	if (src->top == NULL)
	{
		ft_putstr_fd("ft_push_one::src_stack is empty\n", STDERR_FILENO);
		return (0);
	}
	tmp = src->top;
	src->top = src->top->next;
	if (src->top != NULL)
		src->top->prev = NULL;
	ft_lstadd_front(&(dst->top), tmp); 
	src->size = ft_lstsize(src->top);
	dst->size = ft_lstsize(dst->top);
	set_min_max_val(src);
	set_min_max_val(dst);
	if ((dst->flag & (NAME_A | PRINT_ON)) == dst->flag)
		ft_putstr_fd("pa\n", STDOUT_FILENO);
	if ((dst->flag & (NAME_B | PRINT_ON)) == dst->flag)
		ft_putstr_fd("pb\n", STDOUT_FILENO);
	return (1);
}

