#include <stdio.h>
#include <limits.h>

extern int ft_printf(const char *str, ...);

int main() {
	int i = 0;

#if 0
	i = ft_printf("%d\n", 0);
	ft_printf("1. ret : %d\n", i);
	i = ft_printf("%d\n", INT_MIN);
	ft_printf("2. ret : %d\n", i);
	i = ft_printf("ceci edt un %d, ok ?\n", INT_MIN);
	ft_printf("3. ret : %d\n", i);
	i = ft_printf("%d\n", 2147483647);
	ft_printf("4. ret : %d\n", i);
	i = ft_printf("ceci edt un %d, ok ?\n", 2147483647);
	ft_printf("5. ret : %d\n", i);

	/**		ONLY_PADDING				**/
	i = ft_printf("%10d\n", 0);
	ft_printf("6. ret : %d\n", i);
	i = ft_printf("%0d\n", 0);
	ft_printf("7. ret : %d\n", i);
	i = ft_printf("%10d\n", INT_MIN);
	ft_printf("8. ret : %d\n", i);
	i = ft_printf("%0d\n", INT_MIN);
	ft_printf("9. ret : %d\n", i);
	i = ft_printf("%10d\n", 2147483647);
	ft_printf("10. ret : %d\n", i);
	i = ft_printf("%0d\n", 2147483647);
	ft_printf("11. ret : %d\n", i);
	i = ft_printf("ceci edt un %10d, ok ?\n", INT_MIN);
	ft_printf("12. ret : %d\n", i);
	i = ft_printf("ceci edt un %0d, ok ?\n", INT_MIN);
	ft_printf("13. ret : %d\n", i);
	i = ft_printf("ceci edt un %10d, ok ?\n", 2147483647);
	ft_printf("14. ret : %d\n", i);
	i = ft_printf("ceci edt un %0d, ok ?\n", 2147483647);
	ft_printf("15. ret : %d\n", i);

	/**		PADDING + PRECIdION			**/
	i = ft_printf("%50.30d\n", 0);
	ft_printf("16. ret : %d\n", i);
	i = ft_printf("%8.30d\n", 0);
	ft_printf("17. ret : %d\n", i);
	i = ft_printf("%8.2d\n", 0);
	ft_printf("18. ret : %d\n", i);
	i = ft_printf("%3.2d\n", 0);
	ft_printf("19. ret : %d\n", i);
	i = ft_printf("%2.3d\n", 0);
	ft_printf("20. ret : %d\n", i);
	i = ft_printf("%0.30d\n", 0);
	ft_printf("21. ret : %d\n", i);
	i = ft_printf("%0.0d\n", 0);
	ft_printf("22. ret : %d\n", i);
	i = ft_printf("%50.0d\n", 0);
	ft_printf("23. ret : %d\n", i);
	i = ft_printf("%.30d\n", 0);
	ft_printf("24. ret : %d\n", i);
	i = ft_printf("%50.0d\n", 0);
	ft_printf("25. ret : %d\n", i);

	i = ft_printf("%50.30d\n", INT_MIN);
	ft_printf("26. ret : %d\n", i);
	i = ft_printf("%8.30d\n", INT_MIN);
	ft_printf("27. ret : %d\n", i);
	i = ft_printf("%8.2d\n", INT_MIN);
	ft_printf("28. ret : %d\n", i);
	i = ft_printf("%3.2d\n", INT_MIN);
	ft_printf("29. ret : %d\n", i);
	i = ft_printf("%2.3d\n", INT_MIN);
	ft_printf("30. ret : %d\n", i);
	i = ft_printf("%0.30d\n", INT_MIN);
	ft_printf("31. ret : %d\n", i);
	i = ft_printf("%0.0d\n", INT_MIN);
	ft_printf("32. ret : %d\n", i);
	i = ft_printf("%50.0d\n", INT_MIN);
	ft_printf("33. ret : %d\n", i);
	i = ft_printf("%.30d\n", INT_MIN);
	ft_printf("34. ret : %d\n", i);
	i = ft_printf("%50.0d\n", INT_MIN);
	ft_printf("35. ret : %d\n", i);

	i = ft_printf("%50.30d\n", 2147483647);
	ft_printf("36. ret : %d\n", i);
	i = ft_printf("%8.30d\n", 2147483647);
	ft_printf("37. ret : %d\n", i);
	i = ft_printf("%8.2d\n", 2147483647);
	ft_printf("38. ret : %d\n", i);
	i = ft_printf("%3.2d\n", 2147483647);
	ft_printf("39. ret : %d\n", i);
	i = ft_printf("%2.3d\n", 2147483647);
	ft_printf("40. ret : %d\n", i);
	i = ft_printf("%0.30d\n", 2147483647);
	ft_printf("41. ret : %d\n", i);
	i = ft_printf("%0.0d\n", 2147483647);
	ft_printf("42. ret : %d\n", i);
	i = ft_printf("%50.0d\n", 2147483647);
	ft_printf("43. ret : %d\n", i);
	i = ft_printf("%.30d\n", 2147483647);
	ft_printf("44. ret : %d\n", i);
	i = ft_printf("%50.0d\n", 2147483647);
	ft_printf("45. ret : %d\n", i);
#endif

#if 0
	/**		BASIC TESTS (NO-FLAGS)		**/
	i = ft_printf("%s\n", "");
	ft_printf("ret : %d\n", i);
	i = ft_printf("%s\n", "test");
	ft_printf("ret : %d\n", i);
	i = ft_printf("ceci est un %s, ok ?\n", "test");
	ft_printf("ret : %d\n", i);

	/**		ONLY_PADDING				**/
	i = ft_printf("%10s\n", "");
	ft_printf("ret : %d\n", i);
	//i = ft_printf("%0s\n", "");
	//ft_printf("ret : %d\n", i);
	i = ft_printf("%10s\n", "test");
	ft_printf("ret : %d\n", i);
	//i = ft_printf("%0s\n", "test");
	//ft_printf("ret : %d\n", i);
	i = ft_printf("ceci est un %10s, ok ?\n", "test");
	ft_printf("ret : %d\n", i);
	//i = ft_printf("ceci est un %0s, ok ?\n", "test");
	//ft_printf("ret : %d\n", i);

	/**		PADDING + PRECISION			**/
	i = ft_printf("%10.10s\n", "");
	ft_printf("ret : %d\n", i);
	i = ft_printf("%8.10s\n", "");
	ft_printf("ret : %d\n", i);
	i = ft_printf("%8.2s\n", "");
	ft_printf("ret : %d\n", i);
	i = ft_printf("%3.2s\n", "");
	ft_printf("ret : %d\n", i);
	i = ft_printf("%2.3s\n", "");
	ft_printf("ret : %d\n", i);
	//i = ft_printf("%0.10s\n", "");
	//ft_printf("ret : %d\n", i);
	//i = ft_printf("%0.0s\n", "");
	//ft_printf("ret : %d\n", i);
	i = ft_printf("%10.0s\n", "");
	ft_printf("ret : %d\n", i);
	i = ft_printf("%.10s\n", "");
	ft_printf("ret : %d\n", i);
	i = ft_printf("%10.0s\n", "");
	ft_printf("ret : %d\n", i);

	i = ft_printf("%10.10s\n", "test");
	ft_printf("ret : %d\n", i);
	i = ft_printf("%8.10s\n", "test");
	ft_printf("ret : %d\n", i);
	i = ft_printf("%8.2s\n", "test");
	ft_printf("ret : %d\n", i);
	i = ft_printf("%3.2s\n", "test");
	ft_printf("ret : %d\n", i);
	i = ft_printf("%2.3s\n", "test");
	ft_printf("ret : %d\n", i);
	//i = ft_printf("%0.10s\n", "test");
	//ft_printf("ret : %d\n", i);
	//i = ft_printf("%0.0s\n", "test");
	//ft_printf("ret : %d\n", i);
	i = ft_printf("%10.0s\n", "test");
	ft_printf("ret : %d\n", i);
	i = ft_printf("%.10s\n", "test");
	ft_printf("ret : %d\n", i);
	i = ft_printf("%10.0s\n", "test");
	ft_printf("ret : %d\n", i);
#endif
	/**		BAxIC testx (NO-FLAGx)		**/
	i = ft_printf("%x\n", 0);
	ft_printf("ret : %d\n", i);
	//i = ft_printf("%x\n", -2147483648);
	//ft_printf("ret : %d\n", i);
	//i = ft_printf("ceci ext un %x, ok ?\n", -2147483648);
	//ft_printf("ret : %d\n", i);
	i = ft_printf("%x\n", 2147483647);
	ft_printf("ret : %d\n", i);
	i = ft_printf("ceci ext un %x, ok ?\n", 2147483647);
	ft_printf("ret : %d\n", i);

	/**		ONLY_PAxxING				**/
	i = ft_printf("%10x\n", 0);
	ft_printf("ret : %d\n", i);
	i = ft_printf("%0x\n", 0);
	ft_printf("ret : %d\n", i);
	//i = ft_printf("%10x\n", -2147483648);
	//ft_printf("ret : %d\n", i);
	//i = ft_printf("%0x\n", -2147483648);
	//ft_printf("ret : %d\n", i);
	i = ft_printf("%10x\n", 2147483647);
	ft_printf("ret : %d\n", i);
	i = ft_printf("%0x\n", 2147483647);
	ft_printf("ret : %d\n", i);
	//i = ft_printf("ceci ext un %10x, ok ?\n", -2147483648);
	//ft_printf("ret : %d\n", i);
	//i = ft_printf("ceci ext un %0x, ok ?\n", -2147483648);
	//ft_printf("ret : %d\n", i);
	i = ft_printf("ceci ext un %10x, ok ?\n", 2147483647);
	ft_printf("ret : %d\n", i);
	i = ft_printf("ceci ext un %0x, ok ?\n", 2147483647);
	ft_printf("ret : %d\n", i);

	/**		PAxxING + PRECIxION			**/
	i = ft_printf("%50.30x\n", 0);
	ft_printf("ret : %d\n", i);
	i = ft_printf("%8.30x\n", 0);
	ft_printf("ret : %d\n", i);
	i = ft_printf("%8.2x\n", 0);
	ft_printf("ret : %d\n", i);
	i = ft_printf("%3.2x\n", 0);
	ft_printf("ret : %d\n", i);
	i = ft_printf("%2.3x\n", 0);
	ft_printf("ret : %d\n", i);
	i = ft_printf("%0.30x\n", 0);
	ft_printf("ret : %d\n", i);
	i = ft_printf("%0.0x\n", 0);
	ft_printf("ret : %d\n", i);
	i = ft_printf("%50.0x\n", 0);
	ft_printf("ret : %d\n", i);
	i = ft_printf("%.30x\n", 0);
	ft_printf("ret : %d\n", i);
	i = ft_printf("%50.0x\n", 0);
	ft_printf("ret : %d\n", i);

	//i = ft_printf("%50.30x\n", -2147483648);
	//ft_printf("ret : %d\n", i);
	//i = ft_printf("%8.30x\n", -2147483648);
	//ft_printf("ret : %d\n", i);
	//i = ft_printf("%8.2x\n", -2147483648);
	//ft_printf("ret : %d\n", i);
	//i = ft_printf("%3.2x\n", -2147483648);
	//ft_printf("ret : %d\n", i);
	//i = ft_printf("%2.3x\n", -2147483648);
	//ft_printf("ret : %d\n", i);
	//i = ft_printf("%0.30x\n", -2147483648);
	//ft_printf("ret : %d\n", i);
	//i = ft_printf("%0.0x\n", -2147483648);
	//ft_printf("ret : %d\n", i);
	//i = ft_printf("%50.0x\n", -2147483648);
	//ft_printf("ret : %d\n", i);
	//i = ft_printf("%.30x\n", -2147483648);
	//ft_printf("ret : %d\n", i);
	//i = ft_printf("%50.0x\n", -2147483648);
	//ft_printf("ret : %d\n", i);

	i = ft_printf("%50.30x\n", 2147483647);
	ft_printf("ret : %d\n", i);
	i = ft_printf("%8.30x\n", 2147483647);
	ft_printf("ret : %d\n", i);
	i = ft_printf("%8.2x\n", 2147483647);
	ft_printf("ret : %d\n", i);
	i = ft_printf("%3.2x\n", 2147483647);
	ft_printf("ret : %d\n", i);
	i = ft_printf("%2.3x\n", 2147483647);
	ft_printf("ret : %d\n", i);
	i = ft_printf("%0.30x\n", 2147483647);
	ft_printf("ret : %d\n", i);
	i = ft_printf("%0.0x\n", 2147483647);
	ft_printf("ret : %d\n", i);
	i = ft_printf("%50.0x\n", 2147483647);
	ft_printf("ret : %d\n", i);
	i = ft_printf("%.30x\n", 2147483647);
	ft_printf("ret : %d\n", i);
	i = ft_printf("%50.0x\n", 2147483647);
	ft_printf("ret : %d\n", i);
}
