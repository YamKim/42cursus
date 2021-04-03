#include "../incs/push_swap.h"

int main(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;

	//*argv = *argv + 1;
	a = gen_stack(argc - 1, argv + 1, NAME_A | PRINT_OFF);
	if (a.top == NULL)
	{
		ft_putstr_fd("ERROR\n", STDERR_FILENO);
		return (0);
	}
	b = gen_stack(0, 0, NAME_B | PRINT_OFF);
	if (ft_checker(&a, &b))
		ft_putstr_fd("KO\n", STDOUT_FILENO);
	else
		ft_putstr_fd("OK\n", STDOUT_FILENO);
	free_stack_both(a, b);
	return (0);
}
