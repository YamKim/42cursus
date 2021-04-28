#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define ERR_ARG "Error: argument\n"
#define ERR_FILE "Error: Operation file corrupted\n"

typedef struct	s_board
{
	int			size;
	char		*data;
}				t_board;


typedef struct	s_bg
{
	int			width;
	int			height;
	char		color;
}				t_bg;

typedef struct	s_sh
{
	char		type;
	float		x;
	float		y;
	int			width;
	int			height;
	char		color;
	struct s_sh \
				*next;
}				t_sh;

typedef struct	s_info
{
	t_bg		bg;
	t_sh		sh;
	t_board		board;
}				t_info;

int
	ft_strlen(char *str)
{
	int itr;

	itr = 0;
	while (str[itr])
		++itr;
	return (itr);
}

int
	print_err(char *str)
{
	while (*str)
	{
		write(STDOUT_FILENO, str, 1);
		++str;
	}
	return (1);
}

int
	change_dimension(t_info *info, int y, int x)
{
	return ((int)(info->bg.height) * y + x);
}

int
	is_valid_bg_config(t_bg *bg)
{
	if (bg->width > 0 && bg->width <= 300 \
		&& bg->height > 0 && bg->height <= 300)
		return (1);
	return (0);
}

int
	get_bg_config(FILE *file, t_bg *bg)
{
	int	tmp;

	tmp = fscanf(file, "%d %d %c\n", &(bg->width), &(bg->height), &(bg->color));
	if (tmp != 3)
		return (1);
	if (!is_valid_bg_config(bg))
		return (1);
	printf("bg->width: %d, bg->height: %d, bg->color: %c\n", bg->width, bg->height, bg->color);
	return (0);
}

int
	is_valid_sh_config(t_sh *sh)
{
	if (sh->width > 0 && sh->height > 0 \
        && (sh->type == 'r' || sh->type == 'R'))
		return (1);
	return (0);
}

int
	get_sh_config(FILE *file, t_sh *sh)
{
	int	tmp;

	tmp = fscanf(file, "%c %f %f %d %d %c\n", &(sh->type), &(sh->x), &(sh->y), &(sh->width), &(sh->height), &(sh->color));
	if (tmp == -1)
		return (-1);
	if (tmp != 6)
		return (1);
	if (!is_valid_sh_config(sh))
		return (1);
	return (0);
}

int
	is_in_rectangle(float y, float x, t_sh *sh)
{
	int ybeg = sh->y;
	int yend = sh->y + sh->height;
	int xbeg = sh->x;
	int xend = sh->x + sh->width;

	if (((x < xbeg || xend < x))
		|| (y < ybeg) || (yend < y))
		return (0);
	if (((x - xbeg < 1.0f) || (xend - x < 1.0f))
		|| ((y - ybeg < 1.0f) || (yend - y < 1.0f)))
		return (2);
	return (1);
}

int
	set_shapes(FILE *file, t_info *info)
{
	char	*board_data;
	t_sh	tmp_sh;
	int		tmp;

	tmp = 0;
	board_data = info->board.data;
	while ((tmp = get_sh_config(file, &info->sh)) == 0)
	{			
		tmp_sh = info->sh;
		printf("sh->type: %c, sh->x: %f, sh->y: %f, sh->width: %d, sh->height: %d, sh->color: %c\n", tmp_sh.type, tmp_sh.x, tmp_sh.y, tmp_sh.width, tmp_sh.height, tmp_sh.color);
		for (int i = 0; i < info->bg.height; ++i) {
			for (int j = 0; j < info->bg.width; ++j) {
				int ret = is_in_rectangle(i, j, &(tmp_sh));
				if ((tmp_sh.type == 'r' && ret == 2)
					|| (tmp_sh.type == 'R' && ret))
					board_data[change_dimension(info, i, j)] = tmp_sh.color;
				}
		}
	}
	if (tmp == 1) // error exit case
		return (1);
	printf("set_shapes complete..!");
	return (0);
}

void
	show_board(t_info *info)
{
	t_bg	tmp_bg;
	char	c;

	tmp_bg = info->bg;
	for (int i = 0; i < tmp_bg.height; ++i)
	{
		for (int j = 0; j < tmp_bg.width; ++j)
		{
			c = info->board.data[change_dimension(info, i, j)];
			write(1, &c, 1);
		}
		write(1, "\n", 1);
	}
}

int
	init_board(t_info *info)
{
	t_board	tmp;

	tmp.size = info->bg.width * info->bg.height;
	tmp.data = (char *)malloc(sizeof(char) * tmp.size);
	if (!tmp.data)
		return (1);
	for (int i = 0; i < info->bg.height; ++i)
	{
		for (int j = 0; j < info->bg.width; ++j)
			tmp.data[change_dimension(info, i, j)] = info->bg.color;
	}
	info->board.data = tmp.data;
	return (0);
}

int
	exit_program(FILE *file, t_info *info)
{
	fclose(file);
	return (0);	
}

int main(int argc, char *argv[])
{
	FILE	*file;	
	t_info	info;

	if (argc != 2)
		return (print_err(ERR_ARG));
	if (!(file = fopen(argv[1], "r")))
		return (print_err(ERR_FILE));
	if (get_bg_config(file, &(info.bg)))
		return (!exit_program(file, &info) && print_err(ERR_FILE));
	if (init_board(&info))
		return (print_err(ERR_FILE));
	if (set_shapes(file, &info))
		return (!exit_program(file, &info) && print_err(ERR_FILE));
	show_board(&info);

	return (0);
}