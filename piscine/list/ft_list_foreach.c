#include "ft_list.h"

void	ft_list_foreach(tlist *begin_list, void (*f)(void *))
{
	if (begin_list == NULL)
		return ;
	(*f)(begin_list->data);
	ft_list_foreach(begin_list, f);	
}
