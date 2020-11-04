#include <stdio.h>
#include <locale.h>
#include <wchar.h>

#include "./incs/ft_printf.h"

void	u_test();
void	d_test();
void	x_test();
void	c_test();
void	s_test();
void	p_test();
void	per_test();
void	tester_error();

int main(void)
{
#if 0
	   printf("ret = %d\n",    printf("%%p::[%010d]\n", 8473));
	ft_printf("ret = %d\n", ft_printf("%%p::[%010d]\n", 8473));
	   printf("ret = %d\n",    printf("%%p::[%10d]\n", 8473));
    ft_printf("ret = %d\n", ft_printf("%%p::[%10d]\n", 8473));
	   printf("ret = %d\n",    printf("%%p::[%010d]\n", -8473));
    ft_printf("ret = %d\n", ft_printf("%%p::[%010d]\n", -8473));
	   printf("ret = %d\n",    printf("%%p::[% 6.3d]\n", 3));
    ft_printf("ret = %d\n", ft_printf("%%p::[% 6.3d]\n", 3));
#endif
	per_test();
	d_test();
	s_test();
	p_test();
	//c_test();
	//printf("st16 %0.*d\n", 3, 2);
	//u_test();
	//tester_error();
	printf("wait for leaks check!\n");
#if 1
	while (1)
	{

	}
#endif
	
#if 0
	char c = 'a';
	int result_f;
	int result_r;
	result_f = ft_printf("f = [%-4.c]\n", c);
	result_r =    printf("r = [%-4.c]\n", c);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("f = [%-4c]\n", c);
	result_r =    printf("r = [%-4c]\n", c);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	
#endif
#if 0
	int result_f;
	int result_r;
	char *s = "abc";
	result_f = ft_printf("-->|%-16.s|<--\n", s);
	result_r =    printf("-->|%-16.s|<--\n", s);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);

#endif
#if 0
	int result_f;
	int result_r;
	result_f = ft_printf("[%%]\n");
	result_r =    printf("[%%]\n");
	result_f = ft_printf("[%-010%]\n");
	result_r =    printf("[%0-10%]\n");
	result_f = ft_printf("[%010%]\n");
	result_r =    printf("[%010%]\n");
	result_f = ft_printf("[%10%]\n");
	result_r =    printf("[%10%]\n");
	result_f = ft_printf("[%-12%]\n");
	result_r =    printf("[%-12%]\n");
#endif
#if 0
	result_f = ft_printf("%d\n", printf("%%\n"));
	result_r =    printf("%d\n", printf("%%\n"));
	result_f = ft_printf("%d\n", printf("truc\n"));
	result_r =    printf("%d\n", printf("truc\n"));
	result_f = ft_printf("percent 1 %012%\n");
	result_r =    printf("percent 1 %012%\n");
	result_f = ft_printf("percent 2 %12%\n");
	result_r =    printf("percent 2 %12%\n");
	result_f = ft_printf("percent 4 %0%\n");
	result_r =    printf("percent 4 %0%\n");
#endif
#if 0
	printf("ret = %d\n", printf("%%p::[%06.3d]\n", 3));
    ft_printf("ret = %d\n", ft_printf("%%p::[%06.3d]\n", 3));
#endif
#if 0
	static char *s_hidden = "hi low\0don't print me lol\0";
	(void)str;
	(void)s_hidden;
	(void)result_r;
	result_f = ft_printf("f = [%.00s]\n", "\0");
	printf("result_f = %d\n\n", result_f);
	result_f = ft_printf("f = [%.01s]\n", "\0");
	printf("result_f = %d\n\n", result_f);
	result_f = ft_printf("f = [%.03s]\n", "\0");
	printf("result_f = %d\n\n", result_f);
	result_f = ft_printf("f = [%.09s]\n", "\0");
	printf("result_f = %d\n\n", result_f);
#endif
#if 1
#endif
#if 0
	result_f = ft_printf("f = [%0+10d]\n", -123);
	result_r =    printf("r = [%0+10d]\n", -123);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("f = [%e]\n", -123.456);
	result_r =    printf("r = [%e]\n", -123.456);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("f = [%e]\n", 123.456);
	result_r =    printf("r = [%e]\n", 123.456);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("f = [% 30.15e]\n", 123.456);
	result_r =    printf("r = [% 30.15e]\n", 123.456);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("f = [%030.15e]\n", 123.456);
	result_r =    printf("r = [%030.15e]\n", 123.456);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);


	result_f = ft_printf("f = [%e]\n", -123.45678901234);
	result_r =    printf("r = [%e]\n", -123.45678901234);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);

	result_f = ft_printf("f = [%e]\n", 123.45678901234);
	result_r =    printf("r = [%e]\n", 123.45678901234);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);

	result_f = ft_printf("f = [% 30.15e]\n", 123.45678901234);
	result_r =    printf("r = [% 30.15e]\n", 123.45678901234);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);

	result_f = ft_printf("f = [%030.15e]\n", 123.45678901234);
	result_r =    printf("r = [%030.15e]\n", 123.45678901234);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);

	setlocale(LC_ALL, "");
	wchar_t msg[] = L"안녕하세요.";
	printf("%d\n", printf("%lc\n", msg[0]));
	printf("%d\n", printf("%ls\n", msg));
	ft_printf("%d\n", ft_printf("%lc\n", msg[0]));
	ft_printf("%d\n", ft_printf("%ls\n", msg));

	result_r =    printf("r = [%10lc]\n", L'\0');
	result_f = ft_printf("f = [%10lc]\n", L'\0');
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);

	result_r =    printf("r = [%10lc]\n", L"안녕하세요."[1]);
	result_f = ft_printf("f = [%10lc]\n", L"안녕하세요."[1]);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_r =    printf("r = [%-30lc]\n", L"안녕하세요."[1]);
	result_f = ft_printf("f = [%-30lc]\n", L"안녕하세요."[1]);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_r =    printf("r = [%ls]\n", L"안녕하세요.");
	result_f = ft_printf("f = [%ls]\n", L"안녕하세요.");
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_r =    printf("r = [%-30ls]\n", L"안녕하세요.");
	result_f = ft_printf("f = [%-30ls]\n", L"안녕하세요.");
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);


	printf("aaaaaaaaaaaaaaaaaaaaa\n\n");
	ft_printf("%10p\n", "ptr");
	printf("%10p\n", "ptr");
	printf("aaaaaaaaaaaaaaaaaaaaa\n\n");
	ft_printf("%*.p\n", -15, "ptr");
	printf("%*.p\n", -15, "ptr");
	printf("aaaaaaaaaaaaaaaaaaaaa\n\n");
	ft_printf("%.p\n", NULL);
	printf("%.p\n", NULL);
