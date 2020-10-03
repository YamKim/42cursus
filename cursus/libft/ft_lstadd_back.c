/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 17:27:17 by yekim             #+#    #+#             */
/*   Updated: 2020/10/03 06:41:19 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new_lst)
{
	if (lst == 0 || new_lst == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new_lst;	
		return ;
	}
	ft_lstadd_back(&((*lst)->next), new_lst);
}
