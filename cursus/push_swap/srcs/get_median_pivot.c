#include "../incs/push_swap.h"

t_pivot		get_median_pivot(t_stack stack, int range)
{
	t_pivot	ret;
	int		*num_arr;

	range = calc_min(range, stack.size);
	num_arr = cvt_stack_data_to_arr(&stack, range);
	if (num_arr == NULL)
	{
		ret.median = -INF;
		return (ret);
	}
	quick_sort(num_arr, 0, range - 1);
	ret.median = num_arr[(int)(range / 2)];
	free(num_arr);
	return (ret);
}