#endif

	system("leaks a.out > leaks_result && cat leaks_result | grep leaked");
	return 0;
}

void	u_test(void) {
	int result_f;
	int result_r;
	result_f =    printf("%d\n", printf("%-.12u\n", -20000000));
	result_r = ft_printf("%d\n", ft_printf("%-.12u\n", -20000000));
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("f = [%-20.30u]\n", 1231248678);
	result_r =    printf("r = [%-20.30u]\n", 1231248678);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("f = [%u]\n", 17);
	result_r =	  printf("r = [%u]\n", 17);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("f = [%u]\n", 0);
	result_r =    printf("r = [%u]\n", 0);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("f = [%u]\n", 3);
	result_r =    printf("r = [%u]\n", 3);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("r = [%u]\n", 4294967295u);
	result_r =    printf("r = [%u]\n", 4294967295u);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("r = [%7u]\n", 33);
	result_r =    printf("r = [%7u]\n", 33);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("r = [%3u]\n", 0);
	result_r =    printf("r = [%3u]\n", 0);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("r = [%5u]\n", 52625);
	result_r =    printf("r = [%5u]\n", 52625);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("r = [%4u]\n", 94827);
	result_r =    printf("r = [%4u]\n", 94827);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("r = [%-7u]\n", 33);
	result_r =    printf("r = [%-7u]\n", 33);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("r = [%-3u]\n", 0);
	result_r =    printf("r = [%-3u]\n", 0);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("r = [%-5u]\n", 52625);
	result_r =    printf("r = [%-5u]\n", 52625);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("r = [%-4u]\n", 94827);
	result_r =    printf("r = [%-4u]\n", 94827);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("r = [%.5u]\n", 2);
	result_r =    printf("r = [%.5u]\n", 2);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("r = [%.3u]\n", 0);
	result_r =    printf("r = [%.3u]\n", 0);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("r = [%.4u]\n", 5263);
	result_r =    printf("r = [%.4u]\n", 5263);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("r = [%.3u]\n", 13862);
	result_r =    printf("r = [%.3u]\n", 13862);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("r = [%05u]\n", 43);
	result_r =    printf("r = [%05u]\n", 43);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("r = [%03u]\n", 0);
	result_r =    printf("r = [%03u]\n", 0);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("r = [%03u]\n", 634);
	result_r =    printf("r = [%03u]\n", 634);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("r = [%8.5u]\n", 34);
	result_r =    printf("r = [%8.5u]\n", 34);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("r = [%8.5u]\n", 0);
	result_r =    printf("r = [%8.5u]\n", 0);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_r = ft_printf("r = [%8.3u]\n", 8375);
	result_r =    printf("r = [%8.3u]\n", 8375);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_r = ft_printf("r = [%3.7u]\n", 3267);
	result_r =    printf("r = [%3.7u]\n", 3267);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("r = [%-8.5u]\n", 0);
	result_r =    printf("r = [%-8.5u]\n", 0);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("r = [%-8.3u]\n", 8375);
	result_r =    printf("r = [%-8.3u]\n", 8375);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("r = [%-3.7u]\n", 3267);
	result_r =    printf("r = [%-3.7u]\n", 3267);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("r = [%-3.3u]\n", 6983);
	result_r =    printf("r = [%-3.3u]\n", 6983);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);

	// not printf case
	result_f = ft_printf("%08.5u\n", 34);
//	result_r =    printf("%08.5u", 34);
	printf("result_f = %d\n\n", result_f);
//	printf("result_r = %d\n\n", result_r);
	result_f = ft_printf("%08.5u\n", 0);
//	result_r =    printf("%08.5u", 0);
	printf("result_f = %d\n\n", result_f);
//	printf("result_r = %d\n\n", result_r);
	result_f = ft_printf("%08.3u\n", 8375);
//	result_r =    printf("%08.3u", 8375);
	printf("result_f = %d\n\n", result_f);
//	printf("result_r = %d\n\n", result_r);
	result_f = ft_printf("%03.7u\n", 3267);
//	result_r =    printf("%03.7u", 3267);
	printf("result_f = %d\n\n", result_f);
//	printf("result_r = %d\n\n", result_r);
	result_f = ft_printf("%03.3u\n", 6983);
//	result_r =    printf("%03.3u", 6983);
	printf("result_f = %d\n\n", result_f);
//	printf("result_r = %d\n\n", result_r);
	result_f = ft_printf("%0-8.5u\n", 34);
//	result_r =    printf("%0-8.5u", 34);
	printf("result_f = %d\n\n", result_f);
//	printf("result_r = %d\n\n", result_r);
	result_f = ft_printf("%0-8.5u\n", 0);
//	result_r =    printf("%0-8.5u", 0);
	printf("result_f = %d\n\n", result_f);
//	printf("result_r = %d\n\n", result_r);
	result_f = ft_printf("%0-8.3u\n", 8375);
//	result_r =    printf("%0-8.3u", 8375);
	printf("result_f = %d\n\n", result_f);
//	printf("result_r = %d\n\n", result_r);
	result_f = ft_printf("%0-3.7u\n", 3267);
//	result_r =    printf("%0-3.7u", 3267);
	printf("result_f = %d\n\n", result_f);
