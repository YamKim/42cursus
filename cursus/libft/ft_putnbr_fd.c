/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 15:48:05 by yekim             #+#    #+#             */
/*   Updated: 2020/10/02 15:52:23 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int				sign;
	unsigned int	n_tmp;

	if (fd < 0)
		return ;
	if (!n)
		return ;
	sign = n < 0 ? 1 : 0;
	if (sign)
	{
		ft_putchar_fd('-', fd);
		n_tmp = -n;
	}
	else
		n_tmp = n;
	ft_putnbr_fd(n_tmp / 10, fd);
	ft_putchar_fd(n_tmp % 10 + '0', fd);
}
