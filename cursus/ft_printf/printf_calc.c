/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_calc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <yekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 16:21:14 by yekim             #+#    #+#             */
/*   Updated: 2020/10/19 16:52:52 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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


