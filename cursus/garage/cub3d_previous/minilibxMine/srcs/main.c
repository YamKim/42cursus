// ���ϸ� main.c�� �ص�.

# include "../mlx.h"
# include <math.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>

// WASD
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2

// KEYBOARD ESC
# define K_ESC 53

#define MAP_WIDTH 24
#define MAP_HEIGHT 24
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

// EVENT KEY
#define X_EVENT_KEY_PRESS   2
#define X_EVENT_KEY_EXIT    17

typedef struct		s_vector
{
	double	x;
	double	y;
}					t_vector;

typedef struct    s_info
{
    double playerPositionX;
    double playerPositionY;
    double directionVectorX;
    double directionVectorY;
    double planeX;
    double planeY;
    void    *mlx;
    void    *win;
    double    moveSpeed;
    double    rotSpeed;
}                t_info;


int worldMap[MAP_WIDTH][MAP_HEIGHT] =
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

void verLine (t_info *info, int x, int y1, int y2, int color)
{
    int temp;

    temp = y1;
    while (temp <= y2)
    {
        mlx_pixel_put(info->mlx, info->win, x, temp, color);
        temp++;
    }
}

int main_loop(t_info *info)
{
    // // '����' �������� �ð�.
    // double time = 0;
    // // '����' �������� �ð�.
    // // ���� �������� �ð� - ���� �������� �ð�: �̵��Ÿ� ���� �� fps ����
    // double oldTime = 0;

    // ȭ�� ���� �� ���� ���� ����.
    // while���� ��ü �������� �׷����� �Է��� �д� ������ ��.
    int x;

    x = 0;
    while (x < SCREEN_WIDTH)
    {
        /* 
            ������ �������� playerPositionX, Y��.
            directionVectorX, Y�� �÷��̾��� �ʱ� '���⺤��'.
            planeX�� planeY�� ������ ���ߵ� ī�޶� ���.
            �Ʒ� for���� ray�� ��ġ(position) �� ����(direction) ���.
        */

        // cameraX �� for���� x���� ī�޶� ��� �� ���� ���� x��ǥ.
        double cameraX = (2 * x / (double)(SCREEN_WIDTH)) - 1;
        // cameraPlaneX == 0; cameraPlaneY == 0.66; dirVecX = -1; dirVecY = 0;
        // ������ ������ ���⺤�� + ī�޶���� * ���.
        double rayDirectionX = info->directionVectorX + info->planeX * cameraX;
        double rayDirectionY = info->directionVectorY + info->planeY * cameraX;

        /*
            DDAgorithm
        */
        // ���� player�� ��ġ�� �� �� ��ġ.(which box of the map)
        int mapX = (int)(info->playerPositionX);
        int mapY = (int)(info->playerPositionY);

        // ���� ��ġ���� ���� x���̵� �Ǵ� y���̵������ �Ÿ�.
        // �̸� ���� 'ù ��° x�� �� y��'�̶�� �θ� ��.
        double sideDistX;
        double sideDistY;

        // �Ʒ� �� ������ �� ������ ������������ ���ؼ��� ii2r github #6 ����. 
        // deltaDistX�� ù ��° x�鿡�� �� ���� x������� ������ �̵��Ÿ�.
        // �� ��� x�� 1��ŭ �̵�.
        // abs�Լ��� ���� ���밪
        // fabs�Լ��� �Ǽ� ���밪
        double deltaDistX = fabs(1 / rayDirectionX);
        // deltaDistY�� ù ��° y�鿡�� �� ���� y������� ������ �̵��Ÿ�.
        // �� ��� y�� 1��ŭ �̵�.
        double deltaDistY = fabs(1 / rayDirectionY);

        // ������ �̵��Ÿ��� ����� �� ����� ����.
        double perpWallDist;

        // DDAgorithm�� �ݺ����� ������ ������ x, y�������� �� �� ĭ�� ����.
        // ������ ���⿡ ���� ��� �������� �ǳʶٴ��� �޶���.
        // �� ������ stepX, Y�� +1, -1 �� �� �ϳ��� �����.
        int stepX;
        int stepY;

        /*
            hit�� ���� �ε������� �Ǻ��ϱ� ���� ������.
            �ε����ٴ� ���� ������ �����ϱ� ���� ������ ��.
            ���� ���� �ε����µ� �װ� x�鿡 �ε��� �Ŷ�� side = 0��.
            y�鿡 �ε����ٸ� 1�� ��.
            ���� x��, y���� � ĭ�� ��谡 �Ǵ� ���� �ǹ���.
        */
        int hit = 0;
        int side;

        /*
            DDAgorithm�� �����ϱ� ���� 
            stepX, Y �׸��� sideDistX, Y�� ���� �־��ִ� �κ��̴�.
            rayDirectionX�� ������� ���� player���� �ް��̶�� ���̰�,
            ������ ���� player���� �������̶�� ���̴�.
            sideDistX�� ���� rayDirectionX ���� ����� ���
            ������ ���������� �̵��ϴ� ó�� ������ x������� �Ÿ��� �ȴ�.
            sideDistY�� ���� rayDirectionY ���� ����� ���
            ������ �������� �̵��ϴ� ó�� ������ y������� �Ÿ��� �ȴ�.
            rayDirectionX�� ����� ��� sideDistX�� 
            mapX + 1���� ���� ��ġ playerPositionX�� ���ְ� deltaDistX�� ���� �����.
            �ݴ��� ��� playerPositionX���� mapX�� ���ְ� deltaDistX�� ���� �����.
        */
        if (rayDirectionX < 0)
        {
            stepX = -1;
            sideDistX = (info->playerPositionX - mapX) * deltaDistX;
        }
        else
        {
            stepX = 1;
            sideDistX = (mapX + 1.0 - info->playerPositionX) * deltaDistX;
        }
        if (rayDirectionY < 0)
        {
            stepY = -1;
            sideDistY = (info->playerPositionY - mapY) * deltaDistY;
        }
        else
        {
            stepY = 1;
            sideDistY = (mapY + 1.0 - info->playerPositionY) * deltaDistY;
        }

        /*
            DDAgorithm ������ �Ϸ��߰�, ���� �װ��� �����ϴ� �κ�.
            �Ʒ� while���� `���� �ε��� ������` �Ź� �� ĭ�� ���� �̵�.
            �ݺ��� ������ x�������� �� ĭ �Ǵ� y�������� �� ĭ ����.
            ���� ������ ������ x�� ����� ������ ��ġ�Ѵٸ�, x�������θ� �� ĭ �����ϸ� ��.
            ������ ������ ������ <sideDistX, Y>���� <deltaDistX, Y>�� �������鼭 ������Ʈ��.
        */
        while (hit == 0)
        {
            // ���� map �ڽ��� �̵��ϰų� x, y ���� �� �� �ϳ��� �̵��Ѵ�.
            if (sideDistX < sideDistY)
            {
                sideDistX += deltaDistX;
                mapX += stepX; // stepX �� 1, -1 �� �ϳ�.
                side = 0; // x�鿡 �ε����ٸ� side = 0
            }
            else
            {
                sideDistY += deltaDistY;
                mapY += stepY; // stepY�� 1, -1 �� �ϳ�.
                side = 1; // y�鿡 �ε����ٸ� side = 1
            }
            // ray�� ���� �������� Ȯ���ϴ� �۾�
            if (worldMap[mapX][mapY] > 0)
                hit = 1;
        }
        /*
            ���� ���� DDAgorithm�� �Ϸ��.
            ���� ������ ���������� �������� �̵��Ÿ��� ����� ������.
            ������ ���������� �������� �̵��Ÿ��� ���� ���̸� ����ϴ� �� ����.
            H------------ :wall
            | \          \: �����Ÿ�
            |  \         |: ������ camera plane������ �Ÿ�.
            -----P------- :camera plane
            P�� �������� �������� �����Ÿ��� ����Ѵٸ� fisheye ���ۿ��� ��Ÿ��.
            ���� �����κ��� cameraPlane������ �Ÿ��� ����ؾ�.
            �̿� ���� �ڼ��� ������ �ε��� ���� ����.
            ���� �Ʒ� if-else���� fisheye (side)effect�� �����ϴ� �ڵ�.
            (1 - stepX) / 2�� stepX�� -1�̸� 1�̵ǰ� 1�̸� 0�� �ȴ�.(-1 or 0)
            �ش� ������ mapX - playerPositionX�� < 0 �� ��, �� �� ������ �� ��
            ���̿� 1�� �����ֱ� ���� �ڵ��̴�.
            �����Ÿ��� ����ϴ� ����� �̷���. 
            ���� ������ ó������ �ε��� ���� x���̸� 
                mapX - playerPositionX + (1 - stepX / 2)��
                ������ x�������� �� ĭ�̳� �������� ��Ÿ����.(���� �ƴϾ ��.)
                rayDirectionX�� �����ִ� ������ ������ ���� �����Ÿ����� ũ�� ����.
            y�鿡 ó�� �ε����� ���� ���� ������ ����.
            mapX - playerPostionX�� �������� ������ rayDirectionX�� ������ ������
            ���� ���� �׻� �����.
        */
        if (side == 0)
            perpWallDist = (mapX - info->playerPositionX + (1 - stepX) / 2) / rayDirectionX;
        else
            perpWallDist = (mapY - info->playerPositionY + (1 - stepY) / 2) / rayDirectionY;

        // ��ũ���� �׸� line�� ���̸� ���.
        int lineHeight = (int)(SCREEN_HEIGHT / perpWallDist);
        /*
            ���� ����� �Ÿ��� ������ ȭ�鿡 �׷��� �ϴ� ���� ���̸� ���� �� �ִ�.
            ���� �� ���� �׸��ų� ���� �׸��� ������ 2 * lineHeight ���� ���� ���� ���� �ִ�.
            ������ ���� lineHeight�κ��� �츮�� ���� �׸� ��ġ�� �������� ������ ���س� �� �ִ�.
            ���࿡ ���� ���� (0 ~ SCREEN_HEIGHT)�� ����� ��� 
            ���� 0�� SCREEN_HEIGHT - 1�� �����Ѵ�.
                +) drawStart�� End�� 2�� ���� ������ ���ϴ� ������
                   SCREEN_HEIGHT���� drawEnd�� Ŀ���� �ɱ� �ȵɱ �����غ��� �� �� �ִ�.
        */
        int drawStart = (-lineHeight / 2) + (SCREEN_HEIGHT / 2);
        if (drawStart < 0)
            drawStart = 0;
        int drawEnd = (lineHeight / 2) + (SCREEN_HEIGHT / 2);
        if (drawEnd >= SCREEN_HEIGHT)
            drawEnd = SCREEN_HEIGHT - 1;

        int color;
        if (worldMap[mapX][mapY] == 1)
            color = 0xFF0000;
        else if (worldMap[mapX][mapY] == 2)
            color = 0x00FF00;
        else if (worldMap[mapX][mapY] == 3)
            color = 0x0000FF;
        else if (worldMap[mapX][mapY] == 4)
            color = 0xFFFFFF;
        else
            color = 0x123145;

        // x, y side�� ��⸦ �޸�����.
        if (side == 1)
            color = color / 2;
        /* 
            verLine �Լ��� ���� ���� �ߴ´�.
            �� �Լ��� x��ǥ���� drawStart~drawEnd���� color ������ �ȼ��� �׸���.
            (x, drawStart) ~ (x, drawEnd)���� color���� �ǰ�
            x�� ���� �����ϸ� ȭ���� ���� ������ ������ ������ �� ���𰡰� �׷����� ���� ����غ���.
        */
        verLine(info, x, drawStart, drawEnd, color);
        x++;
    } 
}

