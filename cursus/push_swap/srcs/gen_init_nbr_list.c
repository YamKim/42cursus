#include "../incs/push_swap.h"
// > ./checker 3 2 1 0

int	error_case()
{
	return (0);
}

static int	is_int_range(char *str, int num)
{
	int	zero_case;

	zero_case = str[0] == '0' && str[1] == '\0';
	if (!zero_case && num == 0)
		return (0);
	return (1);
}

static int	is_right_argv(int *num_arr, char **argv)
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

static int	*gen_nbr_arr(int argc, char **argv)
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
static t_list	*cvt_arr_to_list(int *num_arr, int size)
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

t_list	*gen_init_nbr_list(int argc, char *argv[])
{
	int		*num_arr;
	t_list	*ret;
	
	num_arr = gen_nbr_arr(argc, argv);
	if (!num_arr)
	{
		error_case();
		return (NULL);
	}
	ret = cvt_arr_to_list(num_arr, argc - 1);
	free(num_arr);
	return (ret);
}
