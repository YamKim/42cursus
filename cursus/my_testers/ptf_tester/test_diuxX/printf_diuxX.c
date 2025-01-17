/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_diuxX.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrunel <mbrunel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 10:29:29 by abourin           #+#    #+#             */
/*   Updated: 2020/11/05 12:28:59 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../ft_printf/incs/ft_printf.h"
#include <stdio.h>

int main(void)
{
	int d;
	(void)d;
#if 0
	d = 12;
	printf("lover |%0*.d|\n", 4, d);
	printf("lover |%0*.*d|\n", 4, 0, d);
	printf("lover |%0*.0d|\n", 4, d);
#endif
	d = -12;
	printf("lover |%04.d|\n", d);
	printf("lover |%04.*d|\n", 0, d);
	printf("lover |%04.0d|\n", d);
	printf("lover |%+0*.0d|\n", 4, d);
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
	printf("p19 %.3x\n", 100);
	printf("p20 %.0x\n", 0);
	printf("p21 %.3x\n", 100);
	printf("p22 %.0x\n", 100);
	printf("p23 %.4x\n", 100);
	printf("p24 %.10x\n", 100);
	printf("p25 %.50x\n", 100);
	printf("p26 %.1x\n", 100);
	printf("p27 %.3x\n", 100);
	printf("p28 %.0x\n", 0);
	printf("p29 %.3u\n", 100);
	printf("p30 %.0u\n", 100);
	printf("p31 %.4u\n", 100);
	printf("p32 %.10u\n", 100);
	printf("p33 %.50u\n", 100);
	printf("p34 %.1u\n", 100);
	printf("p35 %.3u\n", 100);
	printf("p36 %.0u\n", 0);
	printf("%d\n", 2147483647);
	printf("%x\n", 2147483647);
	printf("%X\n", 2147483647);
	printf("%x\n", 0);
	printf("%010x\n", 0);
	printf("%010x\n", 20);
	printf("%010x\n", -20);
	printf("%10x\n", 20);
	printf("%10.2x\n", -20);
	printf("%-10x\n", 50);
	printf("%-15x\n", 0);
	printf("%.1x\n", 500);
	printf("%*.*x\n", 50, 10, 2);
	printf("%x\n", -1);
	printf("%40.50d\n", 50);
    printf("%d\n", -589);
    printf("%-4d\n", -2464);
    printf("%.5d\n", -2372);
    printf("ret = %d\n", printf("%%p::[%010d]\n", -8473));
    printf("ret = %d\n", printf("%%p::[%10d]\n", -8473));
    printf("ret = %d\n", printf("%%p::[%.5d]\n", -8473));
    printf("ret = %d\n", printf("%%p::[%1.50d]\n", -8473));
    printf("ret = %d\n", printf("%%p::[%010d]\n", 8473));
    printf("ret = %d\n", printf("%%p::[%10d]\n", 8473));
    printf("ret = %d\n", printf("%%p::[%.5d]\n", 8473));
    printf("ret = %d\n", printf("%%p::[%01.1d]\n", -8473));
    printf("ret = %d\n", printf("%%p::[%010.1d]\n", -8473));
    printf("ret = %d\n", printf("%%p::[%01.50d]\n", -8473));
    printf("ret = %d\n", printf("%%p::[%0100.50d]\n", -8473));
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
	printf("%d\n", printf("4caractere 1 %12c caractere 2 %12c\n", 'a', 'c'));
	printf("1caractere 1 %c caractere 2 %c\n", 'a', 'c');
	printf("%d\n", printf("1hexa-maj 1 %X hexa-maj 2 %X\n", 42, -42));
	printf("%d\n", printf("4hexa-maj 1 %12X hexa-maj 2 %int12X\n", 42, -42));
	printf("%d\n", printf("4hexa-maj 1 %-12X hexa-maj 2 %-12X\n", 42, -42));
	printf("%d\n", printf("5hexa-maj 1 %0X hexa-maj 2 %0X\n", 42, -42));
	printf("%d\n", printf("6hexa-maj 1 %012X hexa-maj 2 %012X\n", 42, -42));
	printf("%d\n", printf("8hexa-maj 1 %*X hexa-maj 2 %*X\n", 42, 6, 6, 6));
	printf("%d\n", printf("1unsigned 1 %u unsigned 2 %u\n", 42, -42));
	printf("%d\n", printf("4unsigned 1 %12u unsigned 2 %12u\n", 42, -42));
	printf("%d\n", printf("4unsigned 1 %-12u unsigned 2 %-12u\n", 42, -42));
	printf("%d\n", printf("5unsigned 1 %0u unsigned 2 %0u\n", 42, -42));
	printf("%d\n", printf("6unsigned 1 %012u unsigned 2 %012u\n", 42, -42));
	printf("%d\n", printf("8unsigned 1 %*u unsigned 2 %*u\n", 42, 6, 6, 6));
	printf("%d\n", printf("15unsigned 1 %.u unsigned 2 %.u\n", 42, -42));
	printf("%d\n", printf("%%\n")); 
	printf("%d\n", printf("%-.12u\n", -20000000));
	printf("%d\n", printf("%-.12i\n", -20000000));
	printf("%d\n", printf("truc\n"));
	printf("04 Test de chiffre sans h : %d, et %d\n", 432767, -432767);
	printf("31 This is an int : %.0d\n", 0);
	printf("32 This is an int : %0d\n", 0);
	int t = 50;
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
	printf("ultimate2 %*d %*s %*x %*X %*i %*u\n", 1, 5000, 1, "hey", 10, 54700, 1, 300, 10000, -55, 1, -60);
	printf("ultimate4 %*.*x %*.*X\n", 1, 50, 5000, 1, 0, 10);
	printf("ultimate5 %*.*u\n", 1, 50, 5000);
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
