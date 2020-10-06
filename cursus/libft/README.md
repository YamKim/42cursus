Libft는 크게, string.h, stdlib.h, ctype.h, stdio.h, linked-list 관련 함수로 구성되어 있습니다.  
각 함수의 역할과 구현 방식을 간단하게나마 서술하기 위해 글을 올립니다.  
(아래 순서는 범주화 우선으로, 실제 과제 구현 순서와 별개입니다.)  
(그리고, 여기서 만큼은 norminette에 묶이지 않고 싶습니다.ㅠㅠ return (0)도 안할거에요!)  

# string.h
## memory 관련
#### ft_memset 
: fill memory with a constant byte  
+ 목적: s가 가리키는 버퍼의 n개 element를 c 번째 ASCII 문자로 채우는 것.  
+ 구현:
	1. c 번째 ASCII로 채워야 하므로, c를 unsigned char로 typecasting.
	2. s가 void pointer이기 때문에 unsigned char를 담을 수 있도록 typecasting.
	3. s의 n-1번째 인덱스(n개)까지 각 인덱스에 c를 할당합니다.  
```cpp
// 형태
void *ft_memset(void *s, int c, size_t n)  
// 사용 예시
int main(void) {
    char *s = strdup("Hello 42 Wolrd"); // 모두가 아는 그 인사..
    void *s_init = ft_memset((void *)s, '1', strlen(s));
    printf("size: %ld, s_init: %s\n", strlen(s), (char *)s_init);
}
// 출력결과:
// size: 14, s_init: 11111111111111
```

### ft_bzero 
: zero a byte string  
+ 목적: s가 가리키는 버퍼의 n개 element를 NUL (ASCII 0번째)로 채우는 것.  
+ 구현:
	1. ft_memset과 같은 방식으로 하되, c부분을 0('\0')으로 주면 됩니다.  
```cpp
// 형태
void ft_bzero(void *s, size_t n)
// 사용 예시
int main(void) {
    char *s = strdup("Hello 42 World");
    bzero((void *)s, strlen(s));
    printf("size: %ld, s_init: %s\n", strlen(s), s);
}
// 출력결과:
// size: 0, s:
```

###   ft_memcpy
: copy memory area  
+ 목적: src의 메모리 값 n개를 dest에 할당 하는 것. 
+ 구현:
	1. 0번째 index부터 src에 접근하여 그 값을 dest로 할당합니다.  
```cpp
// 형태
void *ft_memcpy(void *dest, void *src, size_t n)
// 사용 예시
int main(void) {
    char *src = strdup("Hello 42 World");
    char dest[0xF0];
    ft_memcpy((void *)dest, src, strlen(src));
    printf("dest: %s\n", dest);
}
// 출력결과:
// dest: Hello 42 World
```
### ft_memccpy
: copy memory area  
+ 목적: src에 특정 문자(c)가 dest에 들어있는 경우, 그 앞까지만 값을 복사.
+ 구현:
	1. ft_memcpy를 수행하는 도중, 'c'를 발견하면 탈출시킵니다.  
```cpp
// 형태
void *ft_memccpy(void *dest, const void *src, int c, size_t n)
// 사용 예시
int main(void) {
    char *src = strdup("Hello 42 World");
    char dest[0xF0];
    ft_memccpy((void *)dest, src, (int)'W', strlen(src));
    printf("dest: %s\n", dest);
}
// 출력결과:
// dest: Hello 42 W
```

### ft_memmove
: copy memory area  
+ 목적: memcpy와 유사하지만, dest가 src 주변을 가리킬 경우 생기는 오류를 극복하기 위함.  
+ 구현:
	1. 만약 dest가 src의 다음다음 위치를 가리키고 있다면,  
	   src의 값을 dest에 복사했을 때, 결국 src + 2 위치에 src의 값이 들어가게 됩니다.  
	2. 이를 막기 위해서, dest에 복사하려는 src의 요수 개수(n)를 기준으로 방식을 나눕니다.
	3. dest가 src보다 뒤를 가리키면, src[n-1-idx]부터 dest[n-1-idx]에 복사합니다.  
	   (dest의 앞을 채우는 동안 src의 뒤가 바뀌는 것을 방지)
	4. dest가 src보다 앞을 가리키면, src[idx]부터 dest[idx]에 복사합니다.  
       (dest의 뒤를 채우는 동안 src의 앞이 바뀌는 것을 방지)