//	printf("result_r = %d\n\n", result_r);
	result_f = ft_printf("%0-3.3u\n", 6983);
//	result_r =    printf("%0-3.3u", 6983);
	printf("result_f = %d\n\n", result_f);
//	printf("result_r = %d\n\n", result_r);

	result_f = ft_printf("%3.0uasdsadf\n", 0);
	result_r =    printf("%3.0uasdsadf\n", 0);
	printf("result_f = %d\n"  , result_f);
	printf("result_r = %d\n\n", result_r);
}

void d_test(void) {
	int result_f;
	int result_r;
	printf("%0*.*d", -4, 5, 42);
	printf("%+-.d", 42);
	int d;

#if 0
	printf("For Velog===================================\n");
	printf("unsigned case===============================\n");
	d = 4242;
	printf("case1\n");
	result_f = ft_printf("-->|%2d|<--\n", d);
	result_r =    printf("-->|%2d|<--\n", d);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	printf("case2\n");
	result_f = ft_printf("-->|%8d|<--\n", d);
	result_r =    printf("-->|%8d|<--\n", d);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	printf("case3\n");
	result_f = ft_printf("-->|%.3d|<--\n", d);
	result_r =    printf("-->|%.3d|<--\n", d);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	printf("case4\n");
	result_f = ft_printf("-->|%1.1d|<--\n", d);
	result_r =    printf("-->|%1.1d|<--\n", d);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	printf("case5\n");
	result_f = ft_printf("-->|%6.3d|<--\n", d);
	result_r =    printf("-->|%6.3d|<--\n", d);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	printf("case6\n");
	result_f = ft_printf("-->|%.7d|<--\n", d);
	result_r =    printf("-->|%.7d|<--\n", d);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	printf("case7\n");
	result_f = ft_printf("-->|%4.7d|<--\n", d);
	result_r =    printf("-->|%4.7d|<--\n", d);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	printf("case8\n");
	result_f = ft_printf("-->|%10.7d|<--\n", d);
	result_r =    printf("-->|%10.7d|<--\n", d);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
#endif

#if 0
	printf("For Velog===================================\n");
	printf("signed case=================================\n");
	int d = -4242;
	printf("case1\n");
	result_f = ft_printf("-->|%2d|<--\n", d);
	result_r =    printf("-->|%2d|<--\n", d);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	printf("case2\n");
	result_f = ft_printf("-->|%8d|<--\n", d);
	result_r =    printf("-->|%8d|<--\n", d);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	printf("case3\n");
	result_f = ft_printf("-->|%.3d|<--\n", d);
	result_r =    printf("-->|%.3d|<--\n", d);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	printf("case4\n");
	result_f = ft_printf("-->|%1.1d|<--\n", d);
	result_r =    printf("-->|%1.1d|<--\n", d);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	printf("case5\n");
	result_f = ft_printf("-->|%6.3d|<--\n", d);
	result_r =    printf("-->|%6.3d|<--\n", d);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	printf("case6\n");
	result_f = ft_printf("-->|%.7d|<--\n", d);
	result_r =    printf("-->|%.7d|<--\n", d);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	printf("case7\n");
	result_f = ft_printf("-->|%4.7d|<--\n", d);
	result_r =    printf("-->|%4.7d|<--\n", d);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	printf("case8\n");
	result_f = ft_printf("-->|%10.7d|<--\n", d);
	result_r =    printf("-->|%10.7d|<--\n", d);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
#endif

#if 0
	printf("For Velog===================================\n");
	printf("zero flag===================================\n");
	d = -4242;
	printf("case2\n");
	result_f = ft_printf("-->|%08d|<--\n", d);
	result_r =    printf("-->|%08d|<--\n", d);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
#endif

#if 1
	printf("For Velog===================================\n");
	printf("asterisk case===============================\n");
	d = -4242;
	printf("case1\n");
	result_f = ft_printf("-->|%*d|<--\n", -6, d);
	result_r =    printf("-->|%*d|<--\n", -6, d);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	printf("case2\n");
	result_f = ft_printf("-->|%0*d|<--\n", 6, d);
	result_r =    printf("-->|%0*d|<--\n", 6, d);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	printf("case3\n");
	result_f = ft_printf("-->|%0*d|<--\n", -6, d);
	result_r =    printf("-->|%0*d|<--\n", -6, d);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	printf("case4\n");
	result_f = ft_printf("-->|%.*d|<--\n", -5, d);
	result_r =    printf("-->|%.*d|<--\n", -5, d);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	printf("case5\n");
	result_f = ft_printf("-->|%010.*d|<--\n", -5, d);
	result_r =    printf("-->|%010.*d|<--\n", -5, d);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
#endif

#if 0
	int d = 12;
	printf("case1\n");
	result_r =    printf("lover |%04.*d|\n", -5, d);
	result_f = ft_printf("lover |%04.*d|\n", -5, d);
	printf("result_r = %d\n", result_r);
	printf("result_f = %d\n\n", result_f);
	printf("case2\n");
	result_r =    printf("lover |%04.*d|\n", 5, d);
	result_f = ft_printf("lover |%04.*d|\n", 5, d);
	printf("result_r = %d\n", result_r);
	printf("result_f = %d\n\n", result_f);
	printf("case4\n");
	result_r =    printf("lover |%0*.d|\n", 4, d);
	result_f = ft_printf("lover |%0*.d|\n", 4, d);
	printf("result_r = %d\n", result_r);
	printf("result_f = %d\n\n", result_f);
	printf("case5\n");
	result_r =    printf("lover |%0*.*d|\n", 4, 0, d);
	result_f = ft_printf("lover |%0*.*d|\n", 4, 0, d);
	printf("result_r = %d\n", result_r);
	printf("result_f = %d\n\n", result_f);
	printf("case6\n");
	result_r =    printf("lover |%0*.0d|\n", 4, d);
	result_f = ft_printf("lover |%0*.0d|\n", 4, d);
	printf("result_r = %d\n", result_r);
	printf("result_f = %d\n\n", result_f);
	d = -12;
	printf("case7\n");
	result_r =    printf("lover |%04.d|\n", d);
	result_f = ft_printf("lover |%04.d|\n", d);
	printf("result_r = %d\n", result_r);
	printf("result_f = %d\n\n", result_f);
	printf("case8\n");
	result_r =    printf("lover |%04.*d|\n", 0, d);
	result_f = ft_printf("lover |%04.*d|\n", 0, d);
	printf("result_r = %d\n", result_r);
	printf("result_f = %d\n\n", result_f);
	printf("case9\n");
	result_r =    printf("lover |%04.0d|\n", d);
	result_f = ft_printf("lover |%04.0d|\n", d);
	printf("result_r = %d\n", result_r);
	printf("result_f = %d\n\n", result_f);
	d = 12;
	printf("case10\n");
	result_r =    printf("lover |%+0*.0d|\n", 4, d);
	result_f = ft_printf("lover |%+0*.0d|\n", 4, d);
	printf("result_r = %d\n", result_r);
	printf("result_f = %d\n\n", result_f);
	printf("case11\n");
	result_r =    printf("lover |%04d|\n", d);
	result_f = ft_printf("lover |%04d|\n", d);
	printf("result_r = %d\n", result_r);
	printf("result_f = %d\n\n", result_f);
#endif




#if 0
	result_r =    printf("[%0.*d]\n", 50, 5);
	result_f = ft_printf("[%0.*d]\n", 50, 5);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_r =    printf("[%10.5d]\n", 5);
	result_f = ft_printf("[%10.5d]\n", 5);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_r =    printf("[%*.*d]\n", 0, 50, 5);
	result_f = ft_printf("[%*.*d]\n", 0, 50, 5);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_r =    printf("[%.*d]\n", 3, 2);
	result_f = ft_printf("[%.*d]\n", 3, 2);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);

	result_f =    printf("%d\n", printf("%-.12i\n", -20000000));
	result_r = ft_printf("%d\n", ft_printf("%-.12i\n", -20000000));
	result_f =    printf("%d\n", printf("%-.12d\n", -20000000));
	result_r = ft_printf("%d\n", ft_printf("%-.12d\n", -20000000));
	result_f =    printf("ret = %d\n",    printf("%%p::[%-4d]\n", -2464));
    result_r = ft_printf("ret = %d\n", ft_printf("%%p::[%-4d]\n", -2464));
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f =    printf("ret = %d\n",    printf("%%p::[%-5d]\n", -2464));
    result_r = ft_printf("ret = %d\n", ft_printf("%%p::[%-5d]\n", -2464));
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f =    printf("ret = %d\n",    printf("%%p::[%.5d]\n", -2464));
    result_r = ft_printf("ret = %d\n", ft_printf("%%p::[%.5d]\n", -2464));
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("f = [% 10.5d]\n", 123);
	result_r =    printf("r = [% 10.5d]\n", 123);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("f = [%- .5d]\n", -123);
	result_r =    printf("r = [%- .5d]\n", -123);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("f = [% d]\n", 123);
	result_r =    printf("r = [% d]\n", 123);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("f = [%+d]\n", 123);
	result_r =    printf("r = [%+d]\n", 123);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("f = [% 10.5d]\n", 123);
	result_r =    printf("r = [% 10.5d]\n", 123);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("f = [%+10.5d]\n", 123);
	result_r =    printf("r = [%+10.5d]\n", 123);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("f = [%d]\n", -1);
	result_r =    printf("r = [%d]\n", -1);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("f = [%+d]\n", -123);
	result_r =    printf("r = [%+d]\n", -123);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("f = [% 10.5d]\n", -123);
	result_r =    printf("r = [% 10.5d]\n", -123);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("f = [%+10.5d]\n", -123);
	result_r =    printf("r = [%+10.5d]\n", -123);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("f = [%d]\n", -1);
	result_r =    printf("r = [%d]\n", -1);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("f = [%+d]\n", -123);
	result_r =    printf("r = [%+d]\n", -123);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("f = [% 10d]\n", -123);
	result_r =    printf("r = [% 10d]\n", -123);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("f = [%+10d]\n", -123);
	result_r =    printf("r = [%+10d]\n", -123);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("f = [%0d]\n", -1);
	result_r =    printf("r = [%0d]\n", -1);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("f = [%0+4d]\n", -123);
	result_r =    printf("r = [%0+4d]\n", -123);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("f = [%0+10d]\n", -123);
	result_r =    printf("r = [%0+10d]\n", -123);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
