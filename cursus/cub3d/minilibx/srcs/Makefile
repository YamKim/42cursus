NAME = program.out
CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -L../ -lmlx -framework OpenGL -framework Appkit
LIBFT = -L./libft/ -lft

SRC = main.c \
	run_program.c \
	init_setting.c \
	parse_config.c \
	parse_map.c \
	player_motion.c \
	player_action.c \
	calc_vector.c \
	calc_dda.c \
	check_door_type.c \
	draw_untex_wall.c \
	draw_tex_wall.c \
	draw_sprite.c \
	draw_sprite_util.c \
	input_keyboard.c \
	check_validity.c \
	load_file.c \
	show_data.c \
	finish_program.c \
	save_bmp_image.c \
	get_bonus_texture.c \
	draw_background.c \
	animate_sprite.c \
	draw_hud.c \
	draw_hud_series.c \
	draw_skybox.c \
	get_close_sprite.c \
	input_mouse.c \
	set_animation.c \

SRCDIR = ./bonus
OBJDIR = ./objs

INC = -I./include

SRCS = $(addprefix $(SRCDIR)/, $(SRC))
OBJS = $(addprefix $(OBJDIR)/, $(SRC:.c=.o))

all: $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	mkdir $(OBJDIR) 2> /cev/null || true
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

$(NAME): $(SRCS)
	$(CC) $(CFLAGS) $(INC) $(LIBFT) $(MLXFLAGS) -o $(NAME) $^

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
