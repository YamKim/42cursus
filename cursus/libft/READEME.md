# Libft
Libft는 크게, string.h, stdlib.h, ctype.h, stdio.h, linked-list 관련 함수로 구성되어 있습니다.  
각 함수의 역할과 구현 방식을 간단하게나마 서술하기 위해 글을 올립니다.  
(아래 순서는 범주화 우선으로, 실제 과제 구현 순서와 별개입니다.)  
(그리고, 여기서 만큼은 norminette에 묶이지 않고 싶습니다.ㅠㅠ return (0)도 안할거에요!)  

## string.h
### memory 관리
-   ft_memset (fill memory with a constant byte)
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
        printf("size: %d, s_init: %s\n", (int)strlen(s), (char *)s_init);
    }
    // 출력결과:
    // size: 14, s_init: 11111111111111
```
-   ft_bzero (zero a byte string)
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
        printf("size: %d, s_init: %s\n", (int)strlen(s), s);
    }
    // 출력결과:
    // size: 0, s:
```
-   ft_memcpy (copy memory area)
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
-   ft_memccpy (copy memory area)
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
-   ft_memmove (copy memory area)
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
-   ft_memchr (scan memory for a character)
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
-   ft_memcmp (compare memory areas)
    + 목적: 두 pointer n개의 요소 값을 비교하여, 같으면 0, s1이 크면 양수, 작으면 음수 반환.   
    + 구현:  
    1. 두 pointer 모두 (unsigned char *)로 형변환합니다.
    2. 각각의 인덱스를 서로 비교하다 같지 않은 경우, 두 값(char 값)의 차이를 반환합니다.
```cpp
    // 형태
    int ft_memcmp(const void *s1, const void *s2, size_t n)
    // 사용 예시
    #if 1 // memcmp
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

### String basic
- ft_strlen
- ft_strlcpy  
- ft_strlcat  
- ft_strchr  
- ft_strrchr
- ft_strnstr
- ft_strncmp


## stdlib.h
- ft_atoi

### string 테크닉

- ft_calloc
- ft_strdup
- ft_substr
- ft_strjoin
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

### 파일관련
- ft_putchar_fd
- ft_putstr_fd
- ft_putendl_fd
- ft_putnbr_fd

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
