#include "ft_printf.h"

int	calc_max(int nbr1, int nbr2)
{
	if (nbr1 >= nbr2)
		return (nbr1);
	return (nbr2);
}

int	calc_min(int nbr1, int nbr2)
{
	if (nbr1 <= nbr2)
		return (nbr1);
	return (nbr2);
}

int	calc_abs(int nbr)
{
	if (nbr >= 0)
		return (nbr);
	return (-nbr);
}