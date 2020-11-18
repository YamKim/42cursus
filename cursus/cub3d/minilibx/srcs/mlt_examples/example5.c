#include <stdio.h>
#include "../../mlx.h"
typedef struct s_img
{
	void		*ptr;
	int			*data;
	int			width;
	int			height;

	int			size_l;
	int			bpp;
	int			endian;
}				t_img;

int main()
{
		void	*mlx;
		void	*win;
		t_img	img;
		int		y;
		int		x;

		mlx = mlx_init();
		win = mlx_new_window(mlx, 500, 500, "my_mlx");
		img.ptr = mlx_xpm_file_to_image(mlx, "../textures/barrel.xpm", &img.width, &img.height);
		printf("img.width: %d, img.height: %d\n", img.width, img.height);
		img.data = (int *)mlx_get_data_addr(img.ptr, &img.bpp, &img.size_l, &img.endian);

		y = 0;
		while (y < img.height)
		{
			x = 0;
			while (x < img.width / 4)
			{
				img.data[y * img.width + x] = 0x0000FFFF;
				++x;
			}
			++y;
		}
		mlx_put_image_to_window(mlx, win, img.ptr, 50, 50);
		mlx_loop(mlx);
		return (0);
}
