#include "../incs/push_swap.h"

void force_finish(t_stack *a, t_stack *b)
{
	if (a != NULL)
		print_stack(*a);
	if (b != NULL)
		print_stack(*b);
	exit(0);
}

static void	move_a_to_b();
static void	move_b_to_a();

static int	is_exit_cond(t_stack *a, t_stack *b, int range)
{
	int	top_num;
	int	second_num;
	
	if (a != NULL && (a->flag & NAME_A))
	{
		if (range <= 1)
			return (1);
		else if (range == 2)
		{
			top_num = get_int_data(a->top);
			second_num = get_int_data(a->top->next);
			if (top_num > second_num)
				ft_swap_one(a);
			return (1);
		}
	}
	if (b != NULL && (b->flag & NAME_B))
	{
		if (range <= 1)
		{
			ft_push_one(b, a);
			return (1);
		}
	}
	return (0);
}

static void	ft_rrotate_loop(t_stack *stack, int itr_range)
{
	int	itr;

	itr = -1;
	while (++itr < itr_range)
		ft_rrotate_one(stack);
}

static void	move_a_to_b(
		t_stack *a,
		t_stack *b,
		int	range)
{
	t_pivot		pivot;
	int			cnt[CNT_SIZE];

	range = calc_min(range, a->size);
	if (is_exit_cond(a, NULL, range))
		return ;
	set_init_arr(cnt, CNT_SIZE);
	pivot = get_tri_division_pivot(*a, range);
	while (range--)
	{
		if (*(int *)(a->top->data) >= pivot.second)
			cnt[CNT_RA] += ft_rotate_one(a);
		else
		{
			cnt[CNT_PB] += ft_push_one(a, b);
			if (*(int *)(b->top->data) >= pivot.first)
				cnt[CNT_RB] += ft_rotate_one(b);
		}
	}
	ft_rrotate_loop(a, cnt[CNT_RA]);
	ft_rrotate_loop(b, cnt[CNT_RB]);
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
	if (is_exit_cond(a, b, range))
		return ;
	set_init_arr(cnt, CNT_SIZE);
	pivot = get_tri_division_pivot(*b, range);
	while (range--)
	{
		if (*(int *)(b->top->data) < pivot.first)
			cnt[CNT_RB] += ft_rotate_one(b);
		else
		{
			cnt[CNT_PA] += ft_push_one(b, a);
			if (*(int *)(a->top->data) < pivot.second)
				cnt[CNT_RA] += ft_rotate_one(a);
		}
	}
	move_a_to_b(a, b, cnt[CNT_RA]);
	ft_rrotate_loop(b, cnt[CNT_RB]);
	move_a_to_b(a, b, cnt[CNT_PA] - cnt[CNT_RA]);
	ft_rrotate_loop(a, cnt[CNT_RA]);
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
