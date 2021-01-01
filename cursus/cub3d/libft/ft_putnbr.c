/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 18:25:34 by yekim             #+#    #+#             */
/*   Updated: 2021/01/01 12:05:00 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static void	print_nbr(unsigned int n)
{
	if (n >= 10)
		print_nbr(n / 10);
	ft_putchar(n % 10 + '0');
}

void		ft_putnbr(int n)
{
	int				sign;
	unsigned int	n_tmp;

	sign = n < 0 ? 1 : 0;
	if (sign)
	{
		ft_putchar('-');
		n_tmp = -n;
	}
	else
		n_tmp = n;
	print_nbr(n_tmp);
}