```cpp
// 형태
void *ft_memmove(void *dest, const void *src, size_t n)
// ft_memcpy를 사용시 발생하는 오류 예시
int main(void) {
    char *src = strdup("Hello 42 World");
    char *dest = src + 2;
    ft_memcpy((void *)dest, src, strlen(src));
    printf("dest: %s\n", dest);
}
// 출력 결과: 
// dest: HeHeHeHeHeHeHe
// ft_memmove 사용 예시
int main(void) {
    char *src = strdup("Hello 42 World");
    char *dest = src + 2;
    ft_memmove((void *)dest, src, strlen(src));
    printf("dest: %s\n", dest);
    return (0);
}
// 출력결과:
// dest: Hello 42 World
```

### ft_memchr
: scan memory for a character  
+ 목적: s의 요소 n개 중에 c번째 ASCII 값이 발견될 경우, 그 이후 값을 가리키는 포인터를 반환.
+ 구현:
	1. ft_memset에서와 같이, s와 int 모두 usngined char로 typecasting 하여 비교합니다.  
	    (s의 경우는 unsinged char *)
	2. 일치하면, 다음 값을 가리키는 포인터를 반환합니다.  
```cpp
// 형태
void *ft_memchr(const void *s, int c, size_t n)
// 사용 예시
int main(void) {
    char *src = strdup("Hello 42 World");
    void *dest;
    dest = ft_memchr(src, (int)'4', strlen(src));
    printf("dest: %s\n", (char *)dest);
    return (0);
}
// 출력 결과: 
// dest: 42 World
```

### ft_memcmp
: compare memory areas  
+ 목적: 두 pointer n개의 요소 값을 비교하여, 같으면 0, s1이 크면 양수, 작으면 음수 반환.   
+ 구현:  
	1. 두 pointer 모두 (unsigned char *)로 형변환합니다.
	2. 각각의 인덱스를 서로 비교하다 같지 않은 경우, 두 값(char 값)의 차이를 반환합니다.
```cpp
// 형태
int ft_memcmp(const void *s1, const void *s2, size_t n)
// 사용 예시
int main(void) {
    char *src = strdup("Hello 42 World");
    void *dest = strdup("Hello 32 World");
    int n = ft_memcmp(src, dest, strlen(src));
    if (n > 0)			printf("result: src > dest\n");
    else if (n == 0)	printf("result: src = dest\n");
    else				printf("result: src < dest\n");
    return (0);
}
// 출력 결과: 
// result: src > dest
```

## string 관련
### ft_strlen  
: calculate the length of a string    
+ 목적: string의 길이를 반환   
+ 구현:  
	1. str의 요소가 NUL(문자열의 마지막)이 될 때까지 증가 시키며 요소의 수를 셉니다.
```cpp
// 형태
size_t ft_strlen(char *str)
// 사용 예시
int main(void) {
	char *src = strdup("Hello 42 World");
	printf("len: %ld\n", ft_strlen(src));
}
// 출력 결과: 
// len: 14
```

### ft_strdup
: duplicate a string  
+ 목적: 입력받은 문자열을 요소로 갖는 char *를 만드는 것.
+ 구현:  
	1. 입력받은 string(s)의 길이를 구하고, 길이 + 1의 크기를 갖는 메모리를 할당합니다.
	2. string의 각 요소 값을 새로 할당한 포인터에 복사합니다. 마지막 요소는 (NUL)로 채우기.
```cpp
// 형태
char *ft_strdup(const char *s)
// 사용 예시
int main(void) {
	char *src = ft_strdup("Hello 42 World");
	printf("result: %s\n", src);
}
// 출력 결과: 
// result: Hello 42 World
```

### ft_strlcpy  
: size-bounded string copying  
+ 목적: dest의 버퍼 크기가 size가 되도록 src의 값을 ***안전히(마지막 요소는 NUL로)*** dest에 복사.    
+ 구현:  
	1. size가 src 길이+1(NUL이 들어갈 공간) 이상이면, src 길이만큼 복사하고 마지막 요소는 NUL로 채웁니다.
	2. 그 외 경우라면, size-1개의 문자를 복사하고 마지막 요소는 NUL로 채웁니다.  
	3. 복사 후, src의 길이를 반환하여 최대 복사할 수 있는 길이(버퍼 크기가 아닌)를 가르쳐줍니다.  
	   (마지막은 NULL이 되어야 하기 때문에, 전체를 복사하려면 예제에서는 size에 15이상 대입해야합니다.)  
```cpp
// 형태
size_t ft_strlcpy(char *dest, const char *src, size_t size)
// 사용 예시
int main(void) {
	char *src = ft_strdup("Hello 42 World");
	char dest[0xF0];
	dest[0] = '4';
	dest[5] = '2';
	size_t len = ft_strlcpy(dest, src, (size_t)20);
	printf("len: %d, dest: %s\n", (int)len, dest);
}
// 출력 결과: 
// len: 14, dest: Hello 42 World
```

