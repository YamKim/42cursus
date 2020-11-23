#include "cub3d.h"

int	load_tex(t_tex *tex, char *file_name)
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

void	check_tex(const t_disp disp)
{
	for (int k = 0; k < 8; ++k) {
		printf("%d set========================================\n", k);
		for (int j = 0; j < 8; ++j) {
			for (int i = 0; i < 8; ++i) {
				printf("%x ", (disp.tex[k]).data[j * 64 + i]);
				if ((i + 1) % 8 == 0) printf("\n");
			}
		}
		printf("\n");
	}
}

int	load_tex_group(t_disp *disp)
{
	int	error;

	error = 0;
    error |= load_tex(&(disp->tex[0]), "textures/eagle.xpm");
    error |= load_tex(&(disp->tex[1]), "textures/redbrick.xpm");
    error |= load_tex(&(disp->tex[2]), "textures/purplestone.xpm");
    error |= load_tex(&(disp->tex[3]), "textures/greystone.xpm");
    error |= load_tex(&(disp->tex[4]), "textures/bluestone.xpm");
    error |= load_tex(&(disp->tex[5]), "textures/mossy.xpm");
    error |= load_tex(&(disp->tex[6]), "textures/wood.xpm");
    error |= load_tex(&(disp->tex[7]), "textures/colorstone.xpm");
    error |= load_tex(&(disp->tex[8]), "textures/barrel.xpm");
    error |= load_tex(&(disp->tex[9]), "textures/greenlight.xpm");
    error |= load_tex(&(disp->tex[10]), "textures/pillar.xpm");
	if (error)
	{
		write(STDOUT_FILENO, ERR_MESSAGE, ft_strlen(ERR_MESSAGE)); 
		return (ERR_TEXTURE_CALL);
	}
	return (0);
}
