#include "../incs/push_swap.h"

void	ft_swap_both(t_list *a_head, t_list *b_head)
{
	ft_swap_one(&a_head);
	ft_swap_one(&b_head);
}
