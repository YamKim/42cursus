#include "../incs/push_swap.h"

void	print_stack(t_stack stack)
{
	printf("print_stack::TOP============\n");
	print_list(stack.top);
	printf("print_stack::size: %d\n\n", stack.size);
}


