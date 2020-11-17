NAME = program.out
CC = gcc

SRC = main.c \
	vector_calc.c \
	player_motion.c

all: $(NAME)

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	$(CC) -L../ -lmlx -framework OpenGL -framework Appkit $(NAME) $^

$(OBJ): $(SRC)
	$(CC)  -I. -o $@ -c $<
	

clean:
	rm -rf $(OBJ)

fclean:

re: fclean all

.PHONY: all clean fclean re
