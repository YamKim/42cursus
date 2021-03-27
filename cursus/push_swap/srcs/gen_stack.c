#include "../incs/push_swap.h"

t_stack	gen_stack(int list_size, char **list_data)
{
	t_stack	ret;

	ret.top = gen_init_nbr_list(list_size, list_data);
	ret.size = ft_lstsize(ret.top);
	return (ret);
}
