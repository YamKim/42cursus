#include "../incs/push_swap.h"


int	ft_push_swap(t_stack *a, t_stack *b)
{
	//solve_nlog2n(a, b);
	solve_nlog3n(a, b);
//	printf("ft_push_swap::get_median_val: %d\n", get_median_val(*a, 3));
	//solve_select_sort(a, b);
#if 0
	printf("stack A=============================\n");
	print_stack(*a);
	printf("stack B=============================\n");
	print_stack(*b);
#endif
	return (0);
}
