#include "../incs/push_swap.h"

int main(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;

	a = gen_stack(argc - 1, argv + 1, NAME_A | PRINT_ON);
	if (a.top == NULL)
	{
		ft_putstr_fd("ERROR\n", 2);
		return (0);
	}
	b = gen_stack(0, 0, NAME_B | PRINT_ON);
	ft_push_swap(&a, &b);
	free_stack_both(a, b);
	return (0);
}
