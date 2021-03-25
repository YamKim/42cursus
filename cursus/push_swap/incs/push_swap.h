#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

# include <stdio.h>

void	print_list(t_list *list_head);

int		is_more_than_one_elem(t_list *stack_head);

void	ft_swap_one(t_list **stack_head);
void	ft_swap_both(t_list *a_head, t_list *b_head);
void	ft_push_one(t_list **src, t_list **dst);
void	ft_push_both(t_list **a_head, t_list **b_head);
void	ft_rotate_one(t_list **stack_head);
void	ft_rotate_both(t_list **a_head, t_list **b_head);
#endif
