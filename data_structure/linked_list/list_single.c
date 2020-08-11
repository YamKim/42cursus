#include "list_single.h"

t_node	*create_node(void *data)
{
	t_node	*ret;

	if (!(ret = (t_node *)malloc(sizeof(t_node))))
		return (NULL);
	ret->data = data;
	ret->next = NULL;
	return (ret);
}

int		push_back(t_node **head, void *data)
{
	int		ret;
	t_node	*cur;
	t_node	*new_node;

	ret = 0;
	cur = *head;
	while (cur)
	{
		++ret;	
		if (!(cur->next))
		{
			new_node = create_node(data);
			cur->next = new_node;
			break ;
		}
		cur = cur->next;
	}

	return (ret + 1);
}

#include <stdio.h>
int		pop_back(t_node **head)
{
	int		ret;
	t_node	*prev;
	t_node	*cur;
	
	ret = 0;
	cur = *head;
	prev = cur;
	while (cur)
	{
		if (!(cur->next))
		{
			prev->next = cur->next;
			free(cur);
			cur = NULL;
			break ;
		}
		++ret;
		prev = cur;
		cur = cur->next;
	}
	return (ret);
}

int		get_size(t_node *cur)
{
	int		ret;

	ret = 0;
	while (cur)
	{
		++ret;
		cur = cur->next;
	}
	return (ret);
}

void	*get_data(t_node *cur, int idx)
{
	while (cur)
	{
		if (!idx)
			return (cur->data);	
		cur = cur->next;
		--idx;
	}
	return (NULL);
}

int		find_idx(t_node *cur, void *data_ref, int (*cmp)())
{
	int		ret;

	ret = 0;
	while (cur)	
	{
		if (cmp(cur->data, data_ref))
			return (ret);
		cur = cur->next;	
		++ret;
	}
	return (-1);
}
