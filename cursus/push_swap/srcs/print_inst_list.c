#include "../incs/push_swap.h"

static char	*cvt_inst_num_to_char(int inst_num)
{
	if (inst_num == INST_SA)
		return ("sa");
	if (inst_num == INST_SB)
		return ("sb");
	if (inst_num == INST_SS)
		return ("ss");
	if (inst_num == INST_PA)
		return ("pa");
	if (inst_num == INST_PB)
		return ("pb");
	if (inst_num == INST_RA)
		return ("ra");
	if (inst_num == INST_RB)
		return ("rb");
	if (inst_num == INST_RR)
		return ("rr");
	if (inst_num == INST_RRA)
		return ("rra");
	if (inst_num == INST_RRB)
		return ("rrb");
	if (inst_num == INST_RRR)
		return ("rrr");
	return ("NaN");
}

void	print_inst_list(t_list *obs)
{
	int		inst_num;
	char	*inst_char;

	while (obs)
	{
		printf("addr of list: %p\n", obs);
		inst_num = *(int *)(obs->data);
		inst_char = cvt_inst_num_to_char(inst_num);
		printf("res of inst: %s\n", inst_char);
		obs = obs->next;
	}
}
