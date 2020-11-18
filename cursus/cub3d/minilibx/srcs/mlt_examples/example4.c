#include <stdio.h>
#include "../../mlx.h"

# define WIN_WIDTH 800
# define WIN_HEIGHT 600

# define IMG_WIDTH 300
# define IMG_HEIGHT 300

typedef struct	s_img
{
	void		*img_ptr;
	int			*data;
	int			size_l;
	int			bpp;
	int			endian;
}				t_img;

typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*win;
}				t_mlx;

int	main(void)
{
	t_mlx	*mlx;
	int		y;
	int		x;
	t_img	img;

	mlx->mlx_ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "A simple example");
	img.img_ptr = mlx_new_image(mlx->mlx_ptr, IMG_WIDTH, IMG_HEIGHT);
	img.data = (int *)mlx_get_data_addr(img.img_ptr, &img.bpp, &img.size_l, &img.endian);
	printf("image.bpp: %d\n", img.bpp);
	printf("image.size_l: %d\n", img.size_l);

	y = 0;
	while (++y < IMG_HEIGHT)
	{
		x = 0;
		img.data[y * IMG_WIDTH + x] = 0x000000FF;
		while (x < IMG_WIDTH)
		{
			++x;
		}
		++y;
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, img.img_ptr, 0, 0);
	mlx_loop(mlx->mlx_ptr);
	//mlx_destroy_image(mlx->mlx_ptr, img.img_ptr);
	return (0);
}
