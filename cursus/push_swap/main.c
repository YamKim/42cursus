#include "./incs/push_swap.h"

int main(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;

	a = gen_stack(argc, argv);
	b = gen_stack(0, 0);

#if 0
	if (ft_checker(&a, &b))
		printf("KO\n");
	else
		printf("OK\n");
#endif
#if 0
	ft_push_one(&a, &b);
	print_stack(a);
	print_stack(b);
#endif
	
#if 1
	ft_push_swap(&a, &b);
#endif
	print_stack(a);
	print_stack(b);
	free_stack_both(a, b);
	return (0);
}
