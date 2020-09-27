#include "ft_list.h"

t_list	*ft_list_last(t_list *begin_list)
{
	if (begin_list->next == NULL)
		return (begin_list);
	else
		return (ft_list_last(begin_list->next));
	return (NULL);
}


#if 0
t_list	*ft_list_last(t_list *begin_list)
{
	while (begin_list)
	{
		if (begin_list->next == NULL)
			return (begin_list);
		begin_list = begin_list->next;
	}
	return (NULL);
}
#endif
