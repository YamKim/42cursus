/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_del_idx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 07:25:04 by yekim             #+#    #+#             */
/*   Updated: 2020/12/29 10:40:59 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	lst_del_idx(t_lst **lst, int idx)
{
	t_lst	*del;
	t_lst	*itr;

	if (*lst == NULL)
		return ;
	if (idx == 0)
	{
		free(*lst);
		*lst = (*lst)->next;
	}
	itr = *lst;
	while (itr && itr->next)
	{
		del = itr->next;
		if (--idx == 0)
		{
			itr->next = del->next;
			free(del);
			return ;
		}
		itr = itr->next;
	}
}
