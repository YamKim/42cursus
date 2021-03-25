#include "../incs/push_swap.h"

void	print_list(t_list *list_head)
{
	while (list_head)
	{
		printf("addr of prev: %p\n", list_head->prev);
		printf("addr of curr: %p\n", list_head);
		printf("addr of next: %p\n", list_head->next);
		printf("data of list: %d\n\n", *(int *)(list_head->content));
		//printf("list_content: %d\n", *(int *)(list_head->content));
		//printf("addr of list_content: %p\n\n", list_head->content);
		list_head = list_head->next;
	}
}
