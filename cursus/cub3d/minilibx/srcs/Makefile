NAME = program.out
CC = gcc

SRC = main.c \
	parse_configuration.c \
	player_motion.c \
	calc_vector.c \
	calc_dda.c \
	disp_untextured_wall.c \
	disp_textured_wall.c \
	disp_sprite.c \
	ft_split.c \
	ft_atoi.c \
	string_utils.c \
	string_utils2.c \
	input_hook.c \
	load_image.c

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
