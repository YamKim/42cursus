# [42 Seoul] Get Next Line(1) - static variable
Get Next Line 과제를 위한 사전지식을 적은 글입니다. 정적변수에 대해 이야기하겠습니다.  

## Static Variable (정적변수)
### 사용 목적
: 간단하게 말하면, local variable(지역변수)의 값을 기억해두고 싶은 경우, 사용한다고 볼 수 있습니다.  
주어진 과제에서는, get_next_line 함수를 부른 경우, 이전에 읽은 값 중 일부는 지역변수가 기억하고  
있어야합니다. 따라서, 정적변수에, 기억해야할 값들을 넣어두고, 다음 호출시 사용합니다.

### 사용 방법
: 정적변수의 범위는 정적변수를 선언해준 소스파일 및 함수 내부입니다.  
즉, A함수 내부에서 선언한 정적변수는 B함수에서 사용할 수 없을 뿐만 아니라,  
C.c에서 선언한 정적변수를 D.c에서 사용할 수 없습니다.

### 사용 예시
- 아래 예시는, get_next_line에서 구현한 keep_bufs의 일부를 발췌하여 사용했습니다.
- mini_keep_bufs는 함수 내부 정적변수인 backup을 누적해서 더해나갑니다.
```cpp
#include <stdio.h>
#include "get_next_line.h"

char *mini_keep_bufs(char *str) {
	static char *backup;
	char *new_backup;
	// new_backup의 길이를 구하기
	size_t len = ft_strlen(backup) + ft_strlen(str);

	if (!(new_backup = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);

	// new_backup에 backup 값과 새로운 값 복사
	size_t idx = ft_strlcpy(new_backup, backup, len + 1);
	ft_strlcpy(new_backup + idx, str, len + 1);	

	// backup이 new_backup을 가리키도록 설정
	free(backup);
	backup = new_backup;
	return (backup);
}

int main(void) {
	printf("%s\n", mini_keep_bufs("Hello 42"));
	printf("%s\n", mini_keep_bufs(" world, "));
	printf("%s\n", mini_keep_bufs("yekim!"));
	return (0);
}
// 실행 결과
// Hello 42
// Hello 42 world, 
// Hello 42 world, yekim!
```
- 위와 같이, 과제 구현시, 개행문자(\n)가 출현할 때까지 기억해두는 용도 혹은,  
개행문자의 뒷내용을 담아두는 용도로 사용할 수 있습니다.  

### 참고자료  
- [코딩도장 - 79.2 정적 변수 선언하기](https://dojang.io/mod/page/view.php?id=690)
- [코딩도장 - 79.3 정적 함수 사용하기](https://dojang.io/mod/page/view.php?id=691)