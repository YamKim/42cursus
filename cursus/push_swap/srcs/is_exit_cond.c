#include "../incs/push_swap.h"

static int	optimize_tri_elements_a(t_stack *a)
{
	int	*arr;

	arr = cvt_stack_data_to_arr(a, 3);
	if (arr[0] > arr[1] && arr[0] < arr[2])
		ft_swap_one(a);
	else if (arr[0] < arr[1] && arr[0] > arr[2])
		ft_rrotate_one(a);
	else if (arr[1] < arr[0] && arr[1] > arr[2])
	{
		ft_swap_one(a);
		ft_rrotate_one(a);
	}
	else if (arr[2] < arr[0] && arr[2] > arr[1])
		ft_rotate_one(a);
	else if (arr[2] > arr[0] && arr[2] < arr[1])
	{
		ft_swap_one(a);
		ft_rotate_one(a);
	}
	return (1);
}

static int	optimize_tri_elements_b(t_stack *b)
{
	int	*arr;

	arr = cvt_stack_data_to_arr(b, 3);
	if (arr[0] > arr[1] && arr[0] < arr[2])
		ft_rrotate_one(b);
	else if (arr[0] < arr[1] && arr[0] > arr[2])
		ft_swap_one(b);
	else if (arr[1] > arr[0] && arr[1] < arr[2])
	{
		ft_swap_one(b);
		ft_rrotate_one(b);
	}
	else if (arr[2] < arr[0] && arr[2] > arr[1])
	{
		ft_swap_one(b);
		ft_rotate_one(b);
	}
	else if (arr[2] > arr[0] && arr[2] < arr[1])
		ft_rotate_one(b);
	return (1);
}

static int	is_exit_cond_a(t_stack *a, int range)
{
	int	top_num;
	int	second_num;

	if (range <= 1)
		return (1);
	else if (range == 2)
	{
		return (0);
		top_num = get_int_data(a->top);
		second_num = get_int_data(a->top->next);
		if (top_num > second_num)
			ft_swap_one(a);
		return (1);
	}
	else if (range == 3)
	{
		return (0);
		return (optimize_tri_elements_a(a));
	}
	return (0);
}

static int	is_exit_cond_b(t_stack *b, t_stack *a, int range)
{
	int	top_num;
	int	second_num;
	if (range <= 1)
	{
		ft_push_one(b, a);
		return (1);
	}
	else if (range == 2)
	{
		top_num = get_int_data(b->top);
		second_num = get_int_data(b->top->next);
		if (top_num < second_num)
			ft_swap_one(b);
		ft_push_one(b, a);
		ft_push_one(b, a);
		return (1);
	}
	else if (range == 3)
	{
		return (0);
		return (optimize_tri_elements_b(b));
	}
	return (0);
}

int	is_exit_cond(
	int stack_name,
	t_stack *a,
	t_stack *b,
	int range)
{
	if (stack_name == NAME_A)
		return (is_exit_cond_a(a, range));
	if (stack_name == NAME_B)
		return (is_exit_cond_b(b, a, range));
	return (0);
}
