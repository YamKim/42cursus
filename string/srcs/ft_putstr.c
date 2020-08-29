#include "ft_string.h"

void	ft_putstr(char *str)
{
	void	ft_putchar(char c);

	while (*str)
		ft_putchar(*(str++));
}