#endif
}

void x_test(void)
{
	int result_r;
	int result_f;
//Hexadecimal lowers - no modifers
	result_f = ft_printf("result_f: [%x]\n", 17);
	result_r =    printf("result_r: [%x]\n", 17);
	printf("length\nresult_f: %d\nresult_r: %d\n\n", result_f, result_r);
	result_f = ft_printf("result_f: [%x]\n", 0);
	result_r =    printf("result_r: [%x]\n", 0);
	printf("length\nresult_f: %d\nresult_r: %d\n\n", result_f, result_r);
	result_f = 	ft_printf("result_f: [%x]\n", 3);
	result_r =    printf("result_r: [%x]\n", 3);
	printf("length\nresult_f: %d\nresult_r: %d\n\n", result_f, result_r);
	result_f = 	ft_printf("result_f: [%x]\n", 4294967295u);
	result_r =    printf("result_r: [%x]\n", 4294967295u);
	printf("length\nresult_f: %d\nresult_r: %d\n\n", result_f, result_r);
//Hexadecimal lowers with field width
	result_f = 	ft_printf("result_f: [%7x]\n", 33);
	result_r =    printf("result_r: [%7x]\n", 33);
	printf("length\nresult_f: %d\nresult_r: %d\n\n", result_f, result_r);
	result_f = 	ft_printf("result_f: [%3x]\n", 0);
	result_r =    printf("result_r: [%3x]\n", 0);
	printf("length\nresult_f: %d\nresult_r: %d\n\n", result_f, result_r);
	result_f = 	ft_printf("result_f: [%5x]\n", 52625);
	result_r =    printf("result_r: [%5x]\n", 52625);
	printf("length\nresult_f: %d\nresult_r: %d\n\n", result_f, result_r);
	result_f = 	ft_printf("result_f: [%2x]\n", 94827);
	result_r =    printf("result_r: [%2x]\n", 94827);
	printf("length\nresult_f: %d\nresult_r: %d\n\n", result_f, result_r);
	result_f = 	ft_printf("result_f: [%-7x]\n", 33);
	result_r =    printf("result_r: [%-7x]\n", 33);
	printf("length\nresult_f: %d\nresult_r: %d\n\n", result_f, result_r);
	result_f = 	ft_printf("result_f: [%-3x]\n", 0);
	result_r =    printf("result_r: [%-3x]\n", 0);
	printf("length\nresult_f: %d\nresult_r: %d\n\n", result_f, result_r);
	result_f = 	ft_printf("result_f: [%-5x]\n", 52625);
	result_r =    printf("result_r: [%-5x]\n", 52625);
	printf("length\nresult_f: %d\nresult_r: %d\n\n", result_f, result_r);
	result_f = 	ft_printf("result_f: [%-4x]\n", 9648627);
	result_r =    printf("result_r: [%-4x]\n", 9648627);
	printf("length\nresult_f: %d\nresult_r: %d\n\n", result_f, result_r);
	printf("Hexadecimal lowers with precision\n");
	result_f = 	ft_printf("result_f: [%.5x]\n", 21);
	result_r =    printf("result_r: [%.5x]\n", 21);
	printf("length\nresult_f: %d\nresult_r: %d\n\n", result_f, result_r);
	result_f = 	ft_printf("result_f: [%.3x]\n", 0);
	result_r =    printf("result_r: [%.3x]\n", 0);
	printf("length\nresult_f: %d\nresult_r: %d\n\n", result_f, result_r);
	result_f = 	ft_printf("result_f: [%.4x]\n", 5263);
	result_r =    printf("result_r: [%.4x]\n", 5263);
	printf("length\nresult_f: %d\nresult_r: %d\n\n", result_f, result_r);
	result_f = 	ft_printf("result_f: [%.3x]\n", 938862);
	result_r =    printf("result_r: [%.3x]\n", 938862);
	printf("length\nresult_f: %d\nresult_r: %d\n\n", result_f, result_r);
//Hex\nadecimal lowers with zero field width padding
//	printf("result_r: %05x\n", 43);
//	printf("result_r: %03x\n", 0);
//	printf("result_r: %03x\n", 698334);
//Hex\nadecimal lowers with field width and precision
	result_f = ft_printf("result_f: [%8.5x]\n", 34);
	result_r =    printf("result_r: [%8.5x]\n", 34);
	printf("length\nresult_f: %d\nresult_r: %d\n\n", result_f, result_r);
	result_f = ft_printf("result_f: [%8.5x]\n", 0);
	result_r =    printf("result_r: [%8.5x]\n", 0);
	printf("length\nresult_f: %d\nresult_r: %d\n\n", result_f, result_r);
	result_f = ft_printf("result_f: [%8.3x]\n", 8375);
	result_r =    printf("result_r: [%8.3x]\n", 8375);
	printf("length\nresult_f: %d\nresult_r: %d\n\n", result_f, result_r);
	result_f = ft_printf("result_f: [%2.7x]\n", 3267);
	result_r =    printf("result_r: [%2.7x]\n", 3267);
	printf("length\nresult_f: %d\nresult_r: %d\n\n", result_f, result_r);
	result_f = ft_printf("result_f: [%3.3x]\n", 6983);
	result_r =    printf("result_r: [%3.3x]\n", 6983);
	printf("length\nresult_f: %d\nresult_r: %d\n\n", result_f, result_r);
//Hex\nadecimal lowers with field width and precision, left-justified
	result_f = ft_printf("result_f: [%-8.5x]\n", 34);
	result_r =    printf("result_r: [%-8.5x]\n", 34);
	printf("length\nresult_f: %d\nresult_r: %d\n\n", result_f, result_r);
	result_f = ft_printf("result_f: [%-8.5x]\n", 0);
	result_r =    printf("result_r: [%-8.5x]\n", 0);
	printf("length\nresult_f: %d\nresult_r: %d\n\n", result_f, result_r);
	result_f = ft_printf("result_f: [%-8.3x]\n", 8375);
	result_r =    printf("result_r: [%-8.3x]\n", 8375);
	printf("length\nresult_f: %d\nresult_r: %d\n\n", result_f, result_r);
	result_f = ft_printf("result_f: [%-2.7x]\n", 3267);
	result_r =    printf("result_r: [%-2.7x]\n", 3267);
	printf("length\nresult_f: %d\nresult_r: %d\n\n", result_f, result_r);
	result_f = ft_printf("result_f: [%-3.3x]\n", 6983);
	result_r =    printf("result_r: [%-3.3x]\n", 6983);
	printf("length\nresult_f: %d\nresult_r: %d\n\n", result_f, result_r);
//Hex\nadecimal lowers with field width and precision with zeropadding
//	printf("result_r: result_r: %08.5x\n", 34);
//	printf("result_r: %08.5x\n", 0);
//	printf("result_r: %08.3x\n", 8375);
//	printf("result_r: %02.7x\n", 3267);
//	printf("result_r: %03.3x\n", 6983);
//Hex\nadecimal lowers with field width and precision, left-justified with zeropadding
//	printf("result_r: %0-8.5x\n", 34);
//	printf("result_r: %0-8.5x\n", 0);
//	printf("result_r: %0-8.3x\n", 8375);
//	printf("result_r: %0-2.7x\n", 3267);
//	printf("result_r: %0-3.3x\n", 6983);
	printf("Hexadecimal lower - zero precision zero value\n");
	result_f = ft_printf("result_f: [%.0x]\n", 15);
	result_r =    printf("result_r: [%.0x]\n", 15);
	printf("length\nresult_f: %d\nresult_r: %d\n\n", result_f, result_r);
	result_f = ft_printf("result_f: [%.0x]\n", 0);
	result_r =    printf("result_r: [%.0x]\n", 0);
	printf("length\nresult_f: %d\nresult_r: %d\n\n", result_f, result_r);
	result_f = ft_printf("result_f: [%.x]\n", 0);
	result_r =    printf("result_r: [%.x]\n", 0);
	printf("length\nresult_f: %d\nresult_r: %d\n\n", result_f, result_r);
	result_f = ft_printf("result_f: [%5.0x]\n", 0);
	result_r =    printf("result_r: [%5.0x]\n", 0);
	printf("length\nresult_f: %d\nresult_r: %d\n\n", result_f, result_r);
	result_f = ft_printf("result_f: [%5.x]\n", 0);
	result_r =    printf("result_r: [%5.x]\n", 0);
	printf("length\nresult_f: %d\nresult_r: %d\n\n", result_f, result_r);
	result_f = ft_printf("result_f: [%-5.0x]\n", 0);
	result_r =    printf("result_r: [%-5.0x]\n", 0);
	printf("length\nresult_f: %d\nresult_r: %d\n\n", result_f, result_r);
	result_f = ft_printf("result_f: [%-5.x]\n", 0);
	result_r =    printf("result_r: [%-5.x]\n", 0);
	printf("length\nresult_f: %d\nresult_r: %d\n\n", result_f, result_r);

}

