CC='gcc'
CFLAGS='-Werror -Wall -Wextra'
RED='\033[0;32m'
PRINTFA='libftprintf.a'
NC='\033[0m' # No Color
PT_TEST='printf_percent.c'
FPT_TEST='ftprintf_percent.c'
echo 'Please enter a path for libftprintf.a'
	rm -f test.c
	cp ${PT_TEST} ft.c
	sed -e '15,$ s/printf/ft_printf/g' ft.c > ${FPT_TEST}
	rm ft.c
	printf "${RED}Compiling printf main...${NC}\n"
	${CC} ${CFLAGS} -o a.out ${PT_TEST} -L../../ -lftprintf 2> /dev/null
	./a.out > printf.txt
	echo "${RED}Compiling ft_printf main...${NC}\n"
	${CC} ${CFLAGS} -o a.out ${FPT_TEST} -L../../ -lftprintf 2> /dev/null
	./a.out > ft_printf.txt
	rm a.out
	diff printf.txt ft_printf.txt > printf.diff
	cat -e printf.diff
	printf "${RED}You have "
	cat -e printf.diff | grep "<" | wc -l | tr -d " " | tr -d "\n"
	printf " errors \n"
