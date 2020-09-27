#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	if (begin_list == NULL)
		return (0);
	return (1 + ft_list_size(begin_list->next));
}
#if 0
int	ft_list_size(t_list *begin_list)
{
	int	ret;
	
	ret = 0;
	while (begin_list)
	{
		++ret;
		begin_list = begin_list->next;
	}

	return (ret);
}
#endif
