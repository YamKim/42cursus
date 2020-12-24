NAME = program.out
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC = main.c \
	run_program.c \
	init_setting.c \
	parse_config.c \
	parse_map.c \
	get_bonus_texture.c \
	set_animation.c \
	player_motion.c \
	player_action.c \
	calc_vector.c \
	calc_dda.c \
	check_door_type.c \
	draw_untex_wall.c \
	draw_tex_wall.c \
	draw_background.c \
	draw_sprite.c \
	draw_sprite_util.c \
	animate_sprite.c \
	get_close_sprite.c \
	draw_skybox.c \
	draw_hud.c \
	draw_hud_series.c \
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
	save_bmp_image.c


OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) -L../ -lmlx -framework OpenGL -framework Appkit -o $(NAME) $^

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
