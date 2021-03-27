#include "../incs/push_swap.h"

void	ft_push_both(t_stack *a, t_stack *b)
{
	ft_push_one(a, b);
	ft_push_one(b, a);
}
