CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f

LIBS		= libfileio.a libstring.a
LIB_DIRS	= -L.

TARGET = ft_cat

INCS = ft_cat.h

SRCS = main.c \
		ft_cat.c

OBJS = $(SRCS:.c=.o)

.c.o :
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(TARGET) : $(OBJS)
	$(CC) $(FLAGS) -I$(INCS) -o $@ $^ $(LIB_DIRS) $(LIBS)

all : $(TARGET)

clean :
	$(RM) $(OBJS)

fclean :
	$(RM) $(TARGET)

re : fclean all

.PHONY: all clean fclean re
