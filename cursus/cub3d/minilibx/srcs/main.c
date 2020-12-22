/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 12:02:53 by yekim             #+#    #+#             */
/*   Updated: 2020/12/22 10:36:30 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_info(t_disp *disp, char *fname)
{
	int		fd;
	char	buf[FILE_DATA];
	char	**line_buf;
	int		end;
	int		beg;
	int		err_num;

	fd = open_file(fname);
	err_num = 0;
	if (read(fd, buf, FILE_DATA) < 0)
	{
		perror("The following error occurred");
		return (errno);
	}
	line_buf = ft_split(buf, '\n', &end);
	beg = 0;
	if (err_num == 0)
		err_num = parse_config(disp, line_buf, &beg);
	disp->map.h = end - beg;
	disp->map.max_w = -2;
	if (err_num == 0)
		err_num = parse_map(disp, line_buf, beg);
	if (err_num == ERR_PARSE_CONFIG)
		printf("Parsing Configurations FAIL=============\n");
	if (err_num == ERR_PARSE_MAP)
		printf("Parsing Map FAIL========================\n");
	free(line_buf);
	return (err_num);
}

int	main(int argc, char *argv[])
{
	t_disp		disp;
	t_player	player;
	int			err_num;

	err_num = 0;
	init_disp_setting(&disp);
	if (argc == 2)
	{
		if (check_file(argv[1]))
			return (ERR_FILE);
		// malloc failure case: -
		if ((err_num = get_info(&disp, argv[1])) < 0)
		{
			printf("ERROR_NUMBER: %d\n", err_num);
			return (ERR_FILE);
		}
		show_map_data(disp);
		init_player_setting(&disp, &player);
#if 1
		if (err_num == 0 && cub3d_run(&disp, &player, 1))
			return (ERR_RUN);
#endif
	}
	return (0);
}
