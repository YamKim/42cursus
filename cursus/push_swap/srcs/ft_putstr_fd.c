#include "../incs/push_swap.h"

static int	ft_strlen(char *str)
{
	int	ret;

	ret = 0;
	while (str[ret])
		++str;
	return (ret);
}
