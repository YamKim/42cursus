#include "./incs/push_swap.h"


int main(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;

	a = gen_stack(argc, argv);
	b = gen_stack(0, 0);

	if (ft_checker(&a, &b))
		printf("KO\n");
	else
		printf("OK\n");
	free_stack_both(a, b);
	return (0);
}
