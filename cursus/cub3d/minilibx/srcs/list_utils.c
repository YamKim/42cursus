/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 09:26:38 by yekim             #+#    #+#             */
/*   Updated: 2020/12/21 09:26:39 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_lst	*lst_new_spr(t_spr spr)
{
	t_lst	*ret;

	if (!(ret = (t_lst *)malloc(sizeof(t_lst))))
		return (NULL);
	ret->spr = spr;
	ret->next = NULL;
	return (ret);
}

t_lst	*lst_last(t_lst *lst)
{
	if (lst == NULL)
		return (NULL);
	if (lst->next == NULL)
		return (lst);
	return (lst_last(lst->next));
}

void	lst_add_back(t_lst **lst, t_lst *new_lst)
{
	t_lst	*last;

	if (lst == 0 || new_lst == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new_lst;
		return ;
	}
	last = lst_last(*lst);
	new_lst->next = last->next;
	last->next = new_lst;
}

t_lst	*lst_get_idx(t_lst *lst, int idx)
{
	if (lst == NULL)
		return (NULL);
	if (idx == 0)
		return (lst);
	return (lst_get_idx(lst->next, idx - 1));
}
