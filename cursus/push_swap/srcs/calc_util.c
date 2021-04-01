#include "../incs/push_swap.h"

int		calc_min(int num1, int num2)
{
	if (num1 > num2)
		return (num2);
	return (num1);
}

void	calc_swap(int *num1, int *num2)
{
	int	tmp;

	tmp = *num1;
	*num1 = *num2;
	*num2 = tmp;
}
