#include "../incs/push_swap.h"

void	ft_push_one(t_list **src, t_list **dst)
{
	t_list	*tmp;

	if (*src == NULL)
	{
		printf("ft_push_one::src_stack is empty\n");
		return ;
	}
	tmp = *src;
	*src = (*src)->next;
	ft_lstadd_front(dst, tmp); 
}

