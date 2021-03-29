#include "../incs/push_swap.h"

int	min(int num1, int num2)
{
	if (num1 > num2)
		return (num2);
	return (num1);
}

int	move_by_pivot_range(
	t_stack *src,
	t_stack *dst,
	int pivot,
	int	range)
{
	int		num;
	t_list	*node;
	int		itr;

	node = src->top;
	range = min(range, src->size);
	itr = -1;
	while (++itr < range)
	{
		num = *(int *)(node->data);
		if (num < pivot)
		{
			printf("PUSHPUSH\n");
			ft_push_one(src, dst);
		}
		else
		{
			printf("RROTRROT\n");
			ft_rotate_one(src);
		}
		node = src->top;
	}
	itr = -1;
	while (++itr < src->cnt[CNT_RR])
		ft_rrotate_one(src);
	return (0);
}

int	ft_push_swap(t_stack *a, t_stack *b)
{
	//move_by_pivot_range(a, b, 5, 5);
	solve_select_sort(a, b);

	return (0);
}
