#include "../incs/push_swap.h"

t_stack	gen_stack(int list_size, char **list_data)
{
	t_stack	ret;
	int		itr;

	itr = -1;
#if 0
	while (++itr < CNT_SIZE)
		ret.cnt[itr] = 0;
#endif
	ret.top = gen_init_nbr_list(list_size, list_data);
	ret.size = ft_lstsize(ret.top);
	set_min_max_val(&ret);
	return (ret);
}
