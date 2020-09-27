#include "ft_list.h"

t_list	*g_reverse_list;

t_list	*ft_list_recur(t_list *list)
{
	t_list	*ret;

	if (list->next == NULL)
	{
		g_reverse_list = list;
		return (list);
	}
	ret = ft_list_recur(list->next);
	list->next = NULL;
	return (ret->next = list);
}

void	ft_list_reverse(t_list **begin_list)
{
	ft_list_recur(*begin_list);
	*begin_list = g_reverse_list;
}
