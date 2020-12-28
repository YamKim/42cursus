/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <yekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 09:44:58 by yekim             #+#    #+#             */
/*   Updated: 2020/12/29 06:07:15 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/cub3d.h"

int	check_file(char *fname)
{
	char	*ext;
	size_t	fname_len;

	fname_len = ft_strlen(fname);
	ext = ft_substr(fname, fname_len - FILE_EXTENSION_LENGTH, fname_len);
	if (ft_strncmp(ext, FILE_EXTENSION, FILE_EXTENSION_LENGTH))
		return (ERR_CHECK_FILE);
	return (0);
}

int	load_tex(t_tex *tex, char *file_name)
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
