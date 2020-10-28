/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newDmain.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrunel <mbrunel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 10:29:29 by abourin           #+#    #+#             */
/*   Updated: 2020/10/28 17:05:45 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int main(void)
{
	int t;
	char c;

	c = 'a';
	t = 50;
	printf("pp %.50d\n", 10000);
	printf("p5 %.3d\n", 100);
	printf("p6 %.0d\n", 100);
	printf("p7 %.4d\n", 100);
	printf("p8 %.10d\n", 100);
	printf("p9 %.50d\n", 100);
	printf("p10 %.1d\n", 100);
	printf("p11 %.3d\n", 100);
	printf("p12 %.0d\n", 0);
	printf("p13 %.3i\n", 100);
	printf("p14 %.0i\n", 100);
	printf("p15 %.4i\n", 100);
	printf("p16 %.10i\n", 100);
	printf("p17 %.50i\n", 100);
	printf("p18 %.1i\n", 100);
	printf("%d\n", 2147483647);
	printf("%40.50d\n", 50);
    printf("%d\n", -589);
    printf("%-4d\n", -2464);
    printf("%.5d\n", -2372);
    printf("ret = %d\n", printf("%%p::[%010d]\n", -8473));
    printf("ret = %d\n", printf("%%p::[%10d]\n", -8473));
    printf("ret = %d\n", printf("%%p::[%.5d]\n", -8473));
    printf("ret = %d\n", printf("%%p::[%01.1d]\n", -8473));
    printf("ret = %d\n", printf("%%p::[%010.1d]\n", -8473));
    printf("ret = %d\n", printf("%%p::[%01.50d]\n", -8473));
    printf("ret = %d\n", printf("%%p::[%1.50d]\n", -8473));
    printf("ret = %d\n", printf("%%p::[%0100.50d]\n", -8473));
    printf("ret = %d\n", printf("%%p::[%010d]\n", 8473));
    printf("ret = %d\n", printf("%%p::[%10d]\n", 8473));
    printf("ret = %d\n", printf("%%p::[%.5d]\n", 8473));
    printf("ret = %d\n", printf("%%p::[%01.1d]\n", 8473));
    printf("ret = %d\n", printf("%%p::[%010.1d]\n", 8473));
    printf("ret = %d\n", printf("%%p::[%01.50d]\n", 8473));
    printf("ret = %d\n", printf("%%p::[%1.50d]\n", 8473));
    printf("ret = %d\n", printf("%%p::[%0100.50d]\n", 8473));
	printf("%d\n", printf("1chiffre 1 %d chiffre 2 %d\n", 42, -42));
	printf("%d\n", printf("4chiffre 1 %-12d chiffre 2 %-12d\n", 42, -42));
	printf("t1 %050d\n", 10);
	printf("t2 %-50d\n", 10);
	printf("t3 %50.0d\n", 10);
	printf("t4 %50.50d\n", 10);
	printf("t5 %50.10d\n", 10);
	printf("t6 %*.*d\n", 50,  5, 10);
	printf("t7 %1.50d\n", -10);
	printf("t8 %1.50d\n", 10);
	printf("t9 %2.2d\n", 10);
	printf("t10 %2.2d\n", -10);
	printf("t12 %.0d\n", 0);
	printf("t13 %01d\n", -20);
	printf("t14 %10d\n", 1000);
	printf("%d\n", printf("5chiffre 1 %0d chiffre 2 %0d\n", 42, -42));
	printf("%d\n", printf("6chiffre 1 %012d chiffre 2 %012d\n", 42, -42));
	printf("%d\n", printf("8chiffre 1 %*d chiffre 2 %*d\n", 42, 6, 6, 6));
	printf("%d\n", printf("15chiffre 1 %.d chiffre 2 %.d\n", 42, -42));
	printf("%d\n", printf("%-.12i\n", -20000000));
	printf("%d\n", printf("truc\n"));
	printf("04 Test de chiffre sans h : %d, et %d\n", 432767, -432767);
	printf("31 This is an int : %.0d\n", 0);
	printf("32 This is an int : %0d\n", 0);
	printf("%d\n", t);
	printf("%d\n", t);
	printf("%d\n", t);
	printf("%d\n", t);
	printf("%d\n", t);
	printf("%d\n", t);
	printf("%d\n", t);
	printf("%d\n", t);
	printf("st1 %*.*d\n", 10, 10, 50);
	printf("st2 %*.*d\n", 1, 50, 50);
	printf("st3 %*.*d\n", 0, 0, 50);
	printf("st4 %*.*d\n", 0, 50, 50);
	printf("st5 %*.*d\n", 10, 0, 50);
	printf("st6 %*.*d\n", 10, 10, 50);
	printf("st12 %*d\n", 10, 50);
	printf("st13 %*d\n", 0, 0);
	printf("st14 %.*d\n", 0, 0);
	printf("st15 %*d\n", 50, 5);
	printf("st16 %0.*d\n", 50, 5);
	printf("st17 %0.*d\n", 0, 0);
	printf("st118 %*d\n", 100, 0);
	printf("st119 %*d\n", 1000, 10);
	printf("st120 %*d\n", 10000, 467);
	printf("st121 %*d\n", 100000, -589);
	printf("ultimate1 %*d        %*i\n", 500, 0, 10, 10);
	printf("neg1 %*d\n", -9, 150);
	printf("neg2 %*.*d\n", -9, 4, 1555);
	printf("neg3 %*d\n", -9, -255);
	printf("neg4 %*.*d\n", 0, 0, -30);
	printf("neg5 %*d\n", -100, -589);
	printf("neg6 %*d\n", -156, 15555);
	printf("neg7 %*.*d\n", -1586, 15, 0);
	printf("neg8 %*.*d\n", -1586, 15, 300);
	printf("neg9 %*.*d\n", 15856, 155, -3000);
	printf("neg10 %*.*d\n", -15586, 15, 150);
	printf("neg11 %*.*d\n", -15586, 15, 0);
}
