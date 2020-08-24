# FT String Header
[upper directory](..)

## FT String Functions
### basic
---
- ft_putchar
    ```c
    void	ft_putchar(char c)
    {
    	write(1, &c, 1);
    }
    ```
    목적: char 자료형의 데이터를 편리하게 출력하기 위함.  
    반환: (void) 표준출력에 c 출력.  
    예시: ft_putchar('a');

- ft_putstr
    ```c
    void    ft_putstr(char *str)
    {
        while (*str)
            ft_putchar(*(str++));
    }
    ```
    목적: char *자료형(str)의 데이터를 편리하게 출력하기 위함.  
    반환: (void) 표준출력에 str 출력.  
    예시: ft_putstr("Hello World!\n");  
    > char *str1 = "Hello world!\n";  
    > char str1[] = "Hello world!\n";  
    >
    > 차이점: 배열로 초기화 하는 경우 특정 인덱스 값 수정 가능.  
    포인터 초기화의 경우 임시적으로 공간이 할당되어 참조만 가능. 수정불가. 

- ft_strlen
    ```c
    int     ft_strlen(char *str)
    {
        int ret;
    
        ret = 0;
        while (*(str++))
            ++ret;
        return (ret);
    }
    ```
    목적: str의 길이를 구하기 위함.  
    반환: (int) str의 길이.   
    예시: printf("len: %d\n", ft_strlen("Hello World!\n"));

### copy
---
- ft_strcpy
    ```c
    char    *ft_strcpy(char *dst, char *src)
    {
       char    *ret;

       ret = dst;
       while (*src)
           *(dst++) = *(src++);
       *dst = *src;
       return (ret);
    }
    ```
    목적: src의 str 데이터를 dst에 복사.  
    반환: (char *) src의 데이터가 복사된 값.   
    예시: printf("res: %s\n", ft_strcpy(str1, str2));
    > char *str1;  (X)  
    > char str1[]; (O)  
    >
    > ft_putstr에서 언급한 바와 같이, 값이 복사될 변수를 포인터로 초기화하는 경우 수정이 불가능하므로 배열로 초기화해야함. 

- ft_strncpy
    ```c
    char	*ft_strncpy(char *dst, char *src, unsigned int n)
    {
    	char	*ret;
    
    	ret = dst;
    	n = n + 1;
    	while (*src && --n)
    		*(dst++) = *(src++);
    	while (n && --n)
    		*(dst++) = '\0';
    	return (ret);
    }
    ```
    목적: src의 데이터 n개만큼 dst에 복사.  
    반환: (char *) src의 데이터가 복사된 값.  
    예시: printf("res: %s\n", ft_strncpy(str1, str2,4));  
    단점: 만약, str1의 버퍼 크기가 n보다 작다면, '\0'값을 삽입할 수 없음. 
    > 참고: ft_putstr, ft_strcpy

- ft_strlcpy
    ```c
    unsigned int	ft_strlcpy(char *dst, char *src, unsigned int size)
    {
    	unsigned int	ret;

    	ret = 0;
    	while (*src && --size)
    	{
    		*(dst++) = *(src++);
    		++ret;
    	}
    	*dst = '\0';
    	while (*(src++))
    		++ret;
    	return (ret);
    }
    ```
    목적: 
    1. size만큼의 크기를 갖는 dst(str 데이터)를 만들기 위함.  
    2. 복사될 수 있는 src의 길이를 반환하여 전체 값을 복사하기 위한 버퍼 크기 가늠.   
    반환: (int) 복사하고자 했던 src의 길이  
    예시: printf("res: %d, dst:%s\n", ft_strlcpy(str1, "Hello", 3), str1);  
    주의: str1 배열로 초기화하기(참고: ft_putstr)  
    장점: strncpy 보완. size - 1 까지의 값만 복사하기 때문에 항상 '\0'값이 들어갈 공간 확보.  

