t_list	*ft_list_sort(t_list *lst, int (*cmp)(int, int))
{
	t_list	*beg;
	t_list	*pos;
	t_list	*min;
	int		tmp;

	pos = lst;
	beg = lst;
	while (lst)
	{
		min = lst;
		pos = lst;
		while (pos)
		{
			if (cmp(min->data, pos->data) == 0)
			{
				min = pos;
			} 
			pos = pos->next;
		}
		tmp = lst->data;
		lst->data = min->data;
		min->data = tmp;
		lst = lst->next;
	}
	return (beg);
}
