CC =  gcc
CFLAGS = -Wall -Wextra -Werror

# your code
INCL = your_code/get_next_line.h
SRCS = your_code/get_next_line.c

# tester
TEST_INCL = answer/get_next_line.h
TEST_SRCS = answer/get_next_line.c
MAIN = test/main.c

all :
	$(CC) $(CFLAGS) $(MAIN) $(SRCS) -include $(INCL)
	./a.out > your_ret
	$(CC) $(CFLAGS) $(MAIN) $(TEST_SRCS) -include $(TEST_INCL)
	./a.out > ans_ret
	diff your_ret ans_ret

clean :
	rm -f $(NAME) $(TEST_NAME) a.out your_ret ans_ret

re : clean all
