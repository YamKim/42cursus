/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_bmp_image.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <yekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 12:30:18 by yekim             #+#    #+#             */
/*   Updated: 2020/12/29 13:40:51 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	type_conversion(unsigned char *src, int n)
{
	src[0] = (unsigned char)n;
	src[1] = (unsigned char)(n >> 8);
	src[2] = (unsigned char)(n >> 16);
	src[3] = (unsigned char)(n >> 24);
}

static int	put_bmp_info(int fd, int file_size, t_disp *disp)
{
	unsigned char	bmp_header[BMP_HEADER_SIZE];

	ft_bzero(bmp_header, BMP_HEADER_SIZE);
	bmp_header[0] = 'B';
	bmp_header[1] = 'M';
	type_conversion(&bmp_header[2], file_size);
	bmp_header[10] = (unsigned char)54;
	bmp_header[14] = (unsigned char)40;
	type_conversion(&bmp_header[18], disp->w);
	type_conversion(&bmp_header[22], disp->h);
	bmp_header[26] = (unsigned char)1;
	bmp_header[28] = (unsigned char)(8 * BMP_PIXEL_SIZE);
	if (write(fd, bmp_header, BMP_HEADER_SIZE) < 0)
		return (ERR_SAVE_BMP);
	return (0);
}

static int	put_bmp_color(int fd, int pad, t_disp *disp)
{
	int				y;
	int				x;
	int				color;
	unsigned char	zero[BMP_PIXEL_SIZE];
	int				ret;

	ret = 0;
	ft_bzero(zero, BMP_PIXEL_SIZE);
	y = disp->h;
	while (--y >= 0)
	{
		x = -1;
		while (++x < disp->w)
		{
			color = disp->img.data[y * disp->w + x];
			if ((ret = write(fd, &color, BMP_PIXEL_SIZE)) < 0)
				return (ERR_SAVE_BMP);
			if ((ret = write(fd, zero, pad)) < 0)
				return (ERR_SAVE_BMP);
		}
	}
	return (0);
}

int			save_bmp_image(t_loop *lv)
{
	int	fd;
	int	file_size;
	int	row_pixel_size;
	int	pad;
	int	ret;

	printf("START CAPTURE================================\n");
	ret = 0;
	run_raycasting(lv);
	row_pixel_size = (lv->disp->w * BMP_PIXEL_SIZE) % BMP_PIXEL_ALIGN;
	pad = row_pixel_size % BMP_PIXEL_ALIGN;
	pad = (BMP_PIXEL_ALIGN - pad) % BMP_PIXEL_ALIGN;
	file_size = 14 + 40 + BMP_PIXEL_SIZE * (lv->disp->w + pad) * lv->disp->h;
	if ((fd = open(FILE_NAME_BMP, O_WRONLY | O_CREAT | O_TRUNC, 0644)) < 0)
		ret = ERR_SAVE_BMP;
	if (ret == 0)
		ret = put_bmp_info(fd, file_size, lv->disp);
	if (ret == 0)
		ret = put_bmp_color(fd, pad, lv->disp);
	close(fd);
	finish_program(lv);
	printf("FINISH CAPTURE================================\n");
	return (ret);
}
