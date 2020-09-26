# Contents

[upper directory](https://github.com/YamKim/ft_lib)

**Basic Functions** 

[basic](#basic)
- my_fgetc
- my_fgets
- my_puterr
- my_input

**Advanced FUNCTIONS**
[file](#file)
- get_size

[CLI](#CLI) 
- ft_cat
- ft_tail

## Basic Functions
---
### basic
- my_fgetc
    ```c
    int		my_fgetc(int *fd)
    {
	    char	buf;

	    if (0 < read(*fd, &buf, sizeof(char)))
	    	return (buf);
	    return (EOF);
    }
    ```
    목적: file descriptor의 첫글자를 읽어들임. 여러 글자를 읽기 위한 도구.  
    반환: (int) 
    1. read 성공시: fd의 첫 글자의 ASCII 수.  
    2. read 실패시: EOF 반환   
    예시: printf("first char: %c\n", my_fgetc(&fd));

- my_fgets
    ```c
    char	*my_fgets(char *str, int size, int *fd)
    {
    	int		idx;
    	char	buf;

    	idx = 0;
    	while ((0 < (buf = my_fgetc(fd))) && (size - idx))
    		str[idx++] = buf;
    	str[idx] = '\0';
    	return (str);
    }
    ```
    목적: file descriptor를 size만큼 읽어, str에 복사해 넣기.  
    반환: (char *) size 길이의 str (str의 버퍼 크기를 미리 크게 세팅해야함)  
    예시: printf("ret: %s\n", my_fgets(str, 100, &fd));

- my_input()
    ```c
    char	*my_input()
    {
    	unsigned int	ft_strlcpy(char *dst, char *src, unsigned int size);
    	char			*pre;
    	char			*cur;
    	int				size;
    	char			buf;

    	size = 1;
    	if (!(pre = (char *)malloc(sizeof(char) * (size + 1))))
    		return (NULL);
    	pre[size] = '\0';
    	if (!(0 < read(STD_IN, pre, sizeof(char))))
    		return (NULL);
    	while (0 < read(STD_IN, &buf, sizeof(char)))
    	{
    		if (buf == 10)
    			break ;
    		++size;
    		if (!(cur = (char *)malloc(sizeof(char) * (size + 1))))
    			return (NULL);
    		ft_strlcpy(cur, pre, size + 1);
    		cur[size - 1] = buf;
    		cur[size] = '\0';
    		free(pre);
    		pre = cur;
    	}
    	return (cur);	
    }
    ```
    목적: 표준입력으로부터 문자열을 입력받아 (char *) 자료형 변수로 가지고 있기 위함.  
    반환: (char *) 표준입력으로 입력받은 데이터.  
    예시: char **str_split = char **a = ft_split(my_input(), " ");


## Advenced Functions
---
### file
- get_size
    ```c
    int		get_size(char *target)
    {
    	int	fd;
    	int	size;

    	size = 0;
    	if (0 < (fd = open(target, O_RDONLY)))
    	{
    		while (0 < my_fgetc(&fd))
    			++size;
    	}
    	else
    		return (-1);
    	return (size);
    }
    ```
    목적: target의 이름을 가진 파일의 크기를 계산하기 위함.  
    반환: (int) 파일의 크기(글자 수)  
    예시: printf("size of file: %d\n", get_size("test.txt"));

### CLI
- ft_cat
    ```c
    int		ft_cat(int argc, char **argv)
    {
    	int		fd;
    	char	data;
    	char	str[BUF_SIZE];
    	int		size;
    	int		file_idx;
    
    	if (argc == 1)
    	{
    		fd = STD_IN;
    		while (0 < (data = my_fgetc(&fd)))
    			ft_putchar(data);
    	}
    	file_idx = 0;
    	while (++file_idx < argc)
    	{
    		if (0 > (fd = open(argv[file_idx], O_RDONLY)))
    		{
    			show_error(argv[0], argv[file_idx]);
    			return (-1);
    		}
    		size = get_size(argv[file_idx]);
    		ft_putstr(my_fgets(str, size, &fd));
    		close(fd);
    	}
    	return (1);
    }
    ```
    목적: CLI의 cat 명령어와 같이 동작하게 하기 위함.  
    기능: 
    1. 입력된 매개변수(파일)가 없을 때, 표준입력창에 입력된 글자들이 출력.
    2. 입력받은 매개변수(파일)들의 내용을 출력.

    반환: (int) 성공시 1, 실패시 -1.
