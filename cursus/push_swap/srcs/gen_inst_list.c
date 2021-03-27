#include "../incs/push_swap.h"

int	get_max_strlen(char *str1, char *str2)
{
	int	str1_len;
	int	str2_len;

	str1_len = ft_strlen(str1);
	str2_len = ft_strlen(str2);
	if (str1_len > str2_len)
		return (str1_len);
	return (str2_len);
}

int	ft_strncmp_exact(char *str1, char *str2)
{
	int	len;

	len = get_max_strlen(str1, str2);
	if (!ft_strncmp(str1, str2, len))
		return (0);
	return (1);
}

int	get_inst_type(char *inst)
{
	if (!ft_strncmp_exact("sa", inst))
		return (INST_SA);
	if (!ft_strncmp_exact("sb", inst))
		return (INST_SB);
	if (!ft_strncmp_exact("ss", inst))
		return (INST_SS);
	if (!ft_strncmp_exact("pa", inst))
		return (INST_PA);
	if (!ft_strncmp_exact("pb", inst))
		return (INST_PB);
	if (!ft_strncmp_exact("ra", inst))
		return (INST_RA);
	if (!ft_strncmp_exact("rb", inst))
		return (INST_RB);
	if (!ft_strncmp_exact("rr", inst))
		return (INST_RR);
	if (!ft_strncmp_exact("rra", inst))
		return (INST_RRA);
	if (!ft_strncmp_exact("rrb", inst))
		return (INST_RRB);
	if (!ft_strncmp_exact("rrr", inst))
		return (INST_RRR);
	printf("get_inst_type::wrong instruction: %s\n", inst);
	return (INST_NAN);
}

t_list	*gen_inst_list()
{
	char	*line;
	t_list	*ret;
	int		*tmp_nbr;
	int		error_case;

	ret = NULL;
	error_case = FALSE;
	while (!error_case && get_next_line(&line) > 0) 
	{
		if (!(tmp_nbr = (int *)malloc(sizeof(int))))
			error_case = TRUE;
		*tmp_nbr = get_inst_type(line);
		if (*tmp_nbr == INST_NAN)
			error_case = TRUE;
		if (!error_case)
			ft_lstadd_back(&ret, ft_lstnew(tmp_nbr));
		if (!error_case)
			free(line);
	}
	free(line);
	if (error_case)
		ft_lstclear(&ret, &free);
	return (ret);
}