### ft_strlcat
: size-bounded string concatenation
+ 목적: dest의 버퍼 크기가 size가 되도록 src의 값을 ***안전히(마지막 요소는 NUL로)*** dest에 덧붙임.
+ 구현:  
	1. 만약, dest의 길이가 size보다 크거나 같다면 덧붙일 수 없기 때문에, 의도했던 크기(NUL 포함)를 반환합니다.  
	   (src의 길이 + size)
	2. dest의 길이가 size보다 작다면, dest 뒤로 size - len_dest 크기를 복사할 수 있습니다.
	3. src를 모두 붙일 수 있었다면, src 길이 + dest 길이를 반환합니다.
```cpp
// 형태
size_t ft_strlcat(char *dest, const char *src, size_t size)
// 사용 예시
int main(void) {
	char *src = ft_strdup("Hello 42 World");
	char *dest = ft_strdup("yekim, ");
	size_t len = ft_strlcat(dest, src, (size_t)16);
	printf("len: %d, dest: %s\n", (int)len, dest);
}
// 출력 결과: 
// len: 21, dest: yekim, Hello 42
```

### ft_strchr
: locate character in string  
+ 목적: string s에서 c번째 ASCII 값을 발견하면 c를 포함한 이 후의 주소를 반환. (앞에서부터)
+ 구현:  
	1. c를 char로 typecasting하여 s의 각 요소와 비교하고, 발견했을 때 해당 주소 반환합니다. (앞에서부터)
	2. [0, strlen(s)-1]까지 비교합니다.
	3. 마지막 요소까지 비교해도 발견하지 못한 경우 NULL을 반환합니다.
+ 주의: 
```cpp
// 형태
char *ft_strchr(const char *s, int c)
// 사용 예시
int main(void) {
	char *src = ft_strdup("Hello 42 World");
	char *res = ft_strchr(src, (int)'o');
	printf("dest: %s\n", res);
}
// 출력 결과: 
// dest: o 42 World
```

### ft_strrchr
: locate character in string  
+ 목적: string s에서 c번째 ASCII 값을 발견하면 c를 포함한 이 후의 주소를 반환. (뒤에서부터)
+ 구현:  
	1. c를 char로 typecasting하여 s의 각 요소와 비교하고, 발견했을 때 해당 주소 반환합니다. (뒤에서부터)
	2. [strlen(s)-1, 0]까지 비교합니다.
	3. 발견하지 못한 경우 NULL을 반환합니다.
```cpp
// 형태
char *ft_strrchr(const char *s, int c)
// 사용 예시
int main(void) {
	char *src = ft_strdup("Hello 42 World");
	char *res = ft_strrchr(src, (int)'o');
	printf("dest: %s\n", res);
}
// 출력 결과: 
// dest: orld
```
### ft_strncmp
: compare two strings  
+ 목적: n개의 요소에 대해 str1이 str2보다 큰지 같은지 작은지 비교하기 위함.
+ 구현:  
	1. 각 요소에 접근하여 한 문자열이라도 문자열의 끝이 되도록 값을 비교합니다.
	2. 동시에 n도 함께 줄여주며 n개의 요소를 비교합니다.
```cpp
// 형태
int ft_strncmp(const char *s1, const char *s2, size_t n)
// 사용 예시
int main(void) {
	char *src1 = ft_strdup("Hello 32 World");
	char *src2 = ft_strdup("Hello 42 World");
	int n = ft_strncmp(src1, src2, ft_strlen(src1));
	if (n > 0)			printf("result: src1 > src2\n");
	else if (n == 0)	printf("result: src1 = src2\n");
	else				printf("result: src1 < src2\n");
}
// 출력 결과: 
// result: src1 < src2
```

### ft_strnstr
: locate a substring
+ 목적: needle이 haystack에 포함되는 문자열인지 찾는 것.
+ 구현:  
	1. haystack을 가리키는 포인터를 이동시키며 needle과 일치하는지 여부를 판단합니다.
	2. (haystack의 길이 - needle의 길이 + 1)번째까지 비교해보고 없으면 루프를 종료합니다.
	3. (haystack의 길이 - needle의 길이)가 0보다 작아도 루프를 돌지 않습니다.
```cpp
// 형태
char *ft_strnstr(const char *haystack, const char *needle)
// 사용 예시
int main(void) {
	char *haystack = ft_strdup("Hello 42 World");
	char *needle = ft_strdup("42");
	char *res = ft_strnstr(haystack, needle);
	printf("result: %s\n", res);
}
// 출력 결과: 
// result: 42 World
```

