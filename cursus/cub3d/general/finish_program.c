/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish_program.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <yekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 19:19:38 by yekim             #+#    #+#             */
/*   Updated: 2021/01/03 07:45:06 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	free_split_arr(char **tab)
{
	int	idx;

	idx = 0;
	while (tab[idx])
	{
		free(tab[idx]);
		++idx;
	}
	free(tab);
}

int		finish_program(t_loop *lv)
{
	lst_clear(&(lv->disp->spr_lst));
	mlx_destroy_window(lv->disp->mlx_ptr, lv->disp->win_ptr);
	ft_putstr("THE PROGRAM HAS ENDED\n");
	exit(0);
	return (0);
}
