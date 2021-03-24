#include "./libft/libft.h"
#include <stdio.h>

// > ./checker 3 2 1 0

int	error_case()
{
	return (0);
}

int	is_int_range(char *str, int num)
{
	int	zero_case;

	zero_case = str[0] == '0' && str[1] == '\0';
	if (!zero_case && num == 0)
		return (0);
	return (1);
}

int	is_more_than_one(t_list *stack_head)
{
	if (!stack_head || !(stack_head->next))
	{
		printf("ft_swap_one::stack_has no or one elements\n");
		return (0);
	}
	return (1);
}

int	is_right_argv(int *num_arr, char **argv)
{
	int	idx;
	int	num;

	idx = 0;
	while (argv[++idx])
	{
		num = ft_atoi(argv[idx]);
		if (!is_int_range(argv[idx], num))
		{
			printf("is_right_argv::over arg range or str\n");
			return (0);
		}
		num_arr[idx - 1] = num;
	}
	return (1);
}

int	*gen_nbr_arr(int argc, char *argv[])
{
	int	*ret;

	ret = (int *)malloc(sizeof(int) * (argc - 1));
	if (!(ret))
		return (NULL);
	if (!is_right_argv(ret, argv))
	{
		printf("gen_nbr_arr::is not right argv\n");
		error_case();
		free(ret);
		return (NULL);
	}	
	return (ret);
}

// use head as top
t_list	*cvt_arr_to_list(int *num_arr, int size)
{
	t_list	*ret;
	int		idx;
	t_list	*tmp_list;
	int		*tmp_num;

	idx = -1;
	ret = NULL;
	while (++idx < size)
	{
		tmp_num = (int *)malloc(sizeof(int));
		if (!tmp_num)
		{
			printf("cvt_arr_to_list::malloc error\n");
			return (ret);
		}
		*tmp_num = num_arr[idx];
		tmp_list = ft_lstnew(tmp_num);
		ft_lstadd_back(&ret, tmp_list);
	}
	return (ret);
}

void	print_list(t_list *list_head)
{
	while (list_head)
	{
		printf("addr of prev: %p\n", list_head->prev);
		printf("addr of curr: %p\n", list_head);
		printf("addr of next: %p\n", list_head->next);
		printf("data of list: %d\n\n", *(int *)(list_head->content));
		//printf("list_content: %d\n", *(int *)(list_head->content));
		//printf("addr of list_content: %p\n\n", list_head->content);
		list_head = list_head->next;
	}
}

void	ft_swap_one(t_list **stack_head)
{
	t_list	*list1;
	t_list	*list2;

	if(!is_more_than_one(*stack_head))
		return ;
	list1 = *stack_head;
	list2 = (*stack_head)->next;
	list1->next = list2->next;
	list2->prev = list1->prev;
	list1->prev = list2;
	list2->next = list1;
	*stack_head = list2;
}

void	ft_swap_both(t_list *a_head, t_list *b_head)
{
	ft_swap_one(&a_head);
	ft_swap_one(&b_head);
}

void	ft_push_one(t_list **src, t_list **dst)
{
	t_list	*tmp;

	if (*src == NULL)
	{
		printf("ft_push_one::src_stack is empty\n");
		return ;
	}
	tmp = *src;
	*src = (*src)->next;
	ft_lstadd_front(dst, tmp); 
}

void	ft_push_both(t_list **a_head, t_list **b_head)
{
	ft_push_one(a_head, b_head);
	ft_push_one(b_head, a_head);
}

void	ft_rotate_one(t_list **stack_head)
{
	t_list	*last;

	if (!is_more_than_one(*stack_head))
		return ;
	last = ft_lstlast(*stack_head);
	last->prev->next = last->next;
	last->prev = (*stack_head)->prev;
	(*stack_head)->prev = last;
	last->next = *stack_head;
	*stack_head = last;
}

void	ft_rotate_both(t_list **a_head, t_list **b_head)
{
	ft_rotate_one(a_head);
	ft_rotate_one(b_head);
}

void	free_num_arr(void *num_arr)
{
	if (num_arr)
		free(num_arr);
	num_arr = NULL;
}

int main(int argc, char *argv[])
{
	int		idx;
	int		*num_arr;
	t_list	*a_head;
	t_list	*b_head;
	
	num_arr = gen_nbr_arr(argc, argv);
	if (!num_arr)
		return (error_case());
	a_head = cvt_arr_to_list(num_arr, argc - 1);
	b_head = NULL;

#if 0
	ft_swap_one(&a_head);
	print_list(a_head);
#endif

#if 0
	ft_push_one(&b_head, &a_head);
	printf("print a list =====================\n");
	print_list(a_head);
	printf("print b list =====================\n");
	print_list(b_head);
#endif
#if 0
	ft_rotate_one(&a_head);
	printf("print a list =====================\n");
	print_list(a_head);
#endif
	ft_rotate_both(&a_head, &b_head);
	free(num_arr);
	ft_lstclear(&a_head, &free);
	ft_lstclear(&b_head, &free);

	return (0);
}
