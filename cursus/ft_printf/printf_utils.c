#include "ft_printf.h"

int		write_pad_prec(const char *str, const t_info *info)
{
	int		ret;
	int		pad_len;
	int		put_len;
	char	pad;

	pad = PAD_TYPE[info->flag];
	ret = 0;
	put_len = (int)ft_strlen(str);
	if (info->prec != INFO_INIT)
		put_len = calc_min(ft_strlen(str), info->prec);
	pad_len = info->width - put_len;
	pad_len = calc_max(pad_len, 0);
	while (pad_len--)
		ret += write(STD_OUT, &pad, sizeof(pad));
	ret += write(STD_OUT, str, put_len);
	return (ret);
}

int		write_prec_pad(const char *str, const t_info *info)
{
	int		ret;
	int		pad_len;
	int		put_len;
	char	pad;

	pad = PAD_TYPE[info->flag];
	ret = 0;
	put_len = (int)ft_strlen(str);
	if (info->prec != INFO_INIT)
		put_len = calc_min(ft_strlen(str), info->prec);
	pad_len = info->width - put_len;
	pad_len = calc_max(pad_len, 0);
	ret += write(STD_OUT, str, put_len);
	while (pad_len--)
		ret += write(STD_OUT, &pad, sizeof(pad));
	return (ret);
}

