#include "cub3d.h"

t_texture	load_texture(char *file_name)
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			tmp;
	t_texture	ret;

	mlx_ptr = mlx_init();
	ret.ptr = mlx_xpm_file_to_image(mlx_ptr, file_name, &ret.width, &ret.height);
	ret.data = (int *)mlx_get_data_addr(ret.ptr, &tmp, &tmp, &tmp);	
	return (ret);
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

void	load_texture_group(t_disp *disp)
{
    disp->texture[0] = load_texture("textures/eagle.xpm");
    disp->texture[1] = load_texture("textures/redbrick.xpm");
    disp->texture[2] = load_texture("textures/purplestone.xpm");
    disp->texture[3] = load_texture("textures/greystone.xpm");
    disp->texture[4] = load_texture("textures/bluestone.xpm");
    disp->texture[5] = load_texture("textures/mossy.xpm");
    disp->texture[6] = load_texture("textures/wood.xpm");
    disp->texture[7] = load_texture("textures/colorstone.xpm");
}
