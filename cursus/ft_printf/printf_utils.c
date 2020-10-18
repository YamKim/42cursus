#include "ft_printf.h"

int		write_pad_prec(const char *str, const t_info *info)
{
	int		ret;
	int		pad_len;
	char	pad;

	if (info->flag == INFO_INIT || info->flag == FLAG_SPACE) 
		pad = ' ';
	else if (info->flag == FLAG_ZERO)
		pad = '0';
	ret = 0;
	pad_len = info->width - info->prec;
	pad_len = pad_len >= 0 ? pad_len : 0;
	while (pad_len--)
		ret += write(STD_OUT, &pad, sizeof(pad));
	if (info->prec != INFO_INIT)
		ret += write(STD_OUT, str, info->prec);
	else
		ret += write(STD_OUT, str, ft_strlen(str));
	return (ret);
}

int		write_prec_pad(const char *str, const t_info *info)
{
	int		ret;
	int		pad_len;
	char	pad;

	if (info->flag == INFO_INIT || info->flag == FLAG_SPACE) 
		pad = ' ';
	else if (info->flag == FLAG_ZERO)
		pad = '0';
	ret = 0;
	pad_len = info->width - info->prec;
	pad_len = pad_len >= 0 ? pad_len : 0;
	if (info->prec != INFO_INIT)
		ret += write(STD_OUT, str, info->prec);
	else
		ret += write(STD_OUT, str, ft_strlen(str));
	while (pad_len--)
		ret += write(STD_OUT, &pad, sizeof(pad));
	return (ret);
}

