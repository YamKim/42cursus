#include "../incs/push_swap.h"

void	print_stack(t_stack stack)
{
	if (stack.flag & NAME_A)
		printf("print_stack::TOP of A===========\n");
	if (stack.flag & NAME_B)
		printf("print_stack::TOP of B===========\n");
	if (stack.top == NULL)
		return ;
	print_list(stack.top);
	printf("print_stack::size: %d\n", stack.size);
	printf("print_stack::min_val: %d\n", stack.min_val);
	printf("print_stack::max_val: %d\n\n", stack.max_val);
}


