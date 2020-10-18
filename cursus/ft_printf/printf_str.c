#include "ft_printf.h"

int	printf_str(const char* str, const t_info *info)
{
	int	ret;

	if (str == NULL)
	{
		write(STD_OUT, "(null)", 6);
		return (6);
	}
	if (info->flag == FLAG_MINUS)
		ret = write_prec_pad(str, info);
	else
		ret = write_pad_prec(str, info);

	return (ret);
}
