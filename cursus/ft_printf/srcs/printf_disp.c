#include "../incs/ft_printf.h"

void	set_pad_space(t_info *info)
{
	if (info->prec > 0)
	{
		if (info->flag.zero)
			info->flag.zero = 0;
		if (info->prec >= info->len)
		{
			if (info->flag.plus || info->flag.space || info->sign)
				info->pad_len = info->prec - info->len + 1;
			else
				info->pad_len = info->prec - info->len;
		}
		else
		{
			info->pad_len = 0;
			if (ft_strchr("cs", info->type))
				info->len = info->prec;
		}
		if (ft_strchr("cs", info->type))
			info->space_len = calc_max(info->width - info->len, 0);
		else
			info->space_len = calc_max(info->width - (info->pad_len + info->len), 0);	
	}
	else
		info->space_len = calc_max(info->width - info->len, 0);
}

int		put_signed_num(const char *str, t_info *info)
{
	int	ret;

	ret = 0;
	set_pad_space(info);
	if (info->flag.minus)
	{
		ret += write(STD_OUT, &str[0], 1);
		info->len -= 1;
		ret += put_pad_disp_space(&str[1], info);
	}
	else if (info->flag.zero)
		ret += put_zeroflag_disp(str, info);
	else
		ret += put_space_sign_pad_disp(str, info);
	return (ret);
}

int		put_unsigned_num(const char *str, t_info *info)
{
	int	ret;

	ret = 0;
	set_pad_space(info);
	if (info->flag.minus)
		ret += put_pad_disp_space(str, info);
	else if (info->flag.zero)
		ret += put_zeroflag_disp(str, info);
	else
		ret += put_space_pad_disp(str, info);
	return (ret);
}

int		put_char_string(const char *str, t_info *info)
{
	int	ret;

	ret = 0;
	set_pad_space(info);
	if (info->flag.minus)
		ret = put_pad_disp_space(str, info);	
	else if (info->flag.zero)
		ret = put_zeroflag_disp(str, info);
	else
		ret = put_space_pad_disp(str, info); 

	return (ret);
}
