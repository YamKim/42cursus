#include "cub3d.h"

static void	int_to_char(int n, unsigned char *src)
{
	src[0] = (unsigned char)n;
	src[1] = (unsigned char)(n >> 8);
	src[2] = (unsigned char)(n >> 16);
	src[3] = (unsigned char)(n >> 24);
}

static int	write_bmp_header(int fd, int file_size, t_disp *disp)
{
	int				ret;
	unsigned char	bmp_header[54];

	ft_bzero(bmp_header, 54);
	ft_memcpy(bmp_header, "BM", sizeof(char) * 2);
	int_to_char(file_size, bmp_header + 2);
	bmp_header[10] = (unsigned char)54;
	bmp_header[14] = (unsigned char)40;
	int_to_char(disp->w, bmp_header + 18);
	int_to_char(disp->h, bmp_header + 22);
	bmp_header[26] = (unsigned char)1;
	bmp_header[28] = (unsigned char)24;
	ret = write(fd, bmp_header, 54);
	return (ret);
}

int			my_mlx_pixel_get(t_img *img, int x, int y)
{
	char	*dst;

	dst = (char *)img->data + (y * img->size_l + x * (img->bpp / 8));
	return (*(unsigned int*)dst);
}

int	get_color(t_disp *disp, int x, int y)
{
	int			color;
	int			rgb;

	color = my_mlx_pixel_get(&disp->img, x, y);
	rgb = (color & 0xFF0000) | (color & 0x00FF00) | (color & 0x0000FF);
	return (rgb);
}

static int	write_bmp_data(int fd, int pad, t_disp *disp)
{
	int				i;
	int				j;
	int				color;
	unsigned char	zero[3];

	i = -1;
	while (++i < 3)
		zero[i] = 0;
	i = disp->h + 1;
	while (--i > 0)
	{
		j = -1;
		while (++j < disp->w)
		{
			color = get_color(disp, j, i);
			if (write(fd, &color, 3) < 0)
				return (0);
			if (pad > 0 && write(fd, &zero, pad) < 0)
				return (0);
		}
	}
	return (1);
}

int			save_bmp_image(t_loop lv, t_disp *disp)
{
	int		fd;
	int		file_size;
	int		pixel_bytes_per_row;
	int		pad;

	main_loop(&lv);
	pixel_bytes_per_row = disp->w * 3;
	pad = (4 - pixel_bytes_per_row % 4) % 4;
	file_size = 14 + 40 + 3 * (disp->w + pad) * disp->h;
	if ((fd = open("screenshot.bmp", O_RDWR | O_CREAT | O_TRUNC, 0644)) < 0)
		return (0);
	if (!(write_bmp_header(fd, file_size, disp)) || !(write_bmp_data(fd, pad, disp)))
		return (0);
	close(fd);
	return (1);
}