void c_test(void) {
	int result_r;
	int result_f;
	char c = 'a';
	for (int i = 0; i < 128; ++i)
		printf("|%4.c|\n", i);

	result_f = ft_printf("-->|%2.c|<--\n", c);
	result_r =    printf("-->|%2.c|<--\n", c);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
#if 1
	result_f =    printf("-->|%-4.c|<--\n", c); 
	result_r = ft_printf("-->|%-4.c|<--\n", c); 
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f =    printf("-->|%-4c|<--\n", c);  
	result_r = ft_printf("-->|%-4c|<--\n", c);  
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f =    printf("-->|%-3.c|<--\n", c); 
	result_r = ft_printf("-->|%-3.c|<--\n", c); 
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f =    printf("-->|%-3c|<--\n", c);  
	result_r = ft_printf("-->|%-3c|<--\n", c);  
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f =    printf("-->|%-2.c|<--\n", c); 
	result_r = ft_printf("-->|%-2.c|<--\n", c); 
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f =    printf("-->|%-2c|<--\n", c);  
	result_r = ft_printf("-->|%-2c|<--\n", c);  
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
#endif
}

void s_test(void) {
	int result_r;
	int result_f;
	char *s = "42Seoul";
	printf("For velog\n");
	printf("case1\n");
	result_f = ft_printf("-->|%3s|<--\n", s);
	result_r =    printf("-->|%3s|<--\n", s);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	printf("case2\n");
	result_f = ft_printf("-->|%10s|<--\n", s);
	result_r =    printf("-->|%10s|<--\n", s);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	printf("case3\n");
	result_f = ft_printf("-->|%.4s|<--\n", s);
	result_r =    printf("-->|%.4s|<--\n", s);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	printf("case4\n");
	result_f = ft_printf("-->|%3.4s|<--\n", s);
	result_r =    printf("-->|%3.4s|<--\n", s);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	printf("case5\n");
	result_f = ft_printf("-->|%7.4s|<--\n", s);
	result_r =    printf("-->|%7.4s|<--\n", s);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	printf("case6\n");
	result_f = ft_printf("-->|%.9s|<--\n", s);
	result_r =    printf("-->|%.9s|<--\n", s);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	printf("case7\n");
	result_f = ft_printf("-->|%7.9s|<--\n", s);
	result_r =    printf("-->|%7.9s|<--\n", s);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	printf("case8\n");
	result_f = ft_printf("-->|%10.9s|<--\n", s);
	result_r =    printf("-->|%10.9s|<--\n", s);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
#if 0
	result_f = ft_printf("-->|%-16.s|<--\n", s);
	result_r =    printf("-->|%-16.s|<--\n", s);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("p3 %.4s\n", NULL);
	result_r =    printf("p3 %.4s\n", NULL);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("p3 %4s\n", NULL);
	result_r =    printf("p3 %4s\n", NULL);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("f = [%c]\n", '\0');
	result_r =    printf("r = [%c]\n", '\0');
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("f = [%-20s]\n", "asdfsadf");
	result_r =    printf("r = [%-20s]\n", "asdfsadf");
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("f = [%-*.*s]\n", 0, 20, "asdfsadf");
	result_r =    printf("r = [%-*.*s]\n", 0, 20, "asdfsadf");
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("f = [%-*.*s]\n", 20, -3, "asdfsadf");
	result_r =    printf("r = [%-*.*s]\n", 20, -3, "asdfsadf");
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("f = [%-*.20s]\n", 20, "asdfsadf");
	result_r =    printf("r = [%-*.20s]\n", 20, "asdfsadf");
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("f = [%*.3s]\n", 20, "asdfsadf");
	result_r =    printf("r = [%*.3s]\n", 20, "asdfsadf");
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	printf("case 7\n");
	result_f = ft_printf("f = [%20.15s]\n", "asdfsadf");
	result_r =    printf("r = [%20.15s]\n", "asdfsadf");
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	printf("case 8\n");
	result_f = ft_printf("f = [%7.15s]\n", "asdfsadf");
	result_r =    printf("r = [%7.15s]\n", "asdfsadf");
	printf("asdfsadf\n");
	result_f = ft_printf("f = [%5.10s]\n", "asdfsadf");
	result_r =    printf("r = [%5.10s]\n", "asdfsadf");
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("f = [%10.10s]\n", "asdfsadf");
	result_r =    printf("r = [%10.10s]\n", "asdfsadf");
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("f = [%3.4s]\n", "asdfsadf");
	result_r =    printf("r = [%3.4s]\n", "asdfsadf");
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("f = [%10.4s]\n", "asdfsadf");
	result_r =    printf("r = [%10.4s]\n", "asdfsadf");
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("f = [%c]\n", '\0');
	result_f = ft_printf("f = [%c]\n", '\0');
	result_f = ft_printf("f = [%c]\n", '\0');
	result_r =    printf("r = [%c]\n", '\0');
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("f = [%-5c]\n", 'a');
	result_r =    printf("r = [%-5c]\n", 'a');
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("f = [%-.5s]\n", "\0");
	result_r =    printf("r = [%-.5s]\n", "\0");
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("f = [%-.5s]\n", "\0");
	result_r =    printf("r = [%-.5s]\n", "\0");
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
#endif
}

