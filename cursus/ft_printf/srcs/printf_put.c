#include "../incs/ft_printf.h"

int		get_str_len(const t_info *info, int *pad_len)
{
	int	ret;
	
	ret = 0;
	if (ft_strchr("diuxXf", info->type))
		if (info->flag.plus || info->flag.space || info->sign == SIGN_MINUS)
			ret += 1;
	*pad_len = calc_max(info->prec - info->len, 0);
	if (ft_strchr("scf", info->type))
		if (info->prec > 0)
			((t_info *)info)->len = calc_min(info->len, info->prec);
	ret += info->len;
	if (info->flag.zero)
		*pad_len = calc_max(info->width - ret, *pad_len);
	if (ft_strchr("cs", info->type))
		return (ret);
	return (ret + *pad_len);
}

char	get_sign2(const t_info *info)
{
	if (info->sign == SIGN_MINUS)
		return ('-');
	if (info->flag.plus)
		return ('+');
	else if (info->flag.space)
		return (' ');
	return ('?');
}

char	*gen_str(const char *str, const t_info *info, int *ret_len)
{
	char	*ret;
	int		pad_len;
	
	*ret_len = get_str_len(info, &pad_len);
	if (!(ret = (char *)malloc(sizeof(char) * (*ret_len + 1))))
		return (NULL);
	ret[*ret_len] = '\0';
	if (ft_strchr("diuxXf", info->type))
		ft_memset((void *)ret, '0', *ret_len);
	if (ft_strchr("diuxXf", info->type))
		if (info->flag.plus || info->flag.space || info->sign == SIGN_MINUS)
			ret[0] = get_sign2(info);
	if (ft_strchr("diupxX", info->type))
		ft_strlcpy(ret + (*ret_len - info->len), str, info->len + 1);
	else if (ft_strchr("f", info->type))
		ft_strlcpy(ret + (*ret_len - info->len - pad_len), str, info->len + 1);
	else if (ft_strchr("cs", info->type))
		ft_strlcpy(ret + (*ret_len - info->len), str, info->len + 1);
	return (ret);
}

int		put_space_and_str(const char *str, const t_info *info)
{
	int		ret;
	int		space_len;
	char	*str_disp;
	int		str_disp_len;

	ret = 0;
	if (!(str_disp = gen_str(str, info, &str_disp_len)))
		return (-1);
	space_len = calc_max(info->width - str_disp_len, 0);
	if (!info->flag.minus)
		while (space_len--)
			ret += write(STD_OUT, " ", 1);
	ret += write(STD_OUT, str_disp, str_disp_len);
	if (info->flag.minus)
		while (space_len--)
			ret += write(STD_OUT, " ", 1);
	free(str_disp);
	return (ret);
}
