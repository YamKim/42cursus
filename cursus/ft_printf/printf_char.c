/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <yekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 15:00:58 by yekim             #+#    #+#             */
/*   Updated: 2020/10/18 23:42:03 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int		printf_char(char c, const t_info *info)
{
	int	ret;

	ret = 0;
	if (info->flag == INFO_INIT || info->flag == FLAG_PLUS)
		write_pad_prec(&c, info);
	else if (info->flag == FLAG_MINUS)
		write_prec_pad(&c, info);
	return (ret);
}