void p_test(void)
{
	int result_f;
	int result_r;
	char *strNULL = "\0";
	result_f = ft_printf("f = [%p]\n", strNULL);
	result_r =    printf("r = [%p]\n", strNULL);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	char *str = "abcd";
	result_f = ft_printf("f = [%5p]\n", str);
	result_r =    printf("r = [%5p]\n", str);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("f = [%-20p]\n", str);
	result_r =    printf("r = [%-20p]\n", str);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("f = [%-20p]\n", (void *)0);
	result_r =    printf("r = [%-20p]\n", (void *)0);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);


}

void per_test(void)
{
	int result_f;
	int result_r;
	result_f = ft_printf("-->|%-4.*%|<--\n", 1);
	result_r =    printf("-->|%-4.*%|<--\n", 1);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("-->|%-4.1%|<--\n");
	result_r =    printf("-->|%-4.1%|<--\n");
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("-->|%0.%|<--\n");
	result_r =    printf("-->|%0.%|<--\n");
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("-->|%0.*%|<--\n", -4);
	result_r =    printf("-->|%0.*%|<--\n", -4);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("-->|%0.*%|<--\n", -3);
	result_r =    printf("-->|%0.*%|<--\n", -3);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("-->|%0.*%|<--\n", -2);
	result_r =    printf("-->|%0.*%|<--\n", -2);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("-->|%0.*%|<--\n", -1);
	result_r =    printf("-->|%0.*%|<--\n", -1);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("-->|%0.*%|<--\n", 0); 
	result_r =    printf("-->|%0.*%|<--\n", 0); 
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("-->|%0.*%|<--\n", 1); 
	result_r =    printf("-->|%0.*%|<--\n", 1); 
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("-->|%0.*%|<--\n", 2); 
	result_r =    printf("-->|%0.*%|<--\n", 2); 
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("-->|%0.*%|<--\n", 3); 
	result_r =    printf("-->|%0.*%|<--\n", 3); 
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("-->|%0.*%|<--\n", 4); 
	result_r =    printf("-->|%0.*%|<--\n", 4); 
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("-->|%0.0%|<--\n");
	result_r =    printf("-->|%0.0%|<--\n");
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("-->|%0.1%|<--\n");
	result_r =    printf("-->|%0.1%|<--\n");
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("-->|%0.2%|<--\n");
	result_r =    printf("-->|%0.2%|<--\n");
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("-->|%0.3%|<--\n");
	result_r =    printf("-->|%0.3%|<--\n");
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("-->|%0.4%|<--\n");
	result_r =    printf("-->|%0.4%|<--\n");
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("-->|%0%|<--\n");  
	result_r =    printf("-->|%0%|<--\n");  
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
}