# stdlib.h
## memory/number allocation
### ft_calloc
: allocate dynamic memory
+ 목적: nmemb x size 만큼의 공간을 만들고, 요소를 NUL로 채우는 것.
+ 구현:  
	1. 최종으로 반환할 크기(nmemb x size)만큼 버퍼를 만들기.
	2. 각 버퍼에 접근하여 NUL로 채우기.
```cpp
// 형태
void *ft_calloc(size_t nmemb, size_t size)
// 사용 예시
int main(void) {
	char *hi = ft_calloc(4, sizeof(char));
	hi[0] = 'H';
	hi[1] = 'i';
	hi[2] = '!';
	printf("result: %s\n", hi);
	return (0);
}
// 출력 결과: 
// result: Hi!
```

### ft_atoi
: convert a string to an integer
+ 목적: string으로 숫자를 받을 때, 이를 int형 숫자로 변환(user로부터 input 받을 때 사용).
+ 구현:  
	1. string nptr의 각 요소에 접근하여 white space인 경우 건너뜁니다.
	2. 부호('-', '+')가 연이어 나올 경우, 0을 반환합니다. ('-'가 나온다면, 기억해두기)
	3. 부호 다음 공백이나 숫자가 아닌 수가 나오면 0을 반환합니다.
	4. 부호 다음 숫자가 나온 경우, 루프 안에서 자릿수에 맞는 값을 누적시킵니다.  
	   참고: ret = ret * 10 + (int)(*(nptr++) - '0');
	5. 반환 직전에 '-' 존재여부를 기준으로 음수라면 '-'를 붙여 반환합니다.
+ 주의: -(int의 최솟값)은 int 자료형이 담지 못하기 때문에, 이를 담기위해 unsigned int 이용하기.  
```cpp
// 형태
int ft_atoi(const char *nptr)
// 사용 예시
int main(void) {
	int nbrEx1 = ft_atoi(" - 4242  ");
	int nbrEx2 = ft_atoi(" --+-4242");
	printf("nbr1: %d, nbr2: %d\n", nbrEx1, nbrEx2);
}
// 출력 결과: 
// nbr1: 0, nbr2: 0
```

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
+ 목적: 표준출력이 아닌, 파일에 string을 출력하기 위함.
+ 구현:  
	1. ft_putchar_fd와 같이 write함수를 사용합니다.
	2. string의 길이를 구하여 버퍼를 통째로 출려합니다.
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
+ 목적: 표준출력이 아닌, 파일에 string 출력 후 줄바꿈을 추가하는 것.
+ 구현:  
	1. ft_putstr_fd로 string을 출력 후, ft_putchar_fd로 줄바꿈을 추가합니다.
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

# libc 외
## string technic
### ft_substr
+ 목적: string s의 부분 string을 사용하기 위함.
+ 구현:  
	1. s의 길이를 구하고, start가 길이 이상인 경우, NUL을 가지는 버퍼를 반환합니다.
	2. start가 s의 길이보다 작으면 그 부분부터 len개의 char가 s에 존재하는지 조사합니다.
	3. 가능하다면, len개의 char 모두 복사하고, 그렇지 않다면 s의 끝까지 복사합니다.
```cpp
// 형태
char *ft_substr(char const *s, unsigned int start, size_t len)
// 사용 예시
int main(void) {
	char *src = "Hello 42 World";
	char *res = ft_substr(src, 6, (size_t)2);
	printf("result: %s\n", res);
}
// 출력 결과: 
// result: 42
```

## string technic
### ft_strjoin
+ 목적: string s의 부분 string을 사용하기 위함.
+ 구현:  
	1. s의 길이를 구하고, start가 길이 이상인 경우, NUL을 가지는 버퍼를 반환합니다.
	2. start가 s의 길이보다 작으면 그 부분부터 len개의 char가 s에 존재하는지 조사합니다.
	3. 가능하다면, len개의 char 모두 복사하고, 그렇지 않다면 s의 끝까지 복사합니다.
```cpp
// 형태
char *ft_substr(char const *s, unsigned int start, size_t len)
// 사용 예시
int main(void) {
	char *src = "Hello 42 World";
	char *res = ft_substr(src, 6, (size_t)2);
	printf("result: %s\n", res);
}
// 출력 결과: 
// result: 42
```

- ft_strtrim
- ft_split
- ft_itoa
- ft_strmapi

### condition check
- ft_isalpha
- ft_isdigit
- ft_isalnum
- ft_isascii
- ft_isprint
- ft_toupper
- ft_tolower



### list 관련
- ft_lstnew
- ft_lstadd_front
- ft_lstsize
- ft_lstlast
- ft_lstadd_back
- ft_lstdelone
- ft_lstclear
- ft_lstiter
- ft_lstmap
