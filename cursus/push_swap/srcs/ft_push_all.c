#include "../incs/push_swap.h"

void	ft_push_all(t_stack *src, t_stack *dst)
{
	if (src->top == NULL)
		return ;
	ft_push_one(src, dst);
	ft_push_all(src, dst);
}
