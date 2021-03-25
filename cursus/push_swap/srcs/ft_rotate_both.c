#include "../incs/push_swap.h"

void	ft_rotate_both(t_list **a_head, t_list **b_head)
{
	ft_rotate_one(a_head);
	ft_rotate_one(b_head);
}
