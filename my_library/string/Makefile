CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f

TARGET = test.out

LIBS_PATH	= ../libs
LIBS_FILE   = libstring.a

SRCS		= main.c 
OBJS		= $(SRCS:.c=.o)
LIBS		= $(addprefix $(LIBS_PATH)/, $(LIBS_FILE))
LIB_DIRS	= -L$(LIBS_PATH)

.c.o :
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(TARGET) : $(OBJS)
		$(CC) $(FLAGS) -o $@ $^ $(LIB_DIRS) $(LIBS)

all : $(TARGET)

clean :
	$(RM) $(OBJS)

fclean :
	$(RM) $(TARGET)

re : fclean all

.PHONY: all clean fclean re
