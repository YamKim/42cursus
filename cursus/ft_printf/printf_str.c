#include "ft_printf.h"

int	printf_str(const char* str, const t_info *info)
{
	int	ret;

	if (str == NULL)
		str = "(null)";
	ret = ft_strlen(str);
	(void)info;
		

	return (ret);
}
