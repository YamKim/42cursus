#include "../incs/push_swap.h"

static int	is_exit_cond_a(t_stack *a, int range)
{
	int	top_num;
	int	second_num;
	
	if (range == 1)
		return (1);
	if (range == 2)
	{
		top_num = get_int_data(a->top);
		second_num = get_int_data(a->top->next);
		if (top_num > second_num)
			ft_swap_one(a);
		return (1);
	}
	return (0);
}

static int	is_exit_cond_b(
			t_stack *b,
			t_stack *a,
			int range)
{
	if (range == 1)
	{
		ft_push_one(b, a);
		return (1);
	}
	return (0);
}

void	move_a_to_b(
		t_stack *a,
		t_stack *b,
		int	range)
{
	t_list	*node;
	int		itr;
	int		pivot;
	int		cnt[3];
	void	move_b_to_a();

	node = a->top;
	range = calc_min(range, a->size);
	set_init_arr(cnt, 3);
	if (is_exit_cond_a(a, range))
		return ;
	itr = -1;
	pivot = get_median_val(*a, range);
	printf("move_by_pivot_range::pivot: %d\n", pivot);
	while (++itr < range)
	{
		if (*(int *)(node->data) >= pivot)
			cnt[CNT_R] += ft_rotate_one(a);
		else
			cnt[CNT_P] += ft_push_one(a, b);
		node = a->top;
	}
	itr = -1;
	printf("move_a_to_b:: cnt[CNT_P]: %d\n", cnt[CNT_P]);
	printf("move_a_to_b:: cnt[CNT_R]: %d\n", cnt[CNT_R]);
	while (++itr < cnt[CNT_R])
		ft_rrotate_one(a);
	move_a_to_b(a, b, cnt[CNT_R]);
	move_b_to_a(b, a, cnt[CNT_P]);
#if 0
	printf("stack A=============================\n");
	print_stack(*a);
	printf("stack B=============================\n");
	print_stack(*b);
#endif
	//exit(0);
}

void	move_b_to_a(
		t_stack *b,
		t_stack *a,
		int	range)
{
	t_list	*node;
	int		itr;
	int		pivot;
	int		cnt[3];
	void	move_a_to_b();

	printf("move_b_to_a:: range: %d\n", range);
	node = b->top;
	range = calc_min(range, b->size);
	set_init_arr(cnt, 3);
	if (is_exit_cond_b(b, a, range))
		return ;
	itr = -1;
	pivot = get_median_val(*b, range);
	printf("move_b_to_a::pivot: %d\n", pivot);
	while (++itr < range)
	{
		if (*(int *)(node->data) >= pivot)
			cnt[CNT_P] += ft_push_one(b, a);
		else
			cnt[CNT_R] += ft_rotate_one(b);
		node = b->top;
	}
	itr = -1;
	printf("move_b_to_a::cnt[CNT_P]: %d\n", cnt[CNT_P]);
	printf("move_b_to_a::cnt[CNT_R]: %d\n", cnt[CNT_R]);
	while (++itr < cnt[CNT_R])
		ft_rrotate_one(b);
	move_a_to_b(a, b, cnt[CNT_P]);
	move_b_to_a(b, a, cnt[CNT_R]);
}

int	ft_push_swap(t_stack *a, t_stack *b)
{
	move_a_to_b(a, b, 10);
//	printf("ft_push_swap::get_median_val: %d\n", get_median_val(*a, 3));
	//solve_select_sort(a, b);
	printf("stack A=============================\n");
	print_stack(*a);
	printf("stack B=============================\n");
	print_stack(*b);
	return (0);
}
