#include "ft_list.h"

t_list	*t_list_at(t_list *begin_list, unsigned int nbr)
{
	if (nbr == 0)
		return (begin_list);
	else
		return (t_list_at(begin_list->next, nbr - 1));
	return (NULL);
}

#if 0
t_list	*t_list_at(t_list *begin_list, unsigned int nbr)
{
	while (begin_list)
	{
		if (!(nbr--))
			return (begin_list);
		begin_list = begin_list->next;
	}
	return (NULL);
}
#endif
