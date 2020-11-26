#include "cub3d.h"

int key_press(int key, t_player *player)
{
    if (key == KEY_W)
		move_forward(player);
    if (key == KEY_S)
		move_backward(player);
    if (key == KEY_A)
		turn_left(player);
    if (key == KEY_D)
		turn_right(player);
    if (key == KEY_ESC)
        exit(0);
    return (0);
}
