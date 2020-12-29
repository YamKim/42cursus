/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_get_idx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 07:28:16 by yekim             #+#    #+#             */
/*   Updated: 2020/12/29 07:28:22 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_lst	*lst_get_idx(t_lst *lst, int idx)
{
	if (lst == NULL)
		return (NULL);
	if (idx == 0)
		return (lst);
	return (lst_get_idx(lst->next, idx - 1));
}
