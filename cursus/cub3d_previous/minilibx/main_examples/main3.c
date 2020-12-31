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

#define mapWidth 24
#define mapHeight 24
#define screenWidth 640
#define screenHeight 480

// EVENT KEY
#define X_EVENT_KEY_PRESS   2
#define X_EVENT_KEY_EXIT    17



/*
    texture�� ������ ���ؼ��� verLine() �Լ��� �̿��� �������� �׸��� ����� ������ �Ѵ�.
    ���, �ȼ��� �ϳ��ϳ� �׷��� ���̴�.
    �츮�� ����� ����� ���� �����ϸ� 2����¥�� '����'�� �̿�, 
    �ѹ��� (�����)ȭ���� ����ϴ� ���̴�.

    �Ʒ��� texWidth, texHeight�� �ؽ����� �ؼ� �ʺ�, ���� ���̴�.

*/
#define texWidth 64
#define texHeight 64

// get_img_data_addr �Լ����� �� ������ ���� �ִ� ����ü.
typedef struct    s_img
{
    void    *img;
    int        *data;

    int        size_l;
    int        bpp;
    int        endian;
    int     img_width;
    int     img_height;
}                t_img;

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

// textured���� �Ʒ� �� ������ �߰���.
    t_img   img;
    int     buf[screenHeight][screenWidth];
    int     **texture;

}                t_info;

int calculateAndSaveToMap(t_info *info);
void imageDraw(t_info *info);

// �ٲ� ��.
int    worldMap[mapWidth][mapHeight] =
{
  {8,8,8,8,8,8,8,8,8,8,8,4,4,6,4,4,6,4,6,4,4,4,6,4},
  {8,0,0,0,0,0,0,0,0,0,8,4,0,0,0,0,0,0,0,0,0,0,0,4},
  {8,0,3,3,0,0,0,0,0,8,8,4,0,0,0,0,0,0,0,0,0,0,0,6},
  {8,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},
  {8,0,3,3,0,0,0,0,0,8,8,4,0,0,0,0,0,0,0,0,0,0,0,4},
  {8,0,0,0,0,0,0,0,0,0,8,4,0,0,0,0,0,6,6,6,0,6,4,6},
  {8,8,8,8,0,8,8,8,8,8,8,4,4,4,4,4,4,6,0,0,0,0,0,6},
  {7,7,7,7,0,7,7,7,7,0,8,0,8,0,8,0,8,4,0,4,0,6,0,6},
  {7,7,0,0,0,0,0,0,7,8,0,8,0,8,0,8,8,6,0,0,0,0,0,6},
  {7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,6,0,0,0,0,0,4},
  {7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,6,0,6,0,6,0,6},
  {7,7,0,0,0,0,0,0,7,8,0,8,0,8,0,8,8,6,4,6,0,6,6,6},
  {7,7,7,7,0,7,7,7,7,8,8,4,0,6,8,4,8,3,3,3,0,3,3,3},
  {2,2,2,2,0,2,2,2,2,4,6,4,0,0,6,0,6,3,0,0,0,0,0,3},
  {2,2,0,0,0,0,0,2,2,4,0,0,0,0,0,0,4,3,0,0,0,0,0,3},
  {2,0,0,0,0,0,0,0,2,4,0,0,0,0,0,0,4,3,0,0,0,0,0,3},
  {1,0,0,0,0,0,0,0,1,4,4,4,4,4,6,0,6,3,3,0,0,0,3,3},
  {2,0,0,0,0,0,0,0,2,2,2,1,2,2,2,6,6,0,0,5,0,5,0,5},
  {2,2,0,0,0,0,0,2,2,2,0,0,0,2,2,0,5,0,5,0,0,0,5,5},
  {2,0,0,0,0,0,0,0,2,0,0,0,0,0,2,5,0,5,0,5,0,5,0,5},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5},
  {2,0,0,0,0,0,0,0,2,0,0,0,0,0,2,5,0,5,0,5,0,5,0,5},
  {2,2,0,0,0,0,0,2,2,2,0,0,0,2,2,0,5,0,5,0,0,0,5,5},
  {2,2,2,2,1,2,2,2,2,2,2,1,2,2,2,5,5,5,5,5,5,5,5,5}
};

