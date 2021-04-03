CHECKER = checker
PUSH_SWAP = push_swap
NAME = libpushswap.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = rc
RM = rm -rf

FUNC = ft_swap_one \
	ft_swap_both \
	ft_push_one \
	ft_push_both \
	ft_push_all \
	ft_rotate_one \
	ft_rotate_both \
	ft_rrotate_one \
	ft_rrotate_both \
	is_more_than_one_elem \
	ft_checker \
	is_sorted_stack \
	gen_init_nbr_list \
	gen_inst_list \
	gen_stack \
	print_list \
	print_inst_list \
	print_stack \
	get_next_line \
	free_stack_both \
	ft_push_swap \
	get_int_data \
	get_median_pivot \
	get_tri_division_pivot \
	set_min_max_val \
	calc_util \
	set_init_arr \
	quick_sort \
	solve_select_sort \
	solve_nlog2n \
	solve_nlog3n \
	
SRCDIR = ./srcs
INCDIR = ./incs
OBJDIR = ./objs
LIBDIR = ./libft
LIBFT  = ./libft/libft.a
MAINDIR = ./main

SRC  = $(addsuffix .c, $(FUNC))
SRCS = $(addprefix $(SRCDIR)/, $(SRC))
OBJS = $(addprefix $(OBJDIR)/, $(SRC:.c=.o))

test: re
	@$(CC) $(CFLAGS) -o $(CHECKER) $(MAINDIR)/checker.c -L./ -lpushswap
	@$(CC) $(CFLAGS) -o $(PUSH_SWAP) $(MAINDIR)/push_swap.c -L./ -lpushswap
	@echo "TYPE INSTRUCTION=============================="

all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) -C $(LIBDIR) all
	@cp $(LIBFT) $(NAME)
	@$(AR) $(ARFLAGS) $(NAME) $^
	@ranlib $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir $(OBJDIR) 2> /dev/null || true
	@$(CC) $(CFLAGS) -I$(INCDIR) -o $@ -c $<

clean:
	@$(RM) $(OBJDIR)
	@$(MAKE) -C $(LIBDIR) clean

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(CHECKER) $(PUSH_SWAP)
	@$(MAKE) -C $(LIBDIR) fclean

re: fclean all

.PHONY: all clean fclean re test
