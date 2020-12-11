#include "cub3d.h"


#if 0
int	draw_tex_floor(t_disp *disp, t_player pl)
{
	//double row_dist = hctr / (y - hctr);
}

int	draw_tex_floor()
{
}
#endif

int	draw_tex_background(t_disp *disp, t_player *player)
{
	t_vecd	ray_dir0;
	t_vecd	ray_dir1;
	t_veci	cell;

	ray_dir0.x = player->dir.x - player->plane.x;
	ray_dir0.y = player->dir.y - player->plane.y;
	ray_dir1.x = player->dir.x + player->plane.x;
	ray_dir1.y = player->dir.y + player->plane.y;


	t_draw	draw;

	t_vecd	ceil_step;
	t_vecd	ceil;

	t_tex tex_ceil = disp->tex[CONFIG_NO];
	t_tex tex_floor = disp->tex[CONFIG_SO];

	draw.yctr = (int)(0.5 * disp->h) + disp->hctr_bias;
	for(int y = 0; y < draw.yctr; ++y)
	{
		double row_dist = (double)draw.yctr / (draw.yctr - y);
		ceil_step.x = row_dist * (ray_dir1.x - ray_dir0.x) / disp->w;
		ceil_step.y = row_dist * (ray_dir1.y - ray_dir0.y) / disp->w;
		ceil.x = player->pos.x + row_dist * ray_dir0.x;
		ceil.y = player->pos.y + row_dist * ray_dir0.y;
		for(int x = 0; x < disp->w; ++x)
		{
			cell.x = (int)ceil.x;
			cell.y = (int)ceil.y;
			draw.tx = (int)fmin(tex_ceil.w * (ceil.x - cell.x), tex_ceil.w - 1);
			draw.ty = (int)fmin(tex_ceil.h * (ceil.y - cell.y), tex_ceil.h - 1);
			draw.color = tex_ceil.data[draw.ty * tex_ceil.w + draw.tx];
			draw.color = (draw.color >> 1) & 8355711; // make a bit darker
			disp->img.data[y * disp->w + x] =disp->ceil_color;
			//disp->img.data[y * disp->w + x] = hit_point.color;	
			ceil.x += ceil_step.x;
			ceil.y += ceil_step.y;
		}
	}
	t_vecd	floor_step;
	t_vecd	floor;
	for (int y = draw.yctr + 1; y < disp->h; ++y)
	{
		double row_dist = (double)draw.yctr / (y - draw.yctr);
		floor_step.x = row_dist * (ray_dir1.x - ray_dir0.x) / disp->w;
		floor_step.y = row_dist * (ray_dir1.y - ray_dir0.y) / disp->w;
		floor.x = player->pos.x + row_dist * ray_dir0.x;
		floor.y = player->pos.y + row_dist * ray_dir0.y;
		for(int x = 0; x < disp->w; ++x)
		{
			cell.x = (int)floor.x;
			cell.y = (int)floor.y;
			draw.tx = (int)fmin(tex_floor.w * (floor.x - cell.x), tex_floor.w - 1);
			draw.ty = (int)fmin(tex_floor.h * (floor.y - cell.y), tex_floor.h - 1);
			draw.color = tex_floor.data[draw.ty * tex_floor.w + draw.tx];
			draw.color = (draw.color >> 1) & 8355711; // make a bit darker
			disp->img.data[y * disp->w + x] = disp->floor_color;
			//disp->img.data[y * disp->w + x] = hit_point.color;
			floor.x += floor_step.x;
			floor.y += floor_step.y;
		}
	}
	return (0);
}
