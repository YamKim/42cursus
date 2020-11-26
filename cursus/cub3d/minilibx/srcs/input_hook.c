#include "cub3d.h"

int key_press(int key, t_loop *lv)
{
    if (key == KEY_W)
		move_forward(lv->player, lv->disp->map);
    if (key == KEY_S)
		move_backward(lv->player, lv->disp->map);
    if (key == KEY_A)
		turn_left(lv->player);
    if (key == KEY_D)
		turn_right(lv->player);
    if (key == KEY_ESC)
        exit(0);
    return (0);
}
