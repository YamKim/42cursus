#include "../incs/push_swap.h"

static void	move_a_to_b();
//static void	move_b_to_a();

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
#if 0
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
#endif

static void	move_a_to_b(
		t_stack *a,
		t_stack *b,
		int	range)
{
	t_list		*node;
	int			itr;
	t_pivot		pivot;
	int			cnt[CNT_SIZE];

	node = a->top;
	range = calc_min(range, a->size);
	set_init_arr(cnt, CNT_SIZE);
	if (is_exit_cond_a(a, range))
		return ;
	itr = -1;
	pivot = get_tri_division_pivot(*a, range);
	while (++itr < range)
	{
		if (*(int *)(node->data) >= pivot.second)
			cnt[CNT_RA] += ft_rotate_one(a);
		else
		{
			cnt[CNT_PB] += ft_push_one(a, b);
			if (*(int *)(b->top->data) >= pivot.first)
				cnt[CNT_RB] += ft_rotate_one(b);
		}
		node = a->top;
	}
	printf("cnt[CNT_RB]: %d\n", cnt[CNT_RB]);
	itr = -1;
	while (++itr < cnt[CNT_RA])
		ft_rrotate_one(a);
	itr = -1;
	while (++itr < cnt[CNT_RB])
		ft_rrotate_one(b);
	//move_a_to_b(a, b, cnt[CNT_RA]);
//	move_a_to_b(a, b, cnt[CNT_R]);
//	move_b_to_a(b, a, cnt[CNT_P]);
}

#if 0
static void	move_b_to_a(
			t_stack *b,
			t_stack *a,
			int	range)
{
	t_list		*node;
	int			itr;
	t_pivot		pivot;
	int			cnt[3];

	node = b->top;
	range = calc_min(range, b->size);
	set_init_arr(cnt, 3);
	if (is_exit_cond_b(b, a, range))
		return ;
	itr = -1;
	pivot = get_tri_division_pivot(*b, range);
	while (++itr < range)
	{
		if (*(int *)(node->data) >= pivot.first)
			cnt[CNT_P] += ft_push_one(b, a);
		else
			cnt[CNT_R] += ft_rotate_one(b);
		node = b->top;
	}
	itr = -1;
	while (++itr < cnt[CNT_R])
		ft_rrotate_one(b);
	move_a_to_b(a, b, cnt[CNT_P]);
	move_b_to_a(b, a, cnt[CNT_R]);
}
#endif

void	solve_nlog3n(t_stack *a, t_stack *b)
{
	move_a_to_b(a, b, a->size);
	print_stack(*a);
	print_stack(*b);
	//move_b_to_a(b, a, a->size);
}
