#include "../incs/push_swap.h"

static int	*cvt_stack_data_to_arr(
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

t_pivot		get_tri_division_pivot(t_stack stack, int range)
{
	t_pivot	ret;
	int		*num_arr;

	range = calc_min(range, stack.size);
	num_arr = cvt_stack_data_to_arr(&stack, range);
	if (num_arr == NULL)
	{
		ret.first = -INF;	
		ret.second = -INF;	
		return (ret);
	}
	quick_sort(num_arr, 0, range - 1);
	ret.first = num_arr[(int)(range / 3)];
	ret.second = num_arr[(int)(2 * range / 3)];
	free(num_arr);
	return (ret);
}
