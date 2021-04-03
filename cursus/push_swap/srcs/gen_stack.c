#include "../incs/push_swap.h"

t_stack	gen_stack(int list_size, char **list_data, int flag)
{
	t_stack	ret;
	int		itr;

	itr = -1;
#if 0
	while (++itr < CNT_SIZE)
		ret.cnt[itr] = 0;
#endif
	ret.flag = flag;
	ret.top = gen_init_nbr_list(list_size, list_data);
	ret.size = list_size;
	if (ret.top == NULL)
		return (ret);
	set_min_max_val(&ret);
	return (ret);
}
