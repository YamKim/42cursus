#include "cub3d.h"

// over max resolution -> max resolution
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


// *** gnl, ft_split, lst free!!!!!!!!!!!!!
int main(int argc, char *argv[])
{
	t_disp	disp;
	int		err_num;
	
	disp.spr_lst = NULL;
	disp.itm_lst = NULL;
	err_num = 0;
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
//		show_lst_data(disp.spr_lst);
//		show_lst_data(disp.itm_lst);
#if 1
		if (err_num == 0 && cub3d_run(&disp))
			return (ERR_RUN);
#endif
	}
	lst_clear(&disp.spr_lst);
	lst_clear(&disp.itm_lst);
	return (0);
}
#if 0
		printf("%d spr: pos.x: %lf, pos.y: %lf\n", idx, tmp->spr.pos.x, tmp->spr.pos.y);
		int del_idx = 0;
		printf("after del %d node=======================\n", del_idx);
		lst_del_idx(&(disp.spr_lst), del_idx);
		printf("after del %d node=======================\n", del_idx);
		lst_del_idx(&(disp.spr_lst), del_idx);
		printf("after del %d node=======================\n", del_idx);
		lst_del_idx(&(disp.spr_lst), del_idx);
		printf("after del %d node=======================\n", del_idx);
		lst_del_idx(&(disp.spr_lst), del_idx);
		printf("after del %d node=======================\n", del_idx);
		lst_del_idx(&(disp.spr_lst), del_idx);
		printf("after del %d node=======================\n", del_idx);
		lst_del_idx(&(disp.spr_lst), del_idx);
		show_lst_data(disp);
#endif
