/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sorted_elist.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <yekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 11:43:05 by yekim             #+#    #+#             */
/*   Updated: 2021/04/22 11:43:06 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

int
	print_sorted_elist(t_list *env_list)
{
	t_list	*cur;
	t_env	*tmp_env;
	t_list	*tmp_elist;

	tmp_elist = sort_elist(env_list);
	cur = tmp_elist;
	while (cur)
	{
		tmp_env = (t_env *)(cur->data);
		printf("declare -x %s=\"%s\"\n", tmp_env->key, tmp_env->val);
		cur = cur->next;
	}
	return (0);
}
