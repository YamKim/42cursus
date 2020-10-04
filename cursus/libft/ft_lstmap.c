/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 08:07:31 by yekim             #+#    #+#             */
/*   Updated: 2020/10/04 19:53:02 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	g_flag;

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list		*ret;

	g_flag = 0;
	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	if (!(ret = ft_lstmap(lst, f, del)))
	{
		g_flag = 1;
		return (NULL);
	}
	ret->next = ft_lstmap(lst->next, f, del);
	if (g_flag)
	{
		ft_lstdelone(lst, del);
		return (NULL);
	}
	return (ret);
}