int main_loop(t_info *info)
{
    calculateAndSaveToMap(info);
    imageDraw(info);

    // warning ������.
    return (0);
}

void imageDraw(t_info *info)
{
    for (int y = 0; y < screenHeight; y++)
        for (int x = 0; x < screenWidth; x++)
            info->img.data[y * screenWidth + x] = info->buf[y][x];

    mlx_put_image_to_window(info->mlx, info->win, info->img.img, 0, 0);
}

int calculateAndSaveToMap(t_info *info)
{
    // ȭ�� ���� �� ���� ���� ����.
    // while���� ��ü �������� �׷����� �Է��� �д� ������ ��.
    int x;

        x = 0;
    while (x < screenWidth)
    {
        // cameraX �� for���� x���� ī�޶� ��� �� ���� ���� x��ǥ.
        double cameraX = (2 * x / (double)(screenWidth)) - 1;
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
        int lineHeight = (int)(screenHeight / perpWallDist);
        /*
            ���� ����� �Ÿ��� ������ ȭ�鿡 �׷��� �ϴ� ���� ���̸� ���� �� �ִ�.
            ���� �� ���� �׸��ų� ���� �׸��� ������ 2 * lineHeight ���� ���� ���� ���� �ִ�.
            ������ ���� lineHeight�κ��� �츮�� ���� �׸� ��ġ�� �������� ������ ���س� �� �ִ�.
            ���࿡ ���� ���� (0 ~ screenHeight)�� ����� ��� 
            ���� 0�� screenHeight - 1�� �����Ѵ�.
                +) drawStart�� End�� 2�� ���� ������ ���ϴ� ������
                   screenHeight���� drawEnd�� Ŀ���� �ɱ� �ȵɱ �����غ��� �� �� �ִ�.
        */
        int drawStart = (-lineHeight / 2) + (screenHeight / 2);
        if (drawStart < 0)
            drawStart = 0;
        int drawEnd = (lineHeight / 2) + (screenHeight / 2);
        if (drawEnd >= screenHeight)
            drawEnd = screenHeight - 1;

        // texturing calculations
        // 1�� ���ִ� ������ 0��° �ؽ��ĵ� 0, ���� ��� 0�̱� ����.
        // 1�� ���� �ʴ´ٸ� ��� �ɱ�?
        // �Ƹ� �������ڸ��� �޹����� ���� ������ �ɾ������ �ϸ� 
        // segmentation fault�� �� ���̴�.
        int texNum = worldMap[mapX][mapY] - 1;
        // int textNum = worldMap[mapX][mapY];

        // wallX�� ���� ���� x��� �ε��� ���(side == 0)
        // ���� Y��ǥ�� �ȴ�.
        // wallX�� ���� �ؽ�ó�� x��ǥ�� ���ؼ��� ����Ѵ�.
        double wallX;
        if (side == 0)
            wallX = info->playerPositionY + perpWallDist * rayDirectionY;
        else
            wallX = info->playerPositionX + perpWallDist * rayDirectionX;
        wallX -= floor(wallX);

        // texX�� texture�� x��ǥ�� ��Ÿ����.
        // x coordinate on the texture
        int texX = (int)(wallX * (double)texWidth);
        if (side == 0 && rayDirectionX > 0)
            texX = texWidth - texX - 1;
        if (side == 1 && rayDirectionY < 0)
            texX = texWidth - texX - 1;

        /*
            texY�� �����ϴ� �ݺ���.
            step�� ��ũ�� �ȼ��� texture ��ǥ�� �󸶳� ���������� ������ ����.
            buffer[y][x]�� ���� color�� texture �迭���� �����´�.
        */
        // How much to increase the texture coordinate perscreen pixel
        double step = 1.0 * texHeight / lineHeight;
        // Starting texture coordinate
        double texPos = (drawStart - screenHeight / 2 + lineHeight / 2) * step;
        for (int y = drawStart; y < drawEnd; y++)
        {
            // Cast the texture coordinate to integer, and mask with (texHeight - 1) in case of overflow
            int texY = (int)texPos & (texHeight - 1);
            texPos += step;
            int color = info->texture[texNum][texHeight * texY + texX];
            // ������ ���� y�鿡 �ε��� ���(side == 1).
            // ����ǥ���� ���� ������ �� �˰� �����.
            // �������� 2�� �������ν� RGB���� �ݰ���Ų��.
            // ����Ʈ ������ �ϰ� 01111111 01111111 01111111(835711)�� & �����ϸ�
            // ��ο� ���� �� �� �ִٴµ� �׳� �ܿ��� ���ʹ�.
            if (side == 1)
                color = (color >> 1) & 8355711;
            info->buf[y][x] = color;
        }
        x++;
    }
	return (1);
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

/*
    https://42kchoi.tistory.com/229?category=886844
    �� ��ũ���� �����ߵ��� mlx_png_file_to_image�� �޸� ���� �̽��� �ֱ� ������,
    mlx_xpm_file_to_image�� ����Ѵ�.
    ����� ���⼭ path�� ����δ�.
*/
void    load_image(t_info *info, int *texture, char *path, t_img *img)
{
    img->img = mlx_xpm_file_to_image(info->mlx, path, &img->img_width, &img->img_height);
    img->data = (int *)mlx_get_data_addr(img->img, &img->bpp, &img->size_l, &img->endian);
    for (int y = 0; y < img->img_height; y++)
    {
        for (int x = 0; x < img->img_width; x++)
        {
            texture[img->img_width * y + x] = img->data[img->img_width * y + x];
        }
    }
    mlx_destroy_image(info->mlx, img->img);
}

void    load_texture(t_info *info)
{
    t_img    img;

    load_image(info, info->texture[0], "textures/eagle.xpm", &img);
    load_image(info, info->texture[1], "textures/redbrick.xpm", &img);
    load_image(info, info->texture[2], "textures/purplestone.xpm", &img);
    load_image(info, info->texture[3], "textures/greystone.xpm", &img);
    load_image(info, info->texture[4], "textures/bluestone.xpm", &img);
    load_image(info, info->texture[5], "textures/mossy.xpm", &img);
    load_image(info, info->texture[6], "textures/wood.xpm", &img);
    load_image(info, info->texture[7], "textures/colorstone.xpm", &img);
}


int main()
{
    t_info info;
    info.mlx = mlx_init();

    // info�� �Ʒ� �ʵ� ��θ� ������ �ִ�.
    info.playerPositionX = 22.0;
    info.playerPositionY = 11.5;
    info.directionVectorX = -1.0;
    info.directionVectorY = 0.0;
    info.planeX = 0.0;
    info.planeY = 0.66;
    info.moveSpeed = 0.05;
    info.rotSpeed = 0.05;


    if (!(info.texture = (int **)malloc(sizeof(int *) * 8)))
        return (-1);
    for (int i = 0; i < 8; i++)
        if (!(info.texture[i] = (int *)malloc(sizeof(int) * (texHeight * texWidth))))
            return (-1);

    for (int i = 0; i < 8; i++)
        for (int j = 0; j < texHeight * texWidth; j++)
            info.texture[i][j] = 0;

    /*
        info.texture ������ ������ ���� ����� �ִµ�,
            int        texture[8][texHeight * texWidth];
        �̰��� �ǹ��ϴ� �ٴ� �� 8���� ������ �ؽ��ĸ� ������ �� �ְ�,
        �� ũ�Ⱑ texHeight * texWidth ��� ���̴�.
    */
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < texHeight * texWidth; j++)
            info.texture[i][j] = 0;

    load_texture(&info);

    // textured���� �߰��� �ڵ� �� ��.
    info.win = mlx_new_window(info.mlx, screenWidth, screenHeight, "mlx");
    info.img.img = mlx_new_image(info.mlx, screenWidth, screenHeight);
    info.img.data = (int *)mlx_get_data_addr(info.img.img, &info.img.bpp, &info.img.size_l, &info.img.endian);

    // �Ʒ� �ڵ���� ���� ������ �ϴ� �� �ñ��ϴٸ� �Ʒ� ��ũ���� �����ص� ������ ����.
    // https://42kchoi.tistory.com/229
    mlx_loop_hook(info.mlx, &main_loop, &info);
    mlx_hook(info.win, X_EVENT_KEY_PRESS, 0, &key_press, &info);
    mlx_loop(info.mlx);    
}
