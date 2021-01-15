#include <stdio.h>

#if 0
int is_space(char c) {
	if (c == 32)
		return (1);
	if (c >= 9 && c <= 13)
		return (1);

	return (0);
}

int is_base(char *base) {
	while (*base) {
		char c = *base;
		if (c == '-')
			return (0);
		if (c == '+')
			return (0);
		if (is_space(c))
			return (0);
		base = base + 1;
	}
	return (1);
}
#endif

//extern int is_space(char c);
extern int is_base(char *base);

int main(void){
	printf("result: %d\n", is_base("-12345"));	
	printf("result: %d\n", is_base("12345"));	
	printf("result: %d\n", is_base("123+45"));	
	printf("result: %d\n", is_base("1234 5"));	
	printf("result: %d\n", is_base("34 5"));	
	printf("result: %d\n", is_base("3425"));	
	return (0);
}
