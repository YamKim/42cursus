#include "cub3d.h"

int	draw_tex_background(t_disp disp, t_player player)
{
	t_vecd	ray_dir0;
	t_vecd	ray_dir1;

	ray_dir0.x = player.dir.x - player.plane.x;
	ray_dir0.y = player.dir.y - player.plane.y;
	ray_dir1.x = player.dir.x + player.plane.x;
	ray_dir1.y = player.dir.y + player.plane.y;

	for(int y = disp.h / 2 + 1; y < disp.h; ++y)
	{
		int p = y - disp.h / 2;
		// Vertical position of the camera.
		float posZ = 0.5 * disp.h;
		// Horizontal distance from the camera to the floor for the current row.
		// 0.5 is the z position exactly in the middle between floor and ceiling.
		float rowDistance = posZ / p;
		// calculate the real world step vector we have to add for each x (parallel to camera plane)
		// adding step by step avoids multiplications with a weight in the inner loop
		float floorStepX = rowDistance * (ray_dir1.x - ray_dir0.x) / disp.w;
		float floorStepY = rowDistance * (ray_dir1.y - ray_dir0.y) / disp.w;
		// real world coordinates of the leftmost column. This will be updated as we step to the right.
		// floor는 dir0과 관련됨
		float floorX = player.pos.x + rowDistance * ray_dir0.x;
		float floorY = player.pos.y + rowDistance * ray_dir0.y;
		t_tex tex_floor = disp.tex[CONFIG_SO];
		t_tex tex_ceil = disp.tex[CONFIG_NO];
		for(int x = 0; x < disp.w; ++x)
		{
			// the cell coord is simply got from the integer parts of floorX and floorY
			#if 1
			int cellX = (int)(floorX);
			int cellY = (int)(floorY);
			#endif
			// get the texture coordinate from the fractional part
			#if 1
			int tx = (int)fmin(tex_floor.w * (floorX - cellX), tex_floor.w - 1);
			int ty = (int)fmin(tex_floor.h * (floorY - cellY), tex_floor.h - 1);
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
			color = tex_floor.data[tex_floor.w * ty + tx];
			color = (color >> 1) & 8355711; // make a bit darker
			//disp.img.data[y * disp.width + x] = color;	
			disp.img.data[y * disp.w+ x] = disp.floor_color;	
			//ceiling (symmetrical, at height - y - 1 instead of y)
			#if 1
			color = tex_ceil.data[tex_ceil.w * ty + tx];
			color = (color >> 1) & 8355711; // make a bit darker
			//disp.img.data[(disp.h - y - 1) * disp.width + x] = color;	
			disp.img.data[(disp.h - y - 1) * disp.w+ x] = disp.ceil_color;	
			#endif
		}
	}
	return (0);
}
