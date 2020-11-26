#include "cub3d.h"

int	parse_resolution(t_disp *disp, char **word_buf)
{
	if (disp->config & (1 << CONFIG_R))
		return (ERR_PARSE);
	disp->config |= 1 << CONFIG_R;
	disp->width = ft_atoi(word_buf[1]);
	disp->height = ft_atoi(word_buf[2]);
	printf("parse_resolution success\n");
	return (0);
}

// show error if repetead case occured
int	parse_texture(t_disp *disp, char *fname, int type)
{
	int	tex_load_err;

	printf("fname: %s\n", fname);
	if (disp->config & (1 << type))
		return (ERR_PARSE);
	disp->config |= 1 << type;
	if ((tex_load_err = load_tex(&(disp->tex[type]), fname)) != 0)
		return (tex_load_err);
	printf("%d type parsing success\n", type);
	return (0);
}


int	parse_color(t_disp *disp, char *color_set, int type)
{
	int		tex_load_err;
	char	**rgb;
	int		tot_color;

	if (disp->config & (1 << type))
		return (ERR_PARSE);
	disp->config |= 1 << type;
	rgb = ft_split(color_set, ',');
	if (check_is_number_arr(rgb))
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
	return (0);
}

int	parse_config_case(t_disp *disp, char **word_buf)
{
	int	parse_err;

	parse_err = 0;
	if (!ft_strncmp(word_buf[0], "R", 1))
		parse_err |= parse_resolution(disp, word_buf);
	else if (!ft_strncmp(word_buf[0], "NO", 2))
		parse_err |= parse_texture(disp, word_buf[1], CONFIG_NO);
	else if (!ft_strncmp(word_buf[0], "SO", 2))
		parse_err |= parse_texture(disp, word_buf[1], CONFIG_SO);
	else if (!ft_strncmp(word_buf[0], "WE", 2))
		parse_err |= parse_texture(disp, word_buf[1], CONFIG_WE);
	else if (!ft_strncmp(word_buf[0], "EA", 2))
		parse_err |= parse_texture(disp, word_buf[1], CONFIG_EA);
	else if (!ft_strncmp(word_buf[0], "S", 1))
		parse_err |= parse_texture(disp, word_buf[1], CONFIG_S);
	else if (!ft_strncmp(word_buf[0], "F", 1))
		parse_err |= parse_color(disp, word_buf[1], CONFIG_F);
	else if (!ft_strncmp(word_buf[0], "C", 1))
		parse_err |= parse_color(disp, word_buf[1], CONFIG_C);
	printf("parse_err: %d\n", parse_err);
	return (parse_err);
}

int	parse_config(t_disp *disp, char **line_buf)
{
	int		k;
	char	**word_buf;

	k = 0;
	while (line_buf[k])
	{
		if (disp->config == ((1 << CONFIG_NUMBER) - 1))
		{
			printf("Finished parsing for elments!\n");
			break;
		}
		word_buf = ft_split(line_buf[k], ' ');
		if (parse_config(disp, word_buf))
			return (ERR_PARSE);
		free_split_arr(word_buf);
		++k;
	}
	if (k != CONFIG_NUMBER)
	{
		printf("Not enough configuration!\n");
		free_split_arr(line_buf);
		return (ERR_PARSE);
	}
	return (0);
}
