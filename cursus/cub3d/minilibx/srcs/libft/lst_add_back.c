/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_add_back.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 07:27:51 by yekim             #+#    #+#             */
/*   Updated: 2020/12/29 10:40:57 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

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
