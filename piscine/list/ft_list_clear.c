#include "ft_list.h"

void	ft_list_clear(t_list *begin_list, void(*free_fct)(void *))
{
	if (begin_list == NULL)
		return ;
	ft_list_clear(begin_list->next, free_fct);
	free_fct(begin_list->data);
	free(begin_list);
}

#if 0
void	ft_list_clear(t_list *begin_list, void(*free_fct)(void *))
{
	t_list	*tmp;

	if (free_fct == NULL)
		return ;

	while (begin_list)
	{
		tmp = begin_list;
		begin_list = begin_list->next;
		free_fct(tmp->data);
		free(tmp);
	}
}
#endif
