#include "ft_string.h"

void	ft_putnbr(int nbr)
{
	int				sign;
	unsigned int	nbr_tmp;

	if (!nbr)
		return ;
	sign = nbr < 0 ? 1 : 0;
	if (sign)
	{
		ft_putchar('-');
		nbr_tmp = -nbr;
	}
	else
		nbr_tmp = nbr;
	ft_putnbr(nbr_tmp / 10);
	ft_putchar(nbr_tmp % 10 + '0');
}
