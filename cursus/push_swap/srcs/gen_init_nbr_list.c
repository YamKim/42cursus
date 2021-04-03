#include "../incs/push_swap.h"

static int	is_int_range(char *str, int num)
{
	int	zero_case;

	zero_case = str[0] == '0' && str[1] == '\0';
	if (!zero_case && num == 0)
		return (0);
	return (1);
}

static int	is_duplicated_num(int *num_arr, int idx, int num)
{
	int	itr;

	itr = -1;
	while (++itr < idx)
	{
		if (num_arr[itr] == num)
			return (1);
	}
	return (0);
}

static int	is_right_argv(int *num_arr, char **argv)
{
	int	idx;
	int	num;

	idx = -1;
	while (argv[++idx])
	{
		num = ft_atoi(argv[idx]);
		if (!is_int_range(argv[idx], num))
		{
			ft_putstr_fd("is_right_argv::over arg range or str\n", STDERR_FILENO);
			return (0);
		}
		if (is_duplicated_num(num_arr, idx, num))
		{
			ft_putstr_fd("is_right_argv::num_arr has duplicated number\n", STDERR_FILENO);
			return (0);
		}
		num_arr[idx] = num;
	}
	return (1);
}

static int	*gen_nbr_arr(int size, char **argv)
{
	int	*ret;

	if (size == 0)
		return (NULL);
	ret = (int *)malloc(sizeof(int) * size);
	if (!(ret))
		return (NULL);
	if (!is_right_argv(ret, argv))
	{
		ft_putstr_fd("gen_nbr_arr::is not right argv\n", STDERR_FILENO);
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
			ft_putstr_fd("cvt_arr_to_list::malloc error\n", STDERR_FILENO);
			return (ret);
		}
		*tmp_num = num_arr[idx];
		tmp_list = ft_lstnew(tmp_num);
		ft_lstadd_back(&ret, tmp_list);
	}
	return (ret);
}

t_list	*gen_init_nbr_list(int size, char *argv[])
{
	int		*num_arr;
	t_list	*ret;
	
	num_arr = gen_nbr_arr(size, argv);
	if (num_arr == NULL)
		return (NULL);
	ret = cvt_arr_to_list(num_arr, size);
	free(num_arr);
	return (ret);
}
