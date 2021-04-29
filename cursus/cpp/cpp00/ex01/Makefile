NAME = PhoneBook

CC = clang++
CFLAGS = -Wall -Wextra -Werror

FUNC = \
	main \
	Contact \
	PhoneBook

OBJDIR = ./objs
INCDIR = ./
SRCDIR = ./

SRC  = $(addsuffix .cpp, $(FUNC))
SRCS = $(addprefix $(SRCDIR)/, $(SRC))
OBJS = $(addprefix $(OBJDIR)/, $(SRC:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJS)
	@echo "Start Program"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) #2> /dev/null || true
	
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@printf "Generating objs... %-33.33s\r" $@
	@mkdir $(OBJDIR) 2> /dev/null || true
	@$(CC) $(CFLAGS) -I$(INCDIR) -o $@ -c $< #2> /dev/null || true

clean:
	@rm -rf $(OBJDIR)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
