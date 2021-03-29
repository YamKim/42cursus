#include "../incs/push_swap.h"

void	set_min_max_val(t_stack *stack)
{
	int		min_val;
	int		max_val;
	t_list	*obs;

	if (stack->top == NULL)
		return ;
	obs = stack->top;
	min_val = get_int_data(obs);
	max_val = get_int_data(obs);
	while (obs)
	{
		if (min_val > get_int_data(obs))
			min_val = get_int_data(obs);
		if (max_val < get_int_data(obs))
			max_val = get_int_data(obs);
		obs = obs->next;
	}
	stack->min_val = min_val;
	stack->max_val = max_val;
}
