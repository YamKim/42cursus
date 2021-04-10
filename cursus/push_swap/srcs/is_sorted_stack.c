#include "../incs/push_swap.h"

int	is_sorted_stack(t_stack *stack, int range, int dir)
{
	t_list	*obs;
	int		pre_num;
	int		cur_num;

	if (stack->top == NULL)
	{
		printf("is_sorted_stack: EMPTY STACK!\n");
		return (0);
	}
	obs = stack->top;
	pre_num = get_int_data(obs);
	obs = obs->next;
	while (obs && range--)
	{
		cur_num = get_int_data(obs);
		if ((dir == DIR_ASCEND) && (pre_num > cur_num))
			return (0);
		if ((dir == DIR_DESCEND) && (pre_num < cur_num))
			return (0);
		obs = obs->next;
		pre_num = cur_num;
	}
	return (1);
}
#if 0
int	is_sorted_stack(t_stack *stack)
{
	t_list	*obs;
	int		pre_num;
	int		cur_num;

	if (stack->top == NULL)
	{
		printf("is_sorted_stack: EMPTY STACK!\n");
		return (0);
	}
	obs = stack->top;
	pre_num = *(int *)(obs->data);
	obs = obs->next;
	while (obs)
	{
		cur_num = *(int *)(obs->data);
		if (pre_num > cur_num)
			return (0);
		obs = obs->next;
		pre_num = cur_num;
	}
	return (1);
}
#endif
