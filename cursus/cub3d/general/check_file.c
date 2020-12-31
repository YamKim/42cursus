/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 17:59:56 by yekim             #+#    #+#             */
/*   Updated: 2020/12/30 19:23:34 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	check_file(char *fname)
{
	char	*ext;
	size_t	fname_len;
	int		ret;

	ret = 0;
	fname_len = ft_strlen(fname);
	ext = ft_substr(fname, fname_len - FILE_EXTENSION_LENGTH, fname_len);
	if (ft_strncmp(ext, FILE_EXTENSION, FILE_EXTENSION_LENGTH))
		ret = ERR_CHECK_FILE;
	free(ext);
	return (ret);
}
