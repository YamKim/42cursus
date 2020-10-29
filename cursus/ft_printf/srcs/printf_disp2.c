#include "../incs/ft_printf.h"

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

int		put_zeroflag_disp(const char *str, t_info *info)
{
	int	ret;

	ret = 0;
	if (info->flag.plus || info->flag.space || info->sign)
		ret += write(STD_OUT, &str[0], 1);
	while (info->space_len-- > 0)
		ret += write(STD_OUT, "0", 1);	
	if (info->flag.plus || info->flag.space || info->sign)
		ret += write(STD_OUT, &str[1], info->len - 1);
	else
		ret += write(STD_OUT, &str[0], info->len);
	return (ret);	
}

int		put_space_sign_pad_disp(const char *str, t_info *info)
{
	int	ret;

	ret = 0;
	while (info->space_len-- > 0)
		ret += write(STD_OUT, " ", 1);	
	if (info->flag.plus || info->flag.space || info->sign)
		ret += write(STD_OUT, &str[0], 1);
	while (info->pad_len-- > 0)
		ret += write(STD_OUT, "0", 1);	
	if (info->flag.plus || info->flag.space || info->sign)
		ret += write(STD_OUT, &str[1], info->len - 1);
	else
		ret += write(STD_OUT, &str[0], info->len);
	return (ret);
}
