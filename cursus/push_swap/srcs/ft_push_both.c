#include "../incs/push_swap.h"

void	ft_push_both(t_list **a_head, t_list **b_head)
{
	ft_push_one(a_head, b_head);
	ft_push_one(b_head, a_head);
}
