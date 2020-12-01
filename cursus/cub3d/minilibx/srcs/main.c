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


int	draw_tex_floor(t_disp disp, t_player player)
{
	t_vecd	ray_dir0;
	t_vecd	ray_dir1;

	ray_dir0.x = player.dir.x - player.plane.x;
	ray_dir0.y = player.dir.y - player.plane.y;
	ray_dir1.x = player.dir.x + player.plane.x;
	ray_dir1.y = player.dir.y + player.plane.y;

	for(int y = disp.height / 2 + 1; y < disp.height; ++y)
	{
		int p = y - disp.height / 2;
		// Vertical position of the camera.
		float posZ = 0.5 * disp.height;
		// Horizontal distance from the camera to the floor for the current row.
		// 0.5 is the z position exactly in the middle between floor and ceiling.
		float rowDistance = posZ / p;
		// calculate the real world step vector we have to add for each x (parallel to camera plane)
		// adding step by step avoids multiplications with a weight in the inner loop
		float floorStepX = rowDistance * (ray_dir1.x - ray_dir0.x) / disp.width;
		float floorStepY = rowDistance * (ray_dir1.y - ray_dir0.y) / disp.width;
		// real world coordinates of the leftmost column. This will be updated as we step to the right.
		// floor는 dir0과 관련됨
		float floorX = player.pos.x + rowDistance * ray_dir0.x;
		float floorY = player.pos.y + rowDistance * ray_dir0.y;
		t_tex tex_floor = disp.tex[CONFIG_SO];
		t_tex tex_ceil = disp.tex[CONFIG_NO];
		for(int x = 0; x < disp.width; ++x)
		{
			// the cell coord is simply got from the integer parts of floorX and floorY
			#if 1
			int cellX = (int)(floorX);
			int cellY = (int)(floorY);
			#endif
			// get the texture coordinate from the fractional part
			#if 1
			int tx = (int)fmin(tex_floor.width * (floorX - cellX), tex_floor.width - 1);
			int ty = (int)fmin(tex_floor.height * (floorY - cellY), tex_floor.height - 1);
			#endif
			floorX += floorStepX;
			floorY += floorStepY;
			// choose texture and draw the pixel
			#if 1
			//int checkerBoardPattern = (int)(cellX + cellY) & 1;
			#if 0
			if(checkerBoardPattern == 0) floorTexture = 3;
			else floorTexture = 4;
			#endif
			int ceilingTexture = 1;
			int floorTexture = 4;
			#endif
			int color;
			// floor
			color = tex_floor.data[tex_floor.width * ty + tx];
			color = (color >> 1) & 8355711; // make a bit darker
			//disp.img.data[y * disp.width + x] = color;	
			disp.img.data[y * disp.width + x] = disp.floor_color;	
			//ceiling (symmetrical, at height - y - 1 instead of y)
			#if 1
			color = tex_ceil.data[tex_ceil.width * ty + tx];
			color = (color >> 1) & 8355711; // make a bit darker
			//disp.img.data[(disp.height - y - 1) * disp.width + x] = color;	
			disp.img.data[(disp.height - y - 1) * disp.width + x] = disp.ceil_color;	
			#endif
		}
	}
	return (1);
}


// *** gnl, ft_split, lst free!!!!!!!!!!!!!
int main(int argc, char *argv[])
{
	t_disp	disp;
	int		err_num;
	
	disp.spr_lst = NULL;
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
		show_lst_data(disp);
#if 1
		if (cub3d_run(&disp))
			return (ERR_RUN);
#endif
	}
	//lst_clear(&disp.spr_lst);
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
