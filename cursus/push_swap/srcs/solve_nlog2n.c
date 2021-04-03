#include "../incs/push_swap.h"

static void	move_b_to_a();
static void	move_a_to_b();

static int	is_exit_cond_a(t_stack *a, int range)
{
	int	top_num;
	int	second_num;
	
	if (range <= 1)
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
	if (range <= 1)
	{
		ft_push_one(b, a);
		return (1);
	}
	return (0);
}

static void	move_a_to_b(
		t_stack *a,
		t_stack *b,
		int	range)
{
	int			itr;
	t_pivot		pivot;
	int			cnt[CNT_SIZE];

	range = calc_min(range, a->size);
	if (is_exit_cond_a(a, range))
		return ;
	set_init_arr(cnt, CNT_SIZE);
	itr = -1;
	pivot = get_median_pivot(*a, range);
	while (++itr < range)
	{
		if (*(int *)(a->top->data) >= pivot.median)
			cnt[CNT_RA] += ft_rotate_one(a);
		else
			cnt[CNT_PB] += ft_push_one(a, b);
	}
	itr = -1;
	while (++itr < cnt[CNT_RA])
		ft_rrotate_one(a);
	move_a_to_b(a, b, cnt[CNT_RA]);
	move_b_to_a(b, a, cnt[CNT_PB]);
}

static void	move_b_to_a(
			t_stack *b,
			t_stack *a,
			int	range)
{
	int			itr;
	t_pivot		pivot;
	int			cnt[CNT_SIZE];

	range = calc_min(range, b->size);
	if (is_exit_cond_b(b, a, range))
		return ;
	set_init_arr(cnt, 3);
	itr = -1;
	pivot = get_median_pivot(*b, range);
	while (++itr < range)
	{
		if (*(int *)(b->top->data) >= pivot.median)
			cnt[CNT_PA] += ft_push_one(b, a);
		else
			cnt[CNT_RB] += ft_rotate_one(b);
	}
	itr = -1;
	while (++itr < cnt[CNT_RB])
		ft_rrotate_one(b);
	move_a_to_b(a, b, cnt[CNT_PA]);
	move_b_to_a(b, a, cnt[CNT_RB]);
}

void		solve_nlog2n(t_stack *a, t_stack *b)
{
	move_a_to_b(a, b, a->size);
}
