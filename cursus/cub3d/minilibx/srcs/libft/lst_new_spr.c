/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_new_spr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 07:27:07 by yekim             #+#    #+#             */
/*   Updated: 2020/12/29 09:55:59 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_lst	*lst_new_spr(t_spr spr)
{
	t_lst	*ret;

	if (!(ret = (t_lst *)malloc(sizeof(t_lst))))
		return (NULL);
	ret->spr = spr;
	ret->next = NULL;
	return (ret);
}
