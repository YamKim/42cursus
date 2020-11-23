#include "cub3d.h"

int	load_texture(t_texture *tex, char *file_name)
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			tmp;

	mlx_ptr = mlx_init();
	tex->ptr = mlx_xpm_file_to_image(mlx_ptr, file_name, &(tex->width), &(tex->height));
	if (tex == NULL)
		return (ERR_TEXTURE_CALL);
	tex->data = (int *)mlx_get_data_addr(tex->ptr, &tmp, &tmp, &tmp);	
	return (0);
}

void	check_texture(const t_disp disp)
{
	for (int k = 0; k < 8; ++k) {
		printf("%d set========================================\n", k);
		for (int j = 0; j < 8; ++j) {
			for (int i = 0; i < 8; ++i) {
				printf("%x ", (disp.texture[k]).data[j * 64 + i]);
				if ((i + 1) % 8 == 0) printf("\n");
			}
		}
		printf("\n");
	}
}

int	load_texture_group(t_disp *disp)
{
	int	error;

	error = 0;
    error |= load_texture(&(disp->texture[0]), "textures/eagle.xpm");
    error |= load_texture(&(disp->texture[1]), "textures/redbrick.xpm");
    error |= load_texture(&(disp->texture[2]), "textures/purplestone.xpm");
    error |= load_texture(&(disp->texture[3]), "textures/greystone.xpm");
    error |= load_texture(&(disp->texture[4]), "textures/bluestone.xpm");
    error |= load_texture(&(disp->texture[5]), "textures/mossy.xpm");
    error |= load_texture(&(disp->texture[6]), "textures/wood.xpm");
    error |= load_texture(&(disp->texture[7]), "textures/colorstone.xpm");
    error |= load_texture(&(disp->texture[8]), "textures/barrel.xpm");
    error |= load_texture(&(disp->texture[9]), "textures/greenlight.xpm");
    error |= load_texture(&(disp->texture[10]), "textures/pillar.xpm");
	if (error)
	{
		write(STDOUT_FILENO, ERR_MESSAGE, ft_strlen(ERR_MESSAGE)); 
		return (ERR_TEXTURE_CALL);
	}
	return (0);
}
