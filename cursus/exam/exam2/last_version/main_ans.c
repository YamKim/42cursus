#include <stdio.h>
#include <limits.h>

int main() {
	int i = 0;

#if 1
	i = printf("%d\n", 0);
	printf("1. ret : %d\n", i);
	i = printf("%d\n", INT_MIN);
	printf("2. ret : %d\n", i);
	i = printf("ceci edt un %d, ok ?\n", INT_MIN);
	printf("3. ret : %d\n", i);
	i = printf("%d\n", 2147483647);
	printf("4. ret : %d\n", i);
	i = printf("ceci edt un %d, ok ?\n", 2147483647);
	printf("5. ret : %d\n", i);
	/**		ONLY_PADDING				**/
	i = printf("%10d\n", 0);
	printf("6. ret : %d\n", i);
	i = printf("%0d\n", 0);
	printf("7. ret : %d\n", i);
	i = printf("%10d\n", INT_MIN);
	printf("8. ret : %d\n", i);
	i = printf("%0d\n", INT_MIN);
	printf("9. ret : %d\n", i);
	i = printf("%10d\n", 2147483647);
	printf("10. ret : %d\n", i);
	i = printf("%0d\n", 2147483647);
	printf("11. ret : %d\n", i);
	i = printf("ceci edt un %10d, ok ?\n", INT_MIN);
	printf("12. ret : %d\n", i);
	i = printf("ceci edt un %0d, ok ?\n", INT_MIN);
	printf("13. ret : %d\n", i);
	i = printf("ceci edt un %10d, ok ?\n", 2147483647);
	printf("14. ret : %d\n", i);
	i = printf("ceci edt un %0d, ok ?\n", 2147483647);
	printf("15. ret : %d\n", i);

	/**		PADDING + PRECIdION			**/
	i = printf("%50.30d\n", 0);
	printf("16. ret : %d\n", i);
	i = printf("%8.30d\n", 0);
	printf("17. ret : %d\n", i);
	i = printf("%8.2d\n", 0);
	printf("18. ret : %d\n", i);
	i = printf("%3.2d\n", 0);
	printf("19. ret : %d\n", i);
	i = printf("%2.3d\n", 0);
	printf("20. ret : %d\n", i);
	i = printf("%0.30d\n", 0);
	printf("21. ret : %d\n", i);
	i = printf("%0.0d\n", 0);
	printf("22. ret : %d\n", i);
	i = printf("%50.0d\n", 0);
	printf("23. ret : %d\n", i);
	i = printf("%.30d\n", 0);
	printf("24. ret : %d\n", i);
	i = printf("%50.0d\n", 0);
	printf("25. ret : %d\n", i);

	i = printf("%50.30d\n", INT_MIN);
	printf("26. ret : %d\n", i);
	i = printf("%8.30d\n", INT_MIN);
	printf("27. ret : %d\n", i);
	i = printf("%8.2d\n", INT_MIN);
	printf("28. ret : %d\n", i);
	i = printf("%3.2d\n", INT_MIN);
	printf("29. ret : %d\n", i);
	i = printf("%2.3d\n", INT_MIN);
	printf("30. ret : %d\n", i);
	i = printf("%0.30d\n", INT_MIN);
	printf("31. ret : %d\n", i);
	i = printf("%0.0d\n", INT_MIN);
	printf("32. ret : %d\n", i);
	i = printf("%50.0d\n", INT_MIN);
	printf("33. ret : %d\n", i);
	i = printf("%.30d\n", INT_MIN);
	printf("34. ret : %d\n", i);
	i = printf("%50.0d\n", INT_MIN);
	printf("35. ret : %d\n", i);

	i = printf("%50.30d\n", 2147483647);
	printf("36. ret : %d\n", i);
	i = printf("%8.30d\n", 2147483647);
	printf("37. ret : %d\n", i);
	i = printf("%8.2d\n", 2147483647);
	printf("38. ret : %d\n", i);
	i = printf("%3.2d\n", 2147483647);
	printf("39. ret : %d\n", i);
	i = printf("%2.3d\n", 2147483647);
	printf("40. ret : %d\n", i);
	i = printf("%0.30d\n", 2147483647);
	printf("41. ret : %d\n", i);
	i = printf("%0.0d\n", 2147483647);
	printf("42. ret : %d\n", i);
	i = printf("%50.0d\n", 2147483647);
	printf("43. ret : %d\n", i);
	i = printf("%.30d\n", 2147483647);
	printf("44. ret : %d\n", i);
	i = printf("%50.0d\n", 2147483647);
	printf("45. ret : %d\n", i);
#endif

#if 0
	/**		BASIC TESTS (NO-FLAGS)		**/
	i = printf("%s\n", "");
	printf("ret : %d\n", i);
	i = printf("%s\n", "test");
	printf("ret : %d\n", i);
	i = printf("ceci est un %s, ok ?\n", "test");
	printf("ret : %d\n", i);

	/**		ONLY_PADDING				**/
	i = printf("%10s\n", "");
	printf("ret : %d\n", i);
	//i = printf("%0s\n", "");
	//printf("ret : %d\n", i);
	i = printf("%10s\n", "test");
	printf("ret : %d\n", i);
	//i = printf("%0s\n", "test");
	//printf("ret : %d\n", i);
	i = printf("ceci est un %10s, ok ?\n", "test");
	printf("ret : %d\n", i);
	//i = printf("ceci est un %0s, ok ?\n", "test");
	//printf("ret : %d\n", i);

	/**		PADDING + PRECISION			**/
	i = printf("%10.10s\n", "");
	printf("ret : %d\n", i);
	i = printf("%8.10s\n", "");
	printf("ret : %d\n", i);
	i = printf("%8.2s\n", "");
	printf("ret : %d\n", i);
	i = printf("%3.2s\n", "");
	printf("ret : %d\n", i);
	i = printf("%2.3s\n", "");
	printf("ret : %d\n", i);
	//i = printf("%0.10s\n", "");
	//printf("ret : %d\n", i);
	//i = printf("%0.0s\n", "");
	//printf("ret : %d\n", i);
	i = printf("%10.0s\n", "");
	printf("ret : %d\n", i);
	i = printf("%.10s\n", "");
	printf("ret : %d\n", i);
	i = printf("%10.0s\n", "");
	printf("ret : %d\n", i);

	i = printf("%10.10s\n", "test");
	printf("ret : %d\n", i);
	i = printf("%8.10s\n", "test");
	printf("ret : %d\n", i);
	i = printf("%8.2s\n", "test");
	printf("ret : %d\n", i);
	i = printf("%3.2s\n", "test");
	printf("ret : %d\n", i);
	i = printf("%2.3s\n", "test");
	printf("ret : %d\n", i);
	//i = printf("%0.10s\n", "test");
	//printf("ret : %d\n", i);
	//i = printf("%0.0s\n", "test");
	//printf("ret : %d\n", i);
	i = printf("%10.0s\n", "test");
	printf("ret : %d\n", i);
	i = printf("%.10s\n", "test");
	printf("ret : %d\n", i);
	i = printf("%10.0s\n", "test");
	printf("ret : %d\n", i);
#endif
#if 0
	/**		BAxIC testx (NO-FLAGx)		**/
	i = printf("%x\n", 0);
	printf("ret : %d\n", i);
	//i = printf("%x\n", -2147483648);
	//printf("ret : %d\n", i);
	//i = printf("ceci ext un %x, ok ?\n", -2147483648);
	//printf("ret : %d\n", i);
	i = printf("%x\n", 2147483647);
	printf("ret : %d\n", i);
	i = printf("ceci ext un %x, ok ?\n", 2147483647);
	printf("ret : %d\n", i);

	/**		ONLY_PAxxING				**/
	i = printf("%10x\n", 0);
	printf("ret : %d\n", i);
	i = printf("%0x\n", 0);
	printf("ret : %d\n", i);
	//i = printf("%10x\n", -2147483648);
	//printf("ret : %d\n", i);
	//i = printf("%0x\n", -2147483648);
	//printf("ret : %d\n", i);
	i = printf("%10x\n", 2147483647);
	printf("ret : %d\n", i);
	i = printf("%0x\n", 2147483647);
	printf("ret : %d\n", i);
	//i = printf("ceci ext un %10x, ok ?\n", -2147483648);
	//printf("ret : %d\n", i);
	//i = printf("ceci ext un %0x, ok ?\n", -2147483648);
	//printf("ret : %d\n", i);
	i = printf("ceci ext un %10x, ok ?\n", 2147483647);
	printf("ret : %d\n", i);
	i = printf("ceci ext un %0x, ok ?\n", 2147483647);
	printf("ret : %d\n", i);

	/**		PAxxING + PRECIxION			**/
	i = printf("%50.30x\n", 0);
	printf("ret : %d\n", i);
	i = printf("%8.30x\n", 0);
	printf("ret : %d\n", i);
	i = printf("%8.2x\n", 0);
	printf("ret : %d\n", i);
	i = printf("%3.2x\n", 0);
	printf("ret : %d\n", i);
	i = printf("%2.3x\n", 0);
	printf("ret : %d\n", i);
	i = printf("%0.30x\n", 0);
	printf("ret : %d\n", i);
	i = printf("%0.0x\n", 0);
	printf("ret : %d\n", i);
	i = printf("%50.0x\n", 0);
	printf("ret : %d\n", i);
	i = printf("%.30x\n", 0);
	printf("ret : %d\n", i);
	i = printf("%50.0x\n", 0);
	printf("ret : %d\n", i);

	//i = printf("%50.30x\n", -2147483648);
	//printf("ret : %d\n", i);
	//i = printf("%8.30x\n", -2147483648);
	//printf("ret : %d\n", i);
	//i = printf("%8.2x\n", -2147483648);
	//printf("ret : %d\n", i);
	//i = printf("%3.2x\n", -2147483648);
	//printf("ret : %d\n", i);
	//i = printf("%2.3x\n", -2147483648);
	//printf("ret : %d\n", i);
	//i = printf("%0.30x\n", -2147483648);
	//printf("ret : %d\n", i);
	//i = printf("%0.0x\n", -2147483648);
	//printf("ret : %d\n", i);
	//i = printf("%50.0x\n", -2147483648);
	//printf("ret : %d\n", i);
	//i = printf("%.30x\n", -2147483648);
	//printf("ret : %d\n", i);
	//i = printf("%50.0x\n", -2147483648);
	//printf("ret : %d\n", i);

	i = printf("%50.30x\n", 2147483647);
	printf("ret : %d\n", i);
	i = printf("%8.30x\n", 2147483647);
	printf("ret : %d\n", i);
	i = printf("%8.2x\n", 2147483647);
	printf("ret : %d\n", i);
	i = printf("%3.2x\n", 2147483647);
	printf("ret : %d\n", i);
	i = printf("%2.3x\n", 2147483647);
	printf("ret : %d\n", i);
	i = printf("%0.30x\n", 2147483647);
	printf("ret : %d\n", i);
	i = printf("%0.0x\n", 2147483647);
	printf("ret : %d\n", i);
	i = printf("%50.0x\n", 2147483647);
	printf("ret : %d\n", i);
	i = printf("%.30x\n", 2147483647);
	printf("ret : %d\n", i);
	i = printf("%50.0x\n", 2147483647);
	printf("ret : %d\n", i);
#endif
}
