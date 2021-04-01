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


void	quick_sort(int *num_arr, int left, int right)
{
	int	i;
	int	j;
	int	pivot;

	i = left;
	j = right;
	pivot = num_arr[(left + right) / 2];
	while (i <= j)
	{
		while (num_arr[i] < pivot)
			++i;
		while (num_arr[j] > pivot)
			--j;
		if (i <= j)
		{
			calc_swap(&num_arr[i], &num_arr[j]);
			++i;
			--j;
		}
	}
	if (left < j)
		quick_sort(num_arr, left, j);
	if (right > i)
		quick_sort(num_arr, i, right);
}

int	get_median_val(t_stack stack, int range)
{
	int	ret;
	int	*num_arr;

	range = calc_min(range, stack.size);
	num_arr = cvt_stack_data_to_arr(&stack, range);
	if (num_arr == NULL)
		return (-INF);
	ret = 0;
	quick_sort(num_arr, 0, range - 1);
	ret = num_arr[(int)(range / 2)];
	free(num_arr);
	return (ret);
}
