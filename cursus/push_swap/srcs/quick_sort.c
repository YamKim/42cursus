#include "../incs/push_swap.h"

void	quick_sort(int *num_arr, int left, int right)
{
	int	i; int	j;
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
