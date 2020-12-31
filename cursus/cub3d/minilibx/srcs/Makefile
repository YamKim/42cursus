NAME = cub3D
CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -L../ -lmlx -framework OpenGL -framework Appkit
LIBFT = -L./libft/ -lft

SRC = main.c \
	run_program.c \
	init_setting.c \
	parse_config.c \
	parse_map.c \
	check_file.c \
	player_motion.c \
	player_direction.c \
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
	load_texture.c \
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

SRC_BONUS = main.c \
	run_program.c \
	run_raycasting.c \
	init_setting.c \
	init_setting2.c \
	parse_config.c \
	parse_map.c \
	check_file.c \
	player_motion.c \
	player_direction.c \
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
	load_texture.c \
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

SRCDIR = ./general
OBJDIR = ./general/objs
SRCDIR_BONUS = ./bonus
OBJDIR_BONUS = ./bonus/objs

INC = -I./include

SRCS = $(addprefix $(SRCDIR)/, $(SRC))
OBJS = $(addprefix $(OBJDIR)/, $(SRC:.c=.o))
SRCS_BONUS = $(addprefix $(SRCDIR_BONUS)/, $(SRC_BONUS))
OBJS_BONUS = $(addprefix $(OBJDIR_BONUS)/, $(SRC_BONUS:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INC) $(LIBFT) $(MLXFLAGS) -o $(NAME) $^

bonus: $(OBJS_BONUS)
	@$(CC) $(CFLAGS) $(INC) $(LIBFT) $(MLXFLAGS) -o $(NAME) $^

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	mkdir $(OBJDIR) 2> /dev/null || true
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

$(OBJDIR_BONUS)/%.o: $(SRCDIR_BONUS)/%.c
	@mkdir $(OBJDIR_BONUS) 2> /dev/null || true
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $<

clean:
	rm -rf $(OBJDIR_BONUS)
	rm -rf $(OBJDIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
