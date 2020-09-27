#include "ft_list.h"

t_list *ft_list_push_strs(int size, char **strs)
{
	t_list	*ret;
	int		idx;

	idx = 0;
	if ((ret = ft_create_elem(strs[idx])) == 0)
		return (0);

	while (++idx < size)
		ft_list_push_front(&ret, strs[idx]);

	return (ret);
}
