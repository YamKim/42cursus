#include "../incs/push_swap.h"

int	run_inst_part1(t_stack *a, t_stack *b, int inst)
{
	if (inst == INST_SA)
		ft_swap_one(a);
	if (inst == INST_SB)
		ft_swap_one(b);
	if (inst == INST_SS)
		ft_swap_both(a, b);
	if (inst == INST_PA)
		ft_push_one(b, a);
	if (inst == INST_PB)
		ft_push_one(a, b);
	return (0);
}

int	run_inst_part2(t_stack *a, t_stack *b, int inst)
{
	if (inst == INST_RA)
		ft_rotate_one(a);
	if (inst == INST_RB)
		ft_rotate_one(b);
	if (inst == INST_RR)
		ft_rotate_both(a, b);
	if (inst == INST_RRA)
		ft_rrotate_one(a);
	if (inst == INST_RRB)
		ft_rrotate_one(b);
	if (inst == INST_RRR)
		ft_rrotate_both(a, b);
	return (0);
}

#if 1
int	run_inst(
	t_stack *a,
	t_stack *b,
	t_list *inst_list)
{
	int		inst;

	while (inst_list)
	{
		inst = *((int *)inst_list->data);
		run_inst_part1(a, b, inst);
		run_inst_part2(a, b, inst);
		inst_list = inst_list->next;
	}
	return (0);
}
#endif

int	ft_checker(
	t_stack *a,
	t_stack *b)
{
	t_list	*inst_list;

	inst_list = gen_inst_list();

	run_inst(a, b, inst_list);
	if (!is_sorted_stack(a, a->size, DIR_ASCEND))
		return (1);
	return (0);
}
