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

int		get_size(t_node *head)
{
	int		ret;
	t_node	*cur;

	ret = 0;
	cur = head;
	while (cur)
	{
		++ret;
		cur = cur->next;
	}
	return (ret);
}

int		get_data(t_node *head, int idx)
{
	t_node	*cur;

	while (cur)
	{
		
		cur = cur->next;
		--idx;
	}
}
