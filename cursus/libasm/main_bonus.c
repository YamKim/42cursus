#include "./incs/libasm.h"
/*
** Useful macro
*/
# define ATOI_BASE(s, b)	i = ft_atoi_base(s, b); printf("`%s`[%s] = %d\n", s, b, i);

/*
** print a list elements one by line
*/
void
	printf_list(t_list *list)
{
	while (list)
	{
		printf("; %s\n", (char *)list->data);
		list = list->next;
	}
}

/*
** free a whole list and it's data field
*/
void
	ft_lstclear(t_list **list)
{
	t_list	*tmp;

	while (*list)
	{
		tmp = (*list)->next;
		if ((*list)->data)
			free((*list)->data);
		free(*list);
		*list = tmp;
	}
}

void ref_ft_list_push_front(t_list **begin_list, void *data)
{
	if (begin_list == NULL)
		return ;
	t_list *new = malloc(sizeof(t_list));
	if (new == NULL)
		return ;
	new->data = data;
	new->next = *begin_list;
	*begin_list = new;
}

static int compare(void *a, void *ref)
{
    return *(int*)a - *(int*)ref;
}

static void free_fct(void *data)
{
    free(data);
}

/*
** Start !
*/
int		main(void)
{
	int	i = 0;
	(void)i;

	t_list	list;
	list.data = strdup("toto");
	list.next = NULL;
	t_list	*push_list = &list;
	//printf("%p\n", &list);
	//ref_ft_list_push_front(&push_list, (void *)ft_strdup("tata"));
	ft_list_push_front(&push_list, (void *)ft_strdup("tata"));
	ft_list_push_front(&push_list, (void *)ft_strdup("tltl"));
	ft_list_push_front(&push_list, (void *)ft_strdup("tete"));
	ft_list_push_front(&push_list, (void *)ft_strdup("tutu"));

	int len = ft_list_size(push_list);
	printf("size: %d\n", len);
	printf_list(push_list);
	//printf("ft_list_remove_if result: %d\n", ft_list_remove_if(&push_list, ft_strdup("tata"), compar, free_fct)); 
	printf("ft_list_remove_if result: %d\n", ft_list_remove_if(&push_list, ft_strdup("toto"), compare, free_fct)); 

	return (0);
}
