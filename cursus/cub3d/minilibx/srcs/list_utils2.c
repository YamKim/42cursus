/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <yekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 09:26:53 by yekim             #+#    #+#             */
/*   Updated: 2020/12/29 06:07:15 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/cub3d.h"

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

void	lst_clear(t_lst **lst)
{
	if (lst == 0)
		return ;
	if (*lst == NULL)
		return ;
	lst_clear(&((*lst)->next));
	free(*lst);
	*lst = NULL;
}
