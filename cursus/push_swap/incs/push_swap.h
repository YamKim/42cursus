#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

# include <stdio.h>

# define TRUE 1
# define FALSE 0
# define INF 987654321

# define INST_NAN 0
# define INST_SA 1 << 1
# define INST_SB 1 << 2
# define INST_SS 1 << 3
# define INST_PA 1 << 4
# define INST_PB 1 << 5
# define INST_RA 1 << 6
# define INST_RB 1 << 7
# define INST_RR 1 << 8
# define INST_RRA 1 << 9
# define INST_RRB 1 << 10
# define INST_RRR 1 << 11

# define CNT_SIZE 4
# define CNT_S 0
# define CNT_P 1
# define CNT_R 2
# define CNT_RR 3

typedef struct	s_stack
{
	t_list		*top;
	int			size;
//	int			cnt[CNT_SIZE];
	int			min_val;
	int			max_val;
}				t_stack;


int		is_more_than_one_elem(t_list *list_head);

void	ft_swap_one(t_stack *stack); void	ft_swap_both(
		t_stack *a,
		t_stack *b);

int		ft_push_one(
		t_stack *src,
		t_stack *dst);
void	ft_push_both(
		t_stack *a,
		t_stack *b);

void	ft_push_all(
		t_stack *src,
		t_stack *dst);

int		ft_rotate_one(t_stack *stack);
void	ft_rotate_both(
		t_stack *a,
		t_stack *b);

int		ft_rrotate_one(t_stack *stack);
void	ft_rrotate_both(
		t_stack *a,
		t_stack *b);

int		ft_checker(
		t_stack *a,
		t_stack *b);
int		is_sorted_stack(t_stack *stack);

t_list	*gen_init_nbr_list(
		int argc,
		char *argv[]);
t_list	*gen_inst_list();
t_stack	gen_stack(
		int list_size,
		char **argv);

int		get_next_line(char **line);

void	print_list(t_list *list_head);
void	print_inst_list(t_list *list_head);
void	print_stack(t_stack stack);

void	free_stack_both(t_stack a, t_stack b);





int		ft_push_swap(t_stack *a, t_stack *b);
void	set_min_max_val(t_stack *stack);
int		get_int_data(t_list *list);

int		get_median_val(t_stack stack, int range);
int		solve_select_sort(t_stack *a, t_stack *b);

void	set_init_arr(int arr[], int size);

// calc_util.c
int		calc_min(int num1, int num2);
void	calc_swap(int *num1, int *num2);
#endif
