# ft_printf를 구현하기 위한 사전지식
## variable argument(가변 인수)
### va 사용 방법
- 요구되는 header file
    > <stdarg.h>: va_list, va_start, va_arg, va_end를 포함하는 헤더파일입니다.

- 함수 형식
```cpp
    #include <stdarg.h>
    // 첫 번째 parameter parmN를 설정하고, 뒤에 ...를 넣어 다른 parm들을 받습니다.
    type functionName(parmN, ...) {
        // ...으로 표현되는 parm을 가리키게 될 포인터입니다.
        va_list ap; 

        // parmN을 대입하여, ap가 ...의 첫 param를 가리키도록 합니다.
        va_start(ap, parmN) 
        // 첫 번째 type의 크기만큼 포인터를 이동시키며 첫 번째 parm 값을 반환합니다.
        type1 parm1 = var_arg(ap, type1) 
        // 위와 같은식으로 두번째 값을 반환합니다.
        type2 parm2 = var_arg(ap, type2) 
        ...
        va_end(parmN)
    }
```

### simple_printf 구현
: 본 함수는, libft를 사용하여 구현했습니다.
```cpp
#include <stdarg.h>
#include "../libft/libft.h"

void simple_printf(char *format, ...) {
	va_list ap;

	va_start(ap, format);
	while (*format) {
		if (*format == '%') {
			++format;
			if (*format == 'd') {
				int num = va_arg(ap, int);
				ft_putnbr_fd(num, 1);	
			}
			if (*format == 's') {
				char *str = va_arg(ap, char *);
				ft_putstr_fd(str, 1);
			}
		}
		else
			ft_putchar_fd(*format, 1);
		++format;
	}
}

int main(void) {
	char *format = ft_strdup("Hello %d %s!");	
	simple_printf(format, 42, "World");
	return (0);
}

// 실행 결과:
// Hello 42 World!%
```

## library compile
gcc -o test main.c -L../libft/ -lft


참고링크: 
1. [cpp reference](https://en.cppreference.com/w/c/variadic)
2. [코딩도장](https://dojang.io/mod/page/view.php?id=577)