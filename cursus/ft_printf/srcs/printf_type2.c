/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_type2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <yekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 11:44:34 by yekim             #+#    #+#             */
/*   Updated: 2020/11/02 15:49:18 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

int	printf_d(const int dec, t_info *info)
{
	int		ret;
	char	*dec_str;

	if (!(dec_str = gen_nbr_str(dec, BASE_DEC)))
		return (MALLOC_ERR);
	if (info->point == 1 && info->prec == 0 && dec == 0)
		dec_str[0] = '\0';
	if (dec < 0)
		info->sign = SIGN_MINUS;
	info->len = (int)ft_strlen(dec_str);
	if ((info->flag.plus || info->flag.space) && !info->sign)
	{
		info->len += 1;
		if (info->flag.plus)
			dec_str = add_prefix("+", dec_str);
		else
			dec_str = add_prefix(" ", dec_str);
	}
	if (info->flag.plus || info->flag.space || info->sign)
		ret = print_signed_num(dec_str, (t_info *)info);
	else
		ret = print_unsigned_num(dec_str, (t_info *)info);
	free(dec_str);
	return (ret);
}

int	printf_u(const unsigned int dec, t_info *info)
{
	int		ret;
	char	*dec_str;

	if (!(dec_str = gen_nbr_str(dec, BASE_DEC)))
		return (MALLOC_ERR);
	if (info->point == 1 && info->prec == 0 && dec == 0)
		dec_str[0] = '\0';
	info->len = (int)ft_strlen(dec_str);
	if ((info->flag.plus || info->flag.space) && !info->sign)
	{
		info->len += 1;
		if (info->flag.plus)
			dec_str = add_prefix("+", dec_str);
		else
			dec_str = add_prefix(" ", dec_str);
	}
	if (info->flag.plus || info->flag.space)
		ret = print_signed_num(dec_str, (t_info *)info);
	else
		ret = print_unsigned_num(dec_str, (t_info *)info);
	free(dec_str);
	return (ret);
}

int	printf_x(const unsigned int dec, t_info *info, char *base_type)
{
	int		ret;
	char	*hex_str;

	if (!(hex_str = gen_nbr_str(dec, base_type)))
		return (MALLOC_ERR);
	if (info->point == 1 && info->prec == 0 && dec == 0)
		hex_str[0] = '\0';
	info->len = (int)ft_strlen(hex_str);
	if ((info->flag.plus || info->flag.space) && !info->sign)
	{
		info->len += 1;
		if (info->flag.plus)
			hex_str = add_prefix("+", hex_str);
		else
			hex_str = add_prefix(" ", hex_str);
	}
	if (info->flag.plus || info->flag.space)
		ret = print_signed_num(hex_str, (t_info *)info);
	else
		ret = print_unsigned_num(hex_str, (t_info *)info);
	free(hex_str);
	return (ret);
}
