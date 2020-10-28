#include "../incs/ft_printf.h"

void	set_pad_space(t_info *info)
{
	if (info->prec > 0)
	{
		if (info->prec > info->len)
		{
			info->pad_len = info->prec - info->len;
		}
		else
			info->pad_len = 0;
		info->space_len = calc_max(info->width - (info->pad_len + info->len), 0);	
	}
	else
		info->space_len = info->width - info->len;
}

#include <stdio.h>
int		put_pad_disp_space(const char *str, t_info *info)
{
	int	ret;

	ret = 0;
	if (ft_strchr("diuxX", info->type))
		while (info->pad_len-- > 0)
			ret += write(STD_OUT, "0", 1);	
	ret += write(STD_OUT, str, info->len);
	while (info->space_len-- > 0)
		ret += write(STD_OUT, " ", 1);	
	return (ret);
}

int		put_space_pad_disp(const char *str, t_info *info)
{
	int	ret;

	ret = 0;
	while (info->space_len-- > 0)
		ret += write(STD_OUT, " ", 1);	
	if (ft_strchr("diuxX", info->type))
		while (info->pad_len-- > 0)
			ret += write(STD_OUT, "0", 1);	
	ret += write(STD_OUT, str, info->len);
	return (ret);
}

int		put_sign_zero_disp(const char *str, t_info *info)
{
	int	ret;

	ret = 0;
	if (info->flag.plus || info->flag.space || info->sign)
		ret += write(STD_OUT, &str[0], 1);
	while (info->space_len-- > 0)
		ret += write(STD_OUT, "0", 1);	
	ret += write(STD_OUT, &str[0], info->len);
	return (ret);	
}

#if 1
int		put_sign_num(const char *str, t_info *info)
{
	int	ret;

	ret = 0;
	set_pad_space(info);
	if (info->flag.minus)
	{
		if (info->flag.plus || info->flag.space || info->sign)
		{
			ret += write(STD_OUT, &str[0], 1);
			ret += put_pad_disp_space(&str[1], info);
		}
		else
			ret += put_pad_disp_space(str, info);
	}
	else if (info->flag.zero)
		ret += put_sign_zero_disp(str, info);
	else
	{
		if (info->flag.plus || info->flag.space || info->sign)
			ret += put_space_pad_disp(str + 1, info);
		else
			ret += put_space_pad_disp(str, info);
	}
	return (ret);
}
#endif

int		disp_control(const char *str, t_info *info)
{
	int	ret;
	set_pad_space(info);
	ret = 0;

	if (info->flag.minus)
		ret = put_pad_disp_space(str, info);	
	else
		ret = put_space_pad_disp(str, info); 

	return (ret);
}
