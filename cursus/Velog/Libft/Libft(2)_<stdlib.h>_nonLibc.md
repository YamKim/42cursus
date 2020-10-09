stdlib의 함수 및 libc (c 표준 라이브러리)에 포함되지 않는 함수를 구현하는 부분입니다.

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
+ 목적: 문자열으로 숫자를 받을 때, 이를 int형 숫자로 변환(user로부터 input 받을 때 사용).
+ 구현:  
	1. 문자열 nptr의 각 요소에 접근하여 white space인 경우 건너뜁니다.
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

# libc 외
## string technic
### ft_substr
+ 목적: 문자열 s의 부분 문자열을 사용하기 위함.
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

### ft_strjoin
+ 목적: 문자열 s1과 s2를 합하여 하나의 문자열로 사용하기 위함.
+ 구현:  
	1. s1과 s2의 길이를 각각 구하여 합합니다.
	2. 위에서 구한 크기로 만든 버퍼에 s1과 s2 각각을 연이어 복사해 넣습니다.
	3. 이 때, ft_strlcpy를 사용하며, 인덱스를 잘 조정하여 겹치는 값이 없도록 합니다.
```cpp
// 형태
char	*ft_strjoin(char const *s1, char const *s2)
// 사용 예시
int main(void) {
	printf("result: %s\n", ft_strjoin("Hello ", "42 World"));
}
// 출력 결과: 
// result: Hello 42 World
```

### ft_strtrim
+ 목적: 발췌하고자 하는 문자열의 앞, 뒤에서 set의 요소들을 제거하는 것.
+ 구현:  
	1. ft_strchr을 이용하여 s1을 set에서 찾습니다.
	2. 발견하지 못할 때까지 skip하며 발췌할 문자열의 시작/끝 지점을 구합니다.
	3. 시작점을 구할 경우, 0번째 인덱스부터, 끝지점을 구할 경우 마지막 인덱스부터 skip해옵니다. 
	4. 끝지점 - 시작점 + 1개 크기의 버퍼를 만들고, 발췌한 값을 복사합니다.
	5. 시작점이 끝점보다 뒤에 있는 경우, 문자열의 모든 요소가 set에 들어있다는 의미이므로 ""를 반환합니다.
```cpp
// 형태
char *ft_strtrim(char const *s1, char const *set)
// 사용 예시
int main(void) {
	char *res = ft_strtrim("  aabcHello 42 Worldccb  ", " abc");	
	printf("result: %s\n", res);
}
// 출력 결과: 
// result: Hello 42 World
```

### ft_split
+ 목적: 문자열 s에 c가 존재하는 경우, 이를 기준으로 단어를 나누어 배열에 담는 것. 
+ 구현:  
	1. c에 의해 몇 단어로 분리될 수 있는지 셉니다.  
	   (s의 각 요소들과 c를 비교하여 같은 경우 skip하며, 다를 경우 count를 올립니다.)
	2. c + 1개의 버퍼를 만들고, 마지막 요소는 0을 할당하여, 끝 지점임을 알립니다.
	3. 각 버퍼를 몇 글자의 단어로 채울 수 있는지 알기 위해, 단어의 글자수를 셉니다.  
	   (1.과 같이 진행하되, 다를 경우를 지속적으로 count하여, 글자수를 구합니다.)
	4. 각 버퍼에 해당하는 글자수를 알면, 글자수 + 1개의 버퍼를 만들고, 마지막 요소는 NUL을 할당합니다.
	5. 각 버퍼에 구분된 단어를 차례로 복사합니다.  
	   (3~5 과정은 한 루프에서 ret[k]의 인덱스 k를 증가시키며 수행합니다.)  
```cpp
// 형태
char **ft_split(char const *s, char c)
// 사용 예시
int main(void) {
	char *s = "   Hello  42      Word  ";
	char **sp = ft_split(s, ' ');
	for (int i = 0; sp[i]; ++i) {
		printf("sp[%d]:%s,", i, sp[i]);
	}
}
// 출력 결과: 
// sp[0]:Hello,sp[1]:42,sp[2]:Word,%
```
### ft_itoa
+ 목적: int형 정수를 문자열 형태로 변환하기 위함.
+ 구현:  
	1. 10진수의 수는, /10은 몫, %10은 나머지 형태로 표현됩니다.
	2. 먼저 정수의 부호가 무엇인지 조사하고, 양수면 0번째 칸 외의 칸들을 채웁니다.
	3. 음수라면, 0번째 칸을 '-'로 하고 그 외의 칸들을 채웁니다.
	4. 위 과정을 위해, 입력받은 수가 몇자리 수인지 먼저 구합니다.
	5. 자릿수만큼 버퍼를 만들고, /10을 한 수의 %10을 요소로 채워 각 자릿수들을 채웁니다.
	   (이 때, 인덱스를 잘 조정하여 버퍼의 마지막 인덱스부터 채워옵니다.)
```cpp
// 형태
char *ft_itoa(int n)
// 사용 예시
int main(void) {
	printf("result: %s\n", ft_itoa(-4242));
}
// 출력 결과: 
// result: -4242
```

### ft_strmapi
+ 목적: s의 각 요소에 접근하여, 함수 f의 규칙을 적용시키기 위함.
+ 구현:  
	1. f가 적용된 각 요소를 담기 위한 반환값을 만들기 위해, s의 길이를 구합니다.
	2. s의 길이 + 1 크기의 버퍼를 만들고, 마지막 요소는 NUL로 채웁니다.
	3. ret의 각 인덱스에 s의 요소에 f를 적용한 값을 차례로 할당합니다.  
```cpp
// 형태
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
// 사용 예시
char func_mapi(unsigned int idx, char c) {
	if (idx < 5) {
		if (c >= 97 && c <= 122) return (ft_toupper(c));
	}
	return (c);
}
int main(void) {
	char *s = "heLLo 42 WorD";
	char *res = ft_strmapi(s, func_mapi);
	printf("result: %s\n", res);
}
// 출력 결과: 
// result: HELLO 42 WorD
// 설명: 인덱스가 5보다 작은 소문자가 알파벳을 대문자로 바뀜.
```