int key_press(int key, t_info *info)
{
    // WS
    if (key == KEY_W)
    {
        if (!worldMap[(int)(info->playerPositionX + info->directionVectorX * info->moveSpeed)][(int)(info->playerPositionY)])
            info->playerPositionX += info->directionVectorX * info->moveSpeed;
        if (!worldMap[(int)(info->playerPositionX)][(int)(info->playerPositionY + info->directionVectorY * info->moveSpeed)])
            info->playerPositionY += info->directionVectorY * info->moveSpeed;
    }

    if (key == KEY_S)
    {
        /*  
            SŰ�� ������ �ڷ� �̵��Ѵ�.
            �̶�, �̵��ϰ��� �ϴ� ��ġ�� �� �󿡼� ������ 0�̾�� �Ѵ�.
            �ֳ��ϸ� �� ������ 1~4�� �ǹ��ϴ� �ٴ� ����� �� ���� ��ֹ��̱� �����̴�.
            ���� [2][2]���� �ִٰ� �� ��,
            ��ġ�� ������ �� �������� ������ ���� �ٶ󺸰� sŰ�� ������
            ���� �Ʒ� �������� �̵��ؾ� �Ѵ�.
            �̸� ���ؼ��� x�� ��ĭ �������� �̵���Ű��,
            y�� ��ĭ �Ʒ��� �̵���Ű�� �ȴ�.
            �Ʒ��� ������ ��ü������ ������ ���̴�.
        */
        if (!worldMap[(int)(info->playerPositionX - info->directionVectorX * info->moveSpeed)][(int)(info->playerPositionY)])
            info->playerPositionX -= info->directionVectorX * info->moveSpeed;
        if (!worldMap[(int)(info->playerPositionX)][(int)(info->playerPositionY - info->directionVectorY * info->moveSpeed)])
            info->playerPositionY -= info->directionVectorY * info->moveSpeed;
    }

    // AD
    if (key == KEY_A)
    {
        double oldDirectionX = info->directionVectorX;
        info->directionVectorX = info->directionVectorX * cos(info->rotSpeed) - info->directionVectorY * sin(info->rotSpeed);
        info->directionVectorY = oldDirectionX * sin(info->rotSpeed) + info->directionVectorY * cos(info->rotSpeed);
        double oldPlaneX = info->planeX;
        info->planeX = info->planeX * cos(info->rotSpeed) - info->planeY * sin(info->rotSpeed);
        info->planeY = oldPlaneX * sin(info->rotSpeed) + info->planeY * cos(info->rotSpeed);
    }

    // https://github.com/ChoiKanghun/images/blob/master/1024_1.jpg?raw=true 
    // �� �̹����� �������� �˻�����. �ٽ��� �Ǵ� �����̴�. �� ���Ŀ� ���� �ڼ��� ������
    // https://github.com/minckim0/cub3d_lect �ش� �� ���� �� pdf 62~66 ������ ����.
    if (key == KEY_D)
    {
        double oldDirectionX = info->directionVectorX;
        info->directionVectorX = info->directionVectorX * cos(-info->rotSpeed) - info->directionVectorY * sin(-info->rotSpeed);
        info->directionVectorY = oldDirectionX * sin(-info->rotSpeed) + info->directionVectorY * cos(-info->rotSpeed);
        double oldPlaneX = info->planeX;
        info->planeX = info->planeX * cos(-info->rotSpeed) - info->planeY * sin(-info->rotSpeed);
        info->planeY = oldPlaneX * sin(-info->rotSpeed) + info->planeY * cos(-info->rotSpeed);
    }
    if (key == K_ESC)
        exit(0);
    return (0);
}

int main()
{
    t_info info;
    info.mlx = mlx_init();

    // info�� �Ʒ� �ʵ� ��θ� ������ �ִ�.
    info.playerPositionX = 12;
    info.playerPositionY = 5;
    info.directionVectorX = -1;
    info.directionVectorY = 0;
    info.planeX = 0;
    info.planeY = 0.66;
    info.moveSpeed = 0.05;
    info.rotSpeed = 0.05;

    // â�� ���.
    info.win = mlx_new_window(info.mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "mlx");

    // main_loop�Լ��� ����. �� �κ��� �߿�.
    mlx_loop_hook(info.mlx, &main_loop, &info);
    // key_press�� ���� �̺�Ʈ�� ���.
    mlx_hook(info.win, X_EVENT_KEY_PRESS, 0, &key_press, &info);

    mlx_loop(info.mlx);
}
