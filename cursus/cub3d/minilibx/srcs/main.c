#include "cub3d.h"

// over max resolution -> max resolution
/*
** lb: line_buf
*/
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
	if (err_num == 0)
		err_num = parse_config(disp, line_buf, &beg);
	disp->map.height = end - beg;
	if (err_num == 0)
		 err_num = parse_map(disp, line_buf, beg);
	if (err_num == ERR_PARSE_CONFIG)
		printf("Parsing Configurations FAIL=============\n");
	if (err_num == ERR_PARSE_MAP)
		printf("Parsing Map FAIL========================\n");
	free(line_buf);
	return (err_num);
}

// *** gnl, ft_split free !!!!!!!!!!!!!
int main(int argc, char *argv[])
{
	t_disp	disp;
	int		err_num;

	if (argc == 2)
	{
		if (check_file(argv[1]))
			return (ERR_FILE);	
		if ((err_num = get_info(&disp, argv[1])) < 0)
		{
			printf("ERROR_NUMBER: %d\n", err_num);
			return (ERR_FILE);
		}
		show_map_data(disp);
#if 0
		if (cub3d_run(&disp))
			return (ERR_RUN);
#endif
	}
	return (0);
}
