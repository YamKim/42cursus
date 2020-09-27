#include "ft_list.h"
#include <stdio.h>

#if 1
void	ft_list_push_back(t_list **begin_list, void *data)
{
	if (*begin_list == NULL)
		*begin_list = ft_create_elem(data);
	else
		ft_list_push_back(&((*begin_list)->next), data);
}
#endif

#if 0
void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*last;
	t_list	*pos;

	last = ft_create_elem(data);
	if (*begin_list == NULL)
		*begin_list = last;
	else
	{
		pos = *begin_list;
		while (pos)
		{
			if (pos->next == NULL)
			{
				pos->next = last;  
				break ;
			}	
			pos = pos->next;
			
		}
	}
}
#endif
