/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_config.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <yekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 12:26:42 by yekim             #+#    #+#             */
/*   Updated: 2020/12/31 10:32:21 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	get_resolution(t_disp *disp, char **word_buf, int wc)
{
	if ((disp->config & (1 << CONFIG_R)) || wc != 3)
		return (ERR_PARSE_CONFIG);
	if (is_number_arr(word_buf + 1, 2, CONFIG_R))
		return (ERR_PARSE_CONFIG);
	disp->config |= 1 << CONFIG_R;
	disp->w = (int)fmin(ft_atoi(word_buf[1]), CONFIG_R_WIDTH_MAX);
	disp->h = (int)fmin(ft_atoi(word_buf[2]), CONFIG_R_HEIGHT_MAX);
	ft_putstr("RESOLUTION PARSING COMPLRETE\n");
	return (0);
}

int	get_texture(t_disp *disp, char *fname, int type, int wc)
{
	if ((disp->config & (1 << type)) || wc != 2)
		return (ERR_PARSE_CONFIG);
	disp->config |= 1 << type;
	if (load_texture(&(disp->tex[type]), fname) != 0)
		return (ERR_PARSE_CONFIG);
	ft_putstr("PARSING TEXTURE[");
	ft_putstr(fname);
	ft_putstr("] COMPLETE\n");
	return (0);
}

int	get_background(t_disp *disp, char *color_set, int type, int wc)
{
	int		ret;
	char	**rgb;
	int		color;

	ret = 0;
	if ((disp->config & (1 << type)) || wc != 2)
		return (ERR_PARSE_CONFIG);
	disp->config |= 1 << type;
	rgb = ft_split(color_set, ',', &color);
	if (is_number_arr(rgb, 3, type))
		ret = ERR_PARSE_CONFIG;
	if (ret == 0)
		color = ft_atoi(rgb[0]) << 16 | ft_atoi(rgb[1]) << 8 | ft_atoi(rgb[2]);
	if (ret == 0 && type == CONFIG_F)
		disp->floor_color = color;
	else if (ret == 0 && type == CONFIG_C)
		disp->ceil_color = color;
	free_split_arr(rgb);
	return (ret);
}

int	parse_config_case(t_disp *disp, char **word_buf, int word_cnt)
{
	int	ret;

	ret = 0;
	if (!ft_strncmp(word_buf[0], "S", ft_strlen(word_buf[0])))
		ret |= get_texture(disp, word_buf[1], CONFIG_S, word_cnt);
	else if (!ft_strncmp(word_buf[0], "R", 1))
		ret |= get_resolution(disp, word_buf, word_cnt);
	else if (!ft_strncmp(word_buf[0], "NO", ft_strlen(word_buf[0])))
		ret |= get_texture(disp, word_buf[1], CONFIG_NO, word_cnt);
	else if (!ft_strncmp(word_buf[0], "SO", ft_strlen(word_buf[0])))
		ret |= get_texture(disp, word_buf[1], CONFIG_SO, word_cnt);
	else if (!ft_strncmp(word_buf[0], "WE", ft_strlen(word_buf[0])))
		ret |= get_texture(disp, word_buf[1], CONFIG_WE, word_cnt);
	else if (!ft_strncmp(word_buf[0], "EA", ft_strlen(word_buf[0])))
		ret |= get_texture(disp, word_buf[1], CONFIG_EA, word_cnt);
	else if (!ft_strncmp(word_buf[0], "F", ft_strlen(word_buf[0])))
		ret |= get_background(disp, word_buf[1], CONFIG_F, word_cnt);
	else if (!ft_strncmp(word_buf[0], "C", ft_strlen(word_buf[0])))
		ret |= get_background(disp, word_buf[1], CONFIG_C, word_cnt);
	else
		ret |= ERR_PARSE;
	return (ret);
}

int	parse_config(t_disp *disp, char **line_buf, int *k)
{
	int		ret;
	char	**word_buf;
	int		word_cnt;

	disp->config = 0;
	*k = 0;
	ret = 0;
	while (ret == 0 && line_buf[*k])
	{
		if (disp->config == ((1 << CONFIG_NUMBER) - 1))
			break ;
		word_buf = ft_split(line_buf[*k], ' ', &word_cnt);
		if (parse_config_case(disp, word_buf, word_cnt))
			ret = ERR_PARSE_CONFIG;
		free_split_arr(word_buf);
		*k = *k + 1;
	}
	if (ret != 0 || *k != CONFIG_NUMBER)
		ret = ERR_PARSE_CONFIG;
	ft_putstr("CONFIGURATION PARSING COMPLETE!\n");
	return (ret);
}
