#include "../incs/push_swap.h"

int	ft_push_one(t_stack *src, t_stack *dst)
{
	t_list	*tmp;

	if (src->top == NULL)
	{
		printf("ft_push_one::src_stack is empty\n");
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
	return (1);
}

