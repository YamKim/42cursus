NAME = program.out
CC = gcc

SRC = main.c \
	vector_calc.c \
	player_motion.c


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
