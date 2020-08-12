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

int		push_back(t_node **lst, void *data)
{
	int		ret;
	t_node	*cur;
	t_node	*new_node;

	ret = 0;
	cur = *lst;
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

int		pop_back(t_node **lst)
{
	int		ret;
	t_node	*prev;
	t_node	*cur;
	
	ret = 0;
	cur = *lst;
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

int		ins_node(t_node **lst, void *data, int idx)
{
	t_node	*cur;
	t_node	*new_node;

	cur = *lst;
	while (cur)
	{
		if (!(--idx))
		{
			new_node = create_node(data);
			new_node->next = cur->next;
			cur->next = new_node;
			return (1);
		}
		cur = cur->next;
	}

	return (0);
}

int		del_node(t_node **lst, int idx)
{
	t_node	*prev;
	t_node	*cur;

	cur = *lst;
	prev = cur;
	while (cur)
	{
		if (!(idx--))
		{
			prev->next = cur->next;
			free(cur);
			cur = NULL;
			return (1);
		}
		prev = cur;
		cur = cur->next;
	}
	return (0);
}

int		list_ins(t_node *lst, void *data, int idx)
{
	t_node	*cur;

	cur = lst;
	while (cur)
	{
		if (!(idx--))
		{
			cur->data = data; 
			return (1);
		}
		cur = cur->next;
	}
	return (0);
}

void	list_clear(t_node *lst, enum TYPE t)
{
	t_node	*cur;

	cur = lst;
	while (cur)
	{
		if(t == TYPE_INT)
			*(int *)(cur->data) = 0;
		else if (t == TYPE_CHAR)
			*(char *)(cur->data) = '\0';
		else if (t == TYPE_STR)
			cur->data = 0;
		cur = cur->next;
	}
}

void	list_free(t_node **lst)
{
	t_node	*cur;
	t_node	*del_node;

	cur = *lst;
	while (cur)
	{
		del_node = cur;	
		cur = cur->next;
		free(del_node);
		del_node = NULL;
	}
}

/* linked list technic */
t_node	*list_sort(t_node *cur, int (*cmp)())
{
	t_node	*ret;
	t_node	*pos;
	t_node	*min_node;
	void	*tmp;

	ret = cur;
	while (cur)
	{
		min_node = cur;
		pos = cur;
		while (pos)
		{
			if(cmp(min_node->data, pos->data))
				min_node = pos;
			pos = pos->next;
		}
		tmp = cur->data;
		cur->data = min_node->data;
		min_node->data = tmp;
		cur = cur->next;
	}
	return (ret);
}

void	list_remove_if(t_node **lst, void *data_ref, int (*cmp)())
{
	t_node	*tmp;
	t_node	*prev;
	t_node	*cur;

	while (*lst && !cmp((*lst)->data, data_ref))
	{
		tmp = *lst;
		*lst = (*lst)->next;
		free(tmp);
	}
	prev = *lst;
	while (prev && prev->next)
	{
		cur = prev->next;
		if (!cmp(cur->data, data_ref))
		{
			tmp = cur;
			prev->next = cur->next;
			free(tmp);
		}
		else
			prev = cur;
	}
}

#include <stdio.h>
void	list_print(t_node *lst, enum TYPE t)
{
	t_node	*cur;

	cur = lst;
	while (cur)
	{
		printf("addr of node: %p\n", cur);
		if (t == TYPE_INT)
			printf("data of node: %d\n", *(int *)(cur->data));
		else if (t == TYPE_CHAR)
			printf("data of node: %c\n", *(char *)(cur->data));
		else if (t == TYPE_STR)
			printf("data of node: %s\n", (char *)(cur->data));
		cur = cur->next;
	}
}