### compare
---
- ft_strcmp
    ```c
    int	ft_strcmp(char *s1, char *s2)
    {
    	while (*s1 || *s2)
    	{
    		if (*s1 != *s2)
    			break ;
    		++s1;
    		++s2;
    	}
    	return ((int)(*s1 - *s2));
    }
    ```
    목적: 두 str의 데이터를 비교하고 다른 값이 나오는 시점의 값 차이를 구함.  
    반환: (int) s1과 s2가 달라지는 시점의 ASCII값 차이. (같으면 0)  
    예시: printf("res: %d\n", ft_strncmp("Abc", "ABc"));  
    주의: 'while (*(s1++) 1= *(s2++))'로 쓰는 경우, 비교 후, return 시 다음 값에 대한 연산을 수행.

- ft_strncmp
    ```c
    int	ft_strncmp(char *s1, char *s2, unsigned int n)
    {
    	n += 1;
    	while ((*s1 || *s2) && --n)
    	{
    		if (*s1 != *s2)
    			break ;
    		++s1;
    		++s2;
    	}
    	if (!n)
    		return (0);
    	return ((int)(*s1 - *s2));
    }
    ```
    목적: 두 str의 데이터 중 n개의 데이터를 비교하고 다른 값이 나오는 시점의 값 차이를 구함.  
    반환: (int) s1과 s2가 달라지는 시점의 ASCII값 차이. (같으면 0)  
    예시: printf("res: %d\n", ft_strncmp("Abcd", "ABcD", 3));

### concat
---
- ft_strcat
    ```c
    char	*ft_strcat(char *dst, char *src)
    {
    	char	*ret;

    	ret = dst;
    	while (*dst)
    		++dst;
    	while (*src)
    		*(dst++) = *(src++);
    	*dst = '\0';
    	return (ret);
    }
    ```
    목적: dst 데이터(str) 뒤에 src 데이터를 이어붙임.  
    반환: (char *) dst 데이터 뒤에 src 데이터가 덧붙여진 값.  
    단점: dst 데이터가 어느정도의 데이터까지 더 덧붙일 수 있는지 판단불가.  
    예시: printf("res: %s\n", ft_strcat(dest, "ABC"));  
    > 주의: dest는 포인터가 아닌 배열로 초기화 해야함  
    > 참고: ft_putstr  

- ft_strncat
    ```c
    char	*ft_strncat(char *dst, char *src, unsigned int nb)
    {
    	char	*ret;

    	ret = dst;
    	while (*dst)
    		++dst;
    	nb += 1;
    	while (*src && --nb > 0)
    		*(dst++) = *(src++);
    	*dst = '\0';
    	return (ret);
    }
    ```
    목적: dst 데이터(str) 뒤에 src 데이터 n개를 이어붙임.  
    반환: (char *) dst에 src를 덧붙인 str 데이터  
    단점: ft_strcat 참고  
    예시: printf("res: %s\n", ft_strncat(dest, "ABC", 2));  
    주의: ft_strcat 참고  

- ft_strlcat
    ```c
    unsigned int	ft_strlcat(char *dst, char *src, unsigned int size)
    {
	    unsigned int	len;
	    unsigned int	src_len;
	    unsigned int	itr;

	    len = 0;
	    src_len = ft_strlen(src);
	    while (*dst)
	    {
		    ++dst;
		    ++len;
	    }
	    if (size <= len)
		    return (src_len + size);
	    itr = size - len + 1;
	    while (*src && --itr)
		    *(dst++) = *(src++);
	    *dst = '\0';
	    return (src_len + len);
    }
    ```
    목적: dst 데이터(str) 뒤에 src 데이터를 최종 버퍼 크기가 size가 되도록 이어 붙임.  
    반환: 
    1. (int) dst 길이가 size보다 작으면 (src의 길이 + size) 값. 이는, dst가 src를 이어 붙이기 위한 최소 버퍼 크기를 의미. 
    2. (int) dst 길이가 size보다 크면 dst에 src를 이어붙인 길이. 이는 버퍼 크기 

    참고: 버퍼 크기는 배열의 총 크기이며, 길이는 '\0'값을 제외한 그 앞까지의 크기를 말함.  
    예시: printf("res: %d, dest: %s\n", ft_strlcat(dest, "abc", 8), dest); 