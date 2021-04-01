#include "../incs/push_swap.h"

void set_init_arr(int arr[], int size)
{
	int	itr;

	itr = -1;
	while (++itr < size)
	{
		arr[itr] = 0;
	}
}
