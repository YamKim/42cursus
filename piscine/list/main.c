#include <stdio.h>
#include "ft_list.h"

void	free_data(void *data)
{
	free(data);
}

void	data_addition(void *data)
{
	*(int *)data = *(int *)data + 1;
}

int		data_cmp(void *data1, void *data2)
{
	if (data1 == data2)
		return (0);
	return (1);
}

int main(void) {
#if 1
	t_list *listEx;

	int *ap; int a = 1; ap = &a;
	listEx = NULL;
//	listEx = ft_create_elem(&a);
	ft_list_push_back(&listEx, ap);

	int *bp; int b = 2; bp = &b;
	//ft_list_push_front(&listEx, &b);
	ft_list_push_back(&listEx, bp);
	int *cp; int c = 3; cp = &c;
	ft_list_push_back(&listEx, cp);
	int *dp; int d = 4; dp = &d;
	ft_list_push_back(&listEx, dp);
	int *ep; int e = 5; ep = &e;
	ft_list_push_back(&listEx, ep);
	//ft_list_push_front(&listEx, cp);
	//printf("addr: %p, data: %d\n", listEx, *(int *)listEx->data);
	//printf("len: %d\n", ft_list_size(listEx));

	//t_list *last = ft_list_last(listEx);
	//printf("addr: %p, data: %d\n", last, *(int *)last->data);

	//int d = 4; 
	//ft_list_push_back(&listEx, &d);
	//printf("addr: %p, data: %d\n", listEx, *(int *)listEx->data);

	//t_list *pick = t_list_at(listEx, 2);
	//printf("addr: %p\n", pick);
	//printf("pick============\n");
	//printf("addr: %p, data: %d\n", pick, *(int *)pick->data);
	//ft_list_reverse(&listEx);
//	printf("len: %d\n", ft_list_size(listEx));
	
	//ft_list_foreach(listEx, data_addition);
	//ft_list_foreach_if(listEx, data_addition, ep, data_cmp);
	t_list *find = ft_list_find(listEx, dp, data_cmp);
	printf("data: %p\n", dp);
	printf("addr: %p, data: %p\n", find, find->data);

#if 1
	printf("original value\n");
	t_list	*pos = listEx;
	while (pos)
	{
		printf("addr: %p, data: %d\n", pos, *(int *)pos->data);
		pos = pos->next;
	}

#if 1
	ft_list_reverse(&listEx);

	printf("reverse value\n");
	pos = listEx;
	while (pos)
	{
		printf("addr: %p, data: %d\n", pos, *(int *)pos->data);
		pos = pos->next;
	}
#endif
#endif
	
#endif
#if 0
	char **strGroup;
	strGroup = (char **)malloc(sizeof(char *) * 4);
	strGroup[0] = (char *)malloc(sizeof(char) * 10);
	strGroup[1] = (char *)malloc(sizeof(char) * 10);
	strGroup[2] = (char *)malloc(sizeof(char) * 10);
	strGroup[3] = (char *)malloc(sizeof(char) * 10);
	//strGroup[0] = "yeham";
	//strGroup[1] = "yeeun";
	//strGroup[2] = "sihwan";
	//strGroup[3] = "dain";
#endif
	
#if 0
	t_list *strList = ft_list_push_strs(4, strGroup);
	t_list *pos = strList; 
	while (pos)
	{
		printf("addr: %p, data: %s\n", pos, (char *)pos->data);
		pos = pos->next;
	}
	ft_list_clear(strList, &free_data);
	printf("addr: %p, data: %s\n", pos, (char *)strList->data);
#endif
	//printf("addr: %p, data: %d\n", pos, *(int *)listEx->data);
	//ft_list_clear(listEx, &free_data);
	//printf("addr: %p, data: %d\n", pos, *(int *)listEx->data);

	return (0);
}
