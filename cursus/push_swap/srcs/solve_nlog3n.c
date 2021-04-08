#include "../incs/push_swap.h"

static void	move_a_to_b();
static void	move_b_to_a();

static void	ft_rrotate_loop(
			t_stack *a,
			t_stack *b,
			int itr_range)
{
	int	itr;

	itr = -1;
	if (a != NULL && b != NULL)
	{
		while (++itr < itr_range)
			ft_rrotate_both(a, b);
	}
	else if (a == NULL)
	{
		while (++itr < itr_range)
			ft_rrotate_one(b);
	}
	else if (b == NULL)
	{
		while (++itr < itr_range)
			ft_rrotate_one(a);
	}
}

static void	move_a_to_b(
			t_stack *a,
			t_stack *b,
			int	range)
{
	t_pivot		pivot;
	int			cnt[CNT_SIZE];

	range = calc_min(range, a->size);
	if (is_exit_cond(a->flag & NAME_A, a, NULL, range))
		return ;
	set_init_arr(cnt, CNT_SIZE);
	pivot = get_tri_division_pivot(*a, range);
	while (range--)
	{
		if (get_int_data(a->top) >= pivot.second)
			cnt[CNT_RA] += ft_rotate_one(a);
		else
		{
			cnt[CNT_PB] += ft_push_one(a, b);
			if (get_int_data(b->top) >= pivot.first)
				cnt[CNT_RB] += ft_rotate_one(b);
		}
	}
	ft_rrotate_loop(a, NULL, cnt[CNT_RA]);
	ft_rrotate_loop(NULL, b, cnt[CNT_RB]);
	move_a_to_b(a, b, cnt[CNT_RA]);
	move_b_to_a(b, a, cnt[CNT_RB]);
	move_b_to_a(b, a, cnt[CNT_PB] - cnt[CNT_RB]);
}

static void	move_b_to_a(
			t_stack *b,
			t_stack *a,
			int	range)
{
	t_pivot		pivot;
	int			cnt[CNT_SIZE];

	range = calc_min(range, b->size);
	if (is_exit_cond(b->flag & NAME_B, a, b, range))
		return ;
	set_init_arr(cnt, CNT_SIZE);
	pivot = get_tri_division_pivot(*b, range);
	while (range--)
	{
		if (get_int_data(b->top) < pivot.first)
			cnt[CNT_RB] += ft_rotate_one(b);
		else
		{
			cnt[CNT_PA] += ft_push_one(b, a);
			if (get_int_data(a->top) < pivot.second)
				cnt[CNT_RA] += ft_rotate_one(a);
		}
	}
	move_a_to_b(a, b, cnt[CNT_PA] - cnt[CNT_RA]);
	ft_rrotate_loop(NULL, b, cnt[CNT_RB]);
	ft_rrotate_loop(a, NULL, cnt[CNT_RA]);
	move_a_to_b(a, b, cnt[CNT_RA]);
	move_b_to_a(b, a, cnt[CNT_RB]);
}

void	solve_nlog3n(t_stack *a, t_stack *b)
{
	//move_a_to_b(a, b, a->size);
	(void)move_a_to_b;
	(void)move_b_to_a;
#if 0
	ft_push_one(a, b);
	ft_push_one(a, b);
	ft_push_one(a, b);
	print_stack(*b);
	printf("START=================================\n");
	move_b_to_a(b, a, b->size);
#endif
#if 1
	move_a_to_b(a, b, a->size);
#endif
#if 0
	print_stack(*a);
	print_stack(*b);
#endif
}
