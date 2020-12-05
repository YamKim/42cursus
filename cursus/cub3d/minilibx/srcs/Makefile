NAME = program.out
CC = gcc

SRC = main.c \
	run_program.c \
	parse_config.c \
	parse_map.c \
	player_motion.c \
	player_motion2.c \
	calc_vector.c \
	calc_dda.c \
	draw_untex_wall.c \
	draw_tex_wall.c \
	draw_tex_background.c \
	draw_sprite.c \
	draw_item.c \
	draw_skybox.c \
	list_utils.c \
	list_utils2.c \
	ft_split.c \
	ft_atoi.c \
	string_utils.c \
	string_utils2.c \
	input_hook.c \
	check_validity.c \
	load_file.c \
	show_data.c \
	bonus_door.c \
	bonus_item.c


OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(SRC)
	$(CC) -L../ -lmlx -framework OpenGL -framework Appkit -o $(NAME) $^

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
