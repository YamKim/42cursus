#include "ft_printf.h"

#include <stdio.h>
#include <locale.h>
#include <wchar.h>

void	u_test();
void	d_test();

int main(void)
{
	int result_f;
	int result_r;
	char *str = "123";
	(void)str;
	(void)result_r;
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
//Hexadecimal lower - zero precision zero value
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
#if 0


/* -----------------------------------------------------------------------------
** 						%X HEXADECIMAL UPPERS TESTS (MANDATORY)
** ---------------------------------------------------------------------------*/
//Hex\nadecimal uppers - no modifers
	printf("this %X number", 17);
	printf("this %X number", 0);
	printf("%X", 3);
	printf("%X", 4294967295u);
//Hex\nadecimal uppers with field width
	printf("%7X", 33);
	printf("%3X", 0);
	printf("%5X", 52625);
	printf("%2X", 94827);
	printf("%-7X", 33);
	printf("%-3X", 0);
	printf("%-5X", 52625);
	printf("%-4X", 9648627);
//Hex\nadecimal uppers with precision
	printf("%.5X", 21);
	printf("%.3X", 0);
	printf("%.4X", 5263);
	printf("%.3X", 938862);
//Hexadecimal uppers with zero field width padding
//	printf("%05X", 43);
//	printf("%03X", 0);
//	printf("%03X", 698334);
//Hexadecimal uppers with field width and precision
	printf("%8.5X", 34);
	printf("%8.5X", 0);
	printf("%8.3X", 8375);
	printf("%2.7X", 3267);
	printf("%3.3X", 6983);
//Hexadecimal uppers with field width and precision, left-justified
	printf("%-8.5X", 34);
	printf("%-8.5X", 0);
	printf("%-8.3X", 8375);
	printf("%-2.7X", 3267);
	printf("%-3.3X", 6983);
//Hexadecimal uppers with field width and precision with zeropadding
//	printf("%08.5X", 34);
//	printf("%08.5X", 0);
//	printf("%08.3X", 8375);
//	printf("%02.7X", 3267);
//	printf("%03.3X", 6983);
//Hexadecimal uppers with field width and precision, left-justified with zeropadding
//	printf("%0-8.5X", 34);
//	printf("%0-8.5X", 0);
//	printf("%0-8.3X", 8375);
//	printf("%0-2.7X", 3267);
//	printf("%0-3.3X", 6983);
//Hexadecimal uppers - zero precision zero value
	printf("%.0X", 0);
	printf("%.X", 0);
	printf("%5.0X", 0);
	printf("%5.X", 0);
	printf("%-5.0X", 0);
	printf("%-5.X", 0);
#endif

//	u_test();
//	d_test();
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
#if 0
	char *strNULL = "\0";
	result_f = ft_printf("f = [%p]\n", strNULL);
	result_r =    printf("r = [%p]\n", strNULL);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("f = [%5p]\n", str);
	result_r =    printf("r = [%5p]\n", str);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("f = [%-20p]\n", str);
	result_r =    printf("r = [%-20p]\n", str);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("f = [%-20p]\n", (void *)0);
	result_r =    printf("r = [%-20p]\n", (void *)0);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
#endif
#if 0
	(void)str;
	result_f = ft_printf("f = [%-20s]\n", "asdfsadf");
	result_r =    printf("r = [%-20s]\n", "asdfsadf");
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("f = [%-*.*s]\n", 20, 3, "asdfsadf");
	result_r =    printf("r = [%-*.*s]\n", 20, 3, "asdfsadf");
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("f = [%*.3s]\n", 20, "asdfsadf");
	result_r =    printf("r = [%*.3s]\n", 20, "asdfsadf");
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("f = [%c]\n", '\0');
	result_r =    printf("r = [%c]\n", '\0');
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("f = [%-5c]\n", 'a');
	result_r =    printf("r = [%-5c]\n", 'a');
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	(void)str;
	//char *strNull = NULL;
	result_f = ft_printf("f = [%-.5s]\n", "\0");
	result_r =    printf("r = [%-.5s]\n", "\0");
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("f = [%-.5s]\n", "\0");
	result_r =    printf("r = [%-.5s]\n", "\0");
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
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

}

void d_print(void) {
	int result_f;
	int result_r;
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
	result_f = ft_printf("f = [%0+10.5d]\n", -123);
	result_r =    printf("r = [%0+10d]\n", -123);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
}
