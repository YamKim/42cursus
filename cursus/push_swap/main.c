#include "./libft/libft.h"

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

#include <stdio.h>
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
		printf("list_content: %d\n", *(int *)(list_head->content));
		printf("addr of list_content: %p\n", list_head->content);
		//free(list_head->content);
		list_head = list_head->next;
	}
}

void	ft_swap_one(t_list *stack_head)
{
	if (!stack_head || !stack_head->next)
	{
		printf("ft_swap_one::stack_has no or one elements\n");
		return ;	
	}

}

void	ft_swap_both()
{
;
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
	print_list(a_head);

//	ft_swap_one(a_head);
	printf("list size: %d\n", ft_lstsize(a_head));
	
	free(num_arr);
	ft_lstclear(&a_head, &free);

	return (0);
}
