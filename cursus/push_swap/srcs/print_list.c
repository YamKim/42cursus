#include "../incs/push_swap.h"

void	print_list(t_list *top)
{
	while (top)
	{
		printf("addr of prev: %p\n", top->prev);
		printf("addr of curr: %p\n", top);
		printf("addr of next: %p\n", top->next);
		printf("data: %d\n\n", *(int *)(top->data));
		//printf("list_content: %d\n", *(int *)(top->content));
		//printf("addr of list_content: %p\n\n", top->content);
		top = top->next;
	}
}
