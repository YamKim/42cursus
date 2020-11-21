NAME = program.out
CC = gcc

SRC = main.c \
	player_motion.c \
	calc_basic.c \
	calc_vector.c \
	calc_dda.c \
	disp_draw.c \
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
