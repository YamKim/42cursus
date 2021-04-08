#include "../incs/push_swap.h"

int	*cvt_stack_data_to_arr(
	t_stack *stack,
	int range)
{
	t_list	*obs;
	int		*ret;
	int		idx;

	ret = (int *)malloc(sizeof(int) * range);	
	if (!ret)
		return (NULL);
	obs = stack->top;
	idx = -1;
	while (obs && ++idx < range)
	{
		ret[idx] = get_int_data(obs);
		obs = obs->next;
	}
	return (ret);
}


