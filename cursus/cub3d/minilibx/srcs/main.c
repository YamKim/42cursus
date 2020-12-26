/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 12:02:53 by yekim             #+#    #+#             */
/*   Updated: 2020/12/26 18:28:53 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_info(
			t_disp *disp,
			char *file_name)
{
	int		fd;
	char	buf[FILE_DATA];
	char	**line_buf;
	int		beg;
	int		ret;

	if ((fd = open(file_name, O_RDONLY)) < 0)
		return (ERR_GET_INFO);
	if (read(fd, buf, FILE_DATA) < 0)
	{
		close(fd);
		return (ERR_GET_INFO);
	}
	ret = 0;
	line_buf = ft_split(buf, '\n', &(disp->map.h));
	beg = 0;
	if (ret == 0)
		ret = parse_config(disp, line_buf, &beg);
	disp->map.h = disp->map.h - beg;
	if (ret == 0)
		ret = parse_map(disp, line_buf, beg);
	free_split_arr(line_buf);
	close(fd);
	return (ret);
}

int			main(int argc, char *argv[])
{
	t_disp		disp;
	t_player	player;
	int			err_num;

	err_num = 0;
	init_disp_setting(&disp);
	if (argc == 2)
	{
		if (check_file(argv[1]))
			return (ERR_CHECK_FILE);
		if ((err_num = get_info(&disp, argv[1])) < 0)
			printf("ERROR_NUMBER: %d\n", err_num);
		show_map_data(disp);
		if (err_num == 0 && cub3d_run(&disp, &player, 0))
			return (ERR_RUN);
	}
	return (0);
}
