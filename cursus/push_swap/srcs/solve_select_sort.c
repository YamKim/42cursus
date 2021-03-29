#include "../incs/push_swap.h"

static void	set_min_to_top(t_stack *stack, int pivot)
{
	int		int_data;

	int_data = get_int_data(stack->top);
	if (int_data == pivot)
		return ;
	ft_rotate_one(stack);
	set_min_to_top(stack, pivot);	
}

static int	solve_select_sort_recur(t_stack *a, t_stack *b)
{
	if (a->top == NULL)
		return (0);
	set_min_to_top(a, a->min_val);
	ft_push_one(a, b);
	solve_select_sort_recur(a, b);
	return (0);
}

int	solve_select_sort(t_stack *a, t_stack *b)
{
	solve_select_sort_recur(a, b);
	ft_push_all(b, a);

	return (0);
}