void tester_error(void)
{
	int result_f;
	int result_r;
	(void)result_f;
	(void)result_r;
	//result_f = ft_printf("|%53c|\n|%0189.51d|\n|%-103.21d|\n|%*p|\n|%102c|\n" ,-27,231647176,-1119242596,-94,(void*)17541392615378030860lu,80);
	//result_r =    printf("|%53c|\n|%0189.51d|\n|%-103.21d|\n|%*p|\n|%102c|\n" ,-27,231647176,-1119242596,-94,(void*)17541392615378030860lu,80);
	//printf("result_f = %d\n", result_f);
	//printf("result_r = %d\n\n",result_r);
#if 0
	result_f = ft_printf("|%*p|\n" ,-94,(void*)17541392615378030860lu);
	result_r =    printf("|%*p|\n" ,-94,(void*)17541392615378030860lu);
	printf("result_f = %d\n", result_f);
	printf("result_r = %d\n\n",result_r);
	result_f = ft_printf("|%*p|\n" ,-94,(void*)175413926153u);
	result_r =    printf("|%*p|\n" ,-94,(void*)175413926153u);
	printf("result_f = %d\n", result_f);
	printf("result_r = %d\n\n",result_r);
	result_f = ft_printf("|%*x|\n" ,-94, 17541615u);
	result_r =    printf("|%*x|\n" ,-94, 17541615u);
	printf("result_f = %d\n", result_f);
	printf("result_r = %d\n\n",result_r);
	result_f = ft_printf("%117.51s%0022.90i%106.16s%-26p%--83.182u" ,"\\w/D^i\\5I1Fo_t|jL{1:78",302655923,"#Xcwl?d@KjMTSDV^Qtax0ayEv6",(void*)14070820740064816673lu,2575039322u);
	result_r =    printf("%117.51s%0022.90i%106.16s%-26p%--83.182u" ,"\\w/D^i\\5I1Fo_t|jL{1:78",302655923,"#Xcwl?d@KjMTSDV^Qtax0ayEv6",(void*)14070820740064816673lu,2575039322u);
	printf("result_f = %d\n", result_f);
	printf("result_r = %d\n\n",result_r);
	result_f = ft_printf("%-168p%*c%-37.186X%-62.12u%-7.80i" ,(void*)11003863505839120615lu,68,73,2383510380u,2783952512u,-1271710852);
	result_r =    printf("%-168p%*c%-37.186X%-62.12u%-7.80i" ,(void*)11003863505839120615lu,68,73,2383510380u,2783952512u,-1271710852);
	printf("result_f = %d\n", result_f);
	printf("result_r = %d\n\n",result_r);
	result_f = ft_printf("%-58.50i%0141.*%%-13.25X%-36p%--82.48x" ,-325554652,-122,636795324u,(void*)17352689100821810594lu,2670537659u);
	result_r =    printf("%-58.50i%0141.*%%-13.25X%-36p%--82.48x" ,-325554652,-122,636795324u,(void*)17352689100821810594lu,2670537659u);
	printf("result_f = %d\n", result_f);
	printf("result_r = %d\n\n",result_r);
	result_f = ft_printf("%103.165s%-97.173u%-13.119i%-136c%--*p" ,"*\t{~QTa5BqO*g[sBW-\r|S\\",2675659708u,1850142310,-41,107,(void*)17179493381796959667lu);
	result_r =    printf("%103.165s%-97.173u%-13.119i%-136c%--*p" ,"*\t{~QTa5BqO*g[sBW-\r|S\\",2675659708u,1850142310,-41,107,(void*)17179493381796959667lu);
	printf("result_f = %d\n", result_f);
	printf("result_r = %d\n\n",result_r);
	result_f = ft_printf("%-144p%144c" ,(void*)14534807036665133330lu,-61);
	result_r =    printf("%-144p%144c" ,(void*)14534807036665133330lu,-61);
	printf("result_f = %d\n", result_f);
	printf("result_r = %d\n\n",result_r);
	result_f = ft_printf("%-144.75d%--78.X%-190p%00041.*x%-23.70%" ,-265040099,1164608268u,(void*)17615309680892657552lu,106,3685356723u);
	result_r =    printf("%-144.75d%--78.X%-190p%00041.*x%-23.70%" ,-265040099,1164608268u,(void*)17615309680892657552lu,106,3685356723u);
	printf("result_f = %d\n", result_f);
	printf("result_r = %d\n\n",result_r);
	result_f = ft_printf("%-153.61d%0105.36i%-77.70u%-80p" ,1957997024,1534377111,2603846243u,(void*)17500981794874329626lu);
	result_r =    printf("%-153.61d%0105.36i%-77.70u%-80p" ,1957997024,1534377111,2603846243u,(void*)17500981794874329626lu);
	printf("result_f = %d\n", result_f);
	printf("result_r = %d\n\n",result_r);
	result_f = ft_printf("%-197p%03.35d%-101.10%" ,(void*)16358200459980665292lu,1110276224);
	result_r =    printf("%-197p%03.35d%-101.10%" ,(void*)16358200459980665292lu,1110276224);
	printf("result_f = %d\n", result_f);
	printf("result_r = %d\n\n",result_r);
	result_f = ft_printf("%-138.17%%--*p%-14p%---167p%--47.91u" ,-13,(void*)10740891812216954868lu,(void*)2144050129394666231lu,(void*)11614427029332157430lu,2673098069u);
	result_r =    printf("%-138.17%%--*p%-14p%---167p%--47.91u" ,-13,(void*)10740891812216954868lu,(void*)2144050129394666231lu,(void*)11614427029332157430lu,2673098069u);
	printf("result_f = %d\n", result_f);
	printf("result_r = %d\n\n",result_r);
	result_f = ft_printf("%--140p%-92.95s%-102.115i" ,(void*)15758905526233078610lu,NULL,-1446158942);
	result_r =    printf("%--140p%-92.95s%-102.115i" ,(void*)15758905526233078610lu,NULL,-1446158942);
	printf("result_f = %d\n", result_f);
	printf("result_r = %d\n\n",result_r);
	result_f = ft_printf("%--*p%0*.119x%-133.14d%0156.113d%-40c" ,19,(void*)9420508942149040314lu,5,3622177574u,267981691,-545348429,63);
	result_r =    printf("%--*p%0*.119x%-133.14d%0156.113d%-40c" ,19,(void*)9420508942149040314lu,5,3622177574u,267981691,-545348429,63);
	printf("result_f = %d\n", result_f);
	printf("result_r = %d\n\n",result_r);
	result_f = ft_printf("%*p%-114.86%%-27.22d" ,-112,(void*)10233099178825149944lu,500193481);
	result_r =    printf("%*p%-114.86%%-27.22d" ,-112,(void*)10233099178825149944lu,500193481);
	printf("result_f = %d\n", result_f);
	printf("result_r = %d\n\n",result_r);
	result_f = ft_printf("%-164.*%%-108c%-157p%--14p" ,91,-9,(void*)8907860934591409401lu,(void*)15408969479809857993lu);
	result_r =    printf("%-164.*%%-108c%-157p%--14p" ,91,-9,(void*)8907860934591409401lu,(void*)15408969479809857993lu);
	printf("result_f = %d\n", result_f);
	printf("result_r = %d\n\n",result_r);
	result_f = ft_printf("%-170.%%-*.182%%--130.136u%--35p" ,133,2033636620u,(void*)9790833151496085968lu);
	result_r =    printf("%-170.%%-*.182%%--130.136u%--35p" ,133,2033636620u,(void*)9790833151496085968lu);
	printf("result_f = %d\n", result_f);
	printf("result_r = %d\n\n",result_r);
	result_f = ft_printf("%0078.34d%-197.122s%158p" ,204031315,"{Be-'BlT",(void*)12817666508860541147lu);
	result_r =    printf("%0078.34d%-197.122s%158p" ,204031315,"{Be-'BlT",(void*)12817666508860541147lu);
	printf("result_f = %d\n", result_f);
	printf("result_r = %d\n\n",result_r);
	result_f = ft_printf("%--99.174%%-152p%---41.22i" ,(void*)13623062879853167239lu,-83457563);
	result_r =    printf("%--99.174%%-152p%---41.22i" ,(void*)13623062879853167239lu,-83457563);
	printf("result_f = %d\n", result_f);
	printf("result_r = %d\n\n",result_r);
#endif
}

