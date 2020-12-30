/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <yekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 09:44:58 by yekim             #+#    #+#             */
/*   Updated: 2020/12/30 18:04:50 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	load_texture(t_tex *tex, char *file_name)
{
	void		*mlx_ptr;
	int			tmp;

	mlx_ptr = mlx_init();
	tex->ptr = mlx_xpm_file_to_image(mlx_ptr, file_name, &(tex->w), &(tex->h));
	if (tex->ptr == NULL)
		return (ERR_TEXTURE_CALL);
	tex->data = (int *)mlx_get_data_addr(tex->ptr, &tmp, &tmp, &tmp);
	return (0);
}
