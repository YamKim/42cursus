표준출력 및 파일 출력을 다루는 stdio의 함수를 구현하는 부분입니다.

# stdio.h
## file 관련
### ft_putchar_fd
: fputc - output of characters
+ 목적: 표준출력이 아닌, 파일에 char를 출력하기 위함.
+ 구현:  
	1. write 함수를 사용하여 입력받은 file descriptor에 char 출력합니다.
+ 참고: 지면을 아끼기 위해, 파일 open시 오류처리는 따로 하지 않겠습니다.
```cpp
// 형태
void ft_putchar_fd(char c, int fd)
// 사용 예시
int main(void) {
	int fd = open("test.txt", O_CREAT | O_TRUNC | O_WRONLY);
	ft_putchar_fd('h', fd);
	ft_putchar_fd('i', fd);
}
// sudo cat -e test.txt: 
// hi%
```

### ft_putstr_fd
: fputs - output of characters
+ 목적: 표준출력이 아닌, 파일에 문자열을 출력하기 위함.
+ 구현:  
	1. ft_putchar_fd와 같이 write함수를 사용합니다.
	2. 문자열의 길이를 구하여 버퍼를 통째로 출려합니다.
```cpp
// 형태
void ft_putstr_fd(char *s, int fd)
// 사용 예시
int main(void) {
	int fd = open("test.txt", O_CREAT | O_TRUNC | O_WRONLY);
	ft_putstr_fd("Hello 42 World", fd);
} 
// sudo cat -e test.txt: 
// Hello 42 World%
```

### ft_putendl_fd
: fputs - output of characters
+ 목적: 표준출력이 아닌, 파일에 문자열 출력 후 줄바꿈을 추가하는 것.
+ 구현:  
	1. ft_putstr_fd로 문자열을 출력 후, ft_putchar_fd로 줄바꿈을 추가합니다.
```cpp
// 형태
void ft_putendl_fd(char *s, int fd)
// 사용 예시
int main(void) {
	int fd = open("test.txt", O_CREAT | O_TRUNC | O_WRONLY);
	ft_putendl_fd("Hello 42 World", fd);
} 
// sudo cat -e test.txt: 
// Hello 42 World$
```

### ft_putnbr_fd
: fputs - output of characters
+ 목적: int형 숫자를 파일에 출력하는 것.
+ 구현:  
	1. (n / 10)과 (n % 10)을 적절히 사용하여 각자리의 숫자를 뽑아냅니다.
	2. ft_putchar_fd를 이용하여 각자리의 숫자를 출력합니다.  
```cpp
// 형태
void ft_putnbr_fd(int n, int fd)
// 사용 예시
int main(void) {
	int fd = open("test.txt", O_CREAT | O_TRUNC | O_WRONLY);
	ft_putnbr_fd(424242, fd);
} 
// sudo cat -e test.txt: 
// 424242%
```