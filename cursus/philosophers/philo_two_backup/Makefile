NAME = philo_two
CC = arch -x86_64 gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

FUNC = \
	main \
	init_info \
	run_routine \
	do_fork \
	do_eat \
	do_sleep \
	do_die \
	ft_utils \
	show_message \
	get_cur_time \
	free_memory \
	exit_threads \
	ft_sem_open

SRCDIR = ./srcs
INCDIR = ./incs
OBJDIR = ./objs

TMPSRCS = $(addsuffix .c, $(FUNC))
SRCS = $(addprefix $(SRCDIR)/, $(TMPSRCS))
OBJS = $(addprefix $(OBJDIR)/, $(TMPSRCS:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	mkdir $(OBJDIR) 2> /dev/null || true
	$(CC) $(CFLAGS) -I$(INCDIR) -Ipthread -o $@ -c $<

clean:
	$(RM) $(OBJDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
