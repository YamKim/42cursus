#include "../mlx.h"
#include <stdio.h>
#include <stdlib.h>

#define X_EVENT_KEY_PRESS	2

#define KEY_ESC	53
#define KEY_W	13
#define KEY_S	1
#define KEY_D	2
#define KEY_A	0

typedef struct	s_param
{
	int			x;
	int			y;
}				t_param;

void	param_init(t_param *param)
{
	param->x = 0;
	param->y = 0;
}

int		get_key(int keycode, t_param *param)
{
	static int	a = 0;

	if (keycode == KEY_W)
		++(param->y);
	else if (keycode == KEY_S)
		--(param->y);
	else if (keycode == KEY_D)
		++(param->x);
	else if (keycode == KEY_A)
		--(param->x);
	else if (keycode == KEY_ESC)
		exit(0);
	printf("x: %3d, y: %3d\n", param->x, param->y);
	return (0);
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_veci	map;

	mlx	= mlx_init();
	mlx_win = mlx_new_window(mlx, 500, 500, "mlx_test"); 
	param_init(&param);
	mlx_hook(mlx_win, X_EVENT_KEY_PRESS, 0, &get_key, &param);
	mlx_loop(mlx);
}
