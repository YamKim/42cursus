#include <stdio.h>
#include <unistd.h>

#define ERR_ARG "Error: argument\n"
#define ERR_FILE "Error: Operation file corrupted\n"

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
	char		*board;
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
	if (tmp != 6)
		return (1);
	if (!is_valid_sh_config(sh))
		return (1);
	printf("sh->type: %c, sh->x: %f, sh->y: %f, sh->width: %d, sh->height: %d, sh->color: %c\n", sh->type, sh->x, sh->y, sh->width, sh->height, sh->color);
	return (0);
}

int
	set_sh_on_board()
{


}

int
	get_board_with_sh(FILE *file, t_info *info)
{
	int		tmp;
	t_shape	tmp_sh;

	while (get_sh_config(file, &tmp_sh))
	{
		if (!is_valid_sh_config(*tmp_sh))
			return (1);
		set_sh_on_board(info->board, &tmp_sh, );

	}	
}

#if 0
int
	init_board(t_info *info)
{
	info->bg.width = 0;
	info->bg.height = 0;
}
#endif

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
	if (get_sh_config(file, &(info.sh)))
		return (!exit_program(file, &info) && print_err(ERR_FILE));


	return (0);
}
