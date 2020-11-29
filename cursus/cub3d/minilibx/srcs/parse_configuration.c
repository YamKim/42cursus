#include "cub3d.h"

int	get_resolution(t_disp *disp, char **word_buf, int wc)
{
	if ((disp->config & (1 << CONFIG_R)) || wc != 3)
		return (ERR_PARSE);
	if (is_number_arr(word_buf + 1, 2, CONFIG_R))
		return (ERR_PARSE);
	disp->config |= 1 << CONFIG_R;
	disp->width = ft_atoi(word_buf[1]);
	disp->height = ft_atoi(word_buf[2]);
	printf("parse_resolution success\n");
	return (0);
}

// show error if repetead case occured
int	get_texture(t_disp *disp, char *fname, int type, int wc)
{
	printf("%d type parsing[%s] start\n", type, fname);
	if ((disp->config & (1 << type)) || wc != 2)
		return (ERR_PARSE);
	disp->config |= 1 << type;
	if (load_tex(&(disp->tex[type]), fname) != 0)
		return (ERR_TEXTURE_CALL);
	printf("%d type parsing[%s] success\n", type, fname);
	return (0);
}

int	get_fc_color(t_disp *disp, char *color_set, int type, int wc)
{
	char	**rgb;
	int		tot_color;

	if ((disp->config & (1 << type)) || wc != 2)
		return (ERR_PARSE);
	disp->config |= 1 << type;
	rgb = ft_split(color_set, ',', &tot_color);
	if (is_number_arr(rgb, 3, type))
	{
		free_split_arr(rgb);
		return (ERR_PARSE);
	}
	tot_color = ft_atoi(rgb[0]) << 16 | ft_atoi(rgb[1]) << 8 | ft_atoi(rgb[2]);
	free_split_arr(rgb);
	if (type == CONFIG_F)
		disp->floor_color = tot_color;
	else
		disp->ceil_color = tot_color;
	printf("color parsing success\n");
	return (0);
}

int	parse_config_case(t_disp *disp, char **word_buf, int word_cnt)
{
	int	parse_err;

	parse_err = 0;
	if (!ft_strncmp(word_buf[0], "S", ft_strlen(word_buf[0])))
		parse_err |= get_texture(disp, word_buf[1], CONFIG_S, word_cnt);
	else if (!ft_strncmp(word_buf[0], "R", 1))
		parse_err |= get_resolution(disp, word_buf, word_cnt);
	else if (!ft_strncmp(word_buf[0], "NO", ft_strlen(word_buf[0])))
		parse_err |= get_texture(disp, word_buf[1], CONFIG_NO, word_cnt);
	else if (!ft_strncmp(word_buf[0], "SO", ft_strlen(word_buf[0])))
		parse_err |= get_texture(disp, word_buf[1], CONFIG_SO, word_cnt);
	else if (!ft_strncmp(word_buf[0], "WE", ft_strlen(word_buf[0])))
		parse_err |= get_texture(disp, word_buf[1], CONFIG_WE, word_cnt);
	else if (!ft_strncmp(word_buf[0], "EA", ft_strlen(word_buf[0])))
		parse_err |= get_texture(disp, word_buf[1], CONFIG_EA, word_cnt);
	else if (!ft_strncmp(word_buf[0], "F", ft_strlen(word_buf[0])))
		parse_err |= get_fc_color(disp, word_buf[1], CONFIG_F, word_cnt);
	else if (!ft_strncmp(word_buf[0], "C", ft_strlen(word_buf[0])))
		parse_err |= get_fc_color(disp, word_buf[1], CONFIG_C, word_cnt);
	else
		parse_err |= ERR_PARSE;
	return (parse_err);
}

int	parse_config(t_disp *disp, char **line_buf, int *k)
{
	char	**word_buf;
	int		word_cnt;

	disp->config = 0;
	*k = 0;
	while (line_buf[*k])
	{
		printf("k: %d\n", *k);
		if (disp->config == ((1 << CONFIG_NUMBER) - 1))
		{
			printf("Finished parsing for elments!\n");
			break;
		}
		word_buf = ft_split(line_buf[*k], ' ', &word_cnt);
		if (parse_config_case(disp, word_buf, word_cnt))
			return (ERR_PARSE_CONFIG);
		*k = *k + 1;
	}
	if (*k != CONFIG_NUMBER)
		return (ERR_PARSE_CONFIG);
	return (0);
}

