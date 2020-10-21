#include "ft_printf.h"

int		get_str_len(const char *str, const t_info *info)
{
	int	ret;
	int	pad_len;
	
	ret = 0;
	if (ft_strchr(SIGN_TYPE, str[0]))
		ret += 1;
	// prec 보다 len이 길면 제로패드 x
	pad_len = info->flag.zero ? calc_max(info->prec - info->len, 0) : 0;
	if (info->conv == 'd')
		ret += pad_len;
	// prec 값이 있는 경우
	if (info->prec != INFO_INIT)
	{
		if (info->conv == 's' || info->conv == 'c' || info->conv == 'f')	
			// 잘리면 값을 바꿔놓기. 출력을 위해서
			((t_info *)info)->len = calc_min(info->len, info->prec);
	}
	ret += info->len;
	if (info->conv == 'f')
		ret += pad_len;
	return (ret);
}

int		gen_str(const char *str, const t_info *info)
{
	int	ret;
	int	pad_len;
	
	ret = 0;
	if (ft_strchr(SIGN_TYPE, str[0]))
		ret += write(STD_OUT, &str[0], 1);
	// prec 보다 len이 길면 제로패드 x
	pad_len = info->flag.zero ? calc_max(info->prec - info->len, 0) : 0;
	if (info->conv == 'd')
		while (pad_len--)
			ret += write(STD_OUT, "0", 1);
	// prec 값이 있는 경우
	ret += write(STD_OUT, str, info->len);
	if (info->conv == 'f')
		while (pad_len--)
			ret += write(STD_OUT, "0", 1);
	return (ret);
}

int		put_space_and_str(const char *str, const t_info *info)
{
	int		ret;
	int		space_len;

	ret = 0;
	space_len = info->width - get_str_len(str, info);
	space_len = calc_max(space_len, 0);
	if (!info->flag.minus)
		while (space_len--)
			ret += write(STD_OUT, " ", 1);
	gen_str(str, info);	
	if (info->flag.minus)
		while (space_len--)
			ret += write(STD_OUT, " ", 1);
	return (ret);
}

char	*add_prefix(const char *prefix, const char *str)
{
	char	*ret;

	ret = ft_strjoin(prefix, str);
	free((char *)str);

	return (ret);
}
