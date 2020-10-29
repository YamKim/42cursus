/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_cs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrunel <mbrunel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 10:29:29 by abourin           #+#    #+#             */
/*   Updated: 2020/10/29 16:06:16 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int main(void)
{
	int t;
	char c;

	c = 'a';
	t = 50;
	printf("p1 %.4s\n", "cccc");
	printf("p2 %.10s\n", "cccc");
	printf("p3 %.4s\n", NULL);
	printf("p4 %.5s\n", "aaaaa");
	printf("Hello 42 school! %s\n", NULL);
	printf("%c\n", 'a');
	printf("%10c\n", 't');
	printf("%1c\n", 'y');
	printf("%50.2s\n", "Coucou");
	printf("%50.2s\n", NULL);
	printf("%5.0s\n", "Hello");
	printf("%.1s\n", "Test");
	printf("%10s\n", NULL);
	printf("%10s\n", "Ok");
	printf("%d\n", printf("4caractere 1 %12c caractere 2 %12c\n", 'a', 'c'));
	printf("1caractere 1 %c caractere 2 %c\n", 'a', 'c');
	printf("%d\n", printf("1string 1 %s string 2 %s\n", "toto", "bonjour"));
	printf("%d\n", printf("4string 1 %12s string 2 %12s\n", "toto", "bonjour"));
	printf("%d\n", printf("4string 1 %-12s string 2 %-12s\n", "toto", "bonjour"));
	printf("st7 %*.*s\n", 1, 50, "hey");
	printf("st8 %*.*s\n", 0, 0, "coucou");
	printf("st9 %*.*s\n", 0, 50, "hey");
	printf("st10 %*.*s\n", 10, 0, "dsa");
	printf("st11 %*.*s\n", 10, 10, "hello");
	printf("st8 %.*s\n", 0, "coucou");
	printf("st9 %*s\n", 0, "hey");
	printf("st10 %*s\n", 10, "dsa");
	printf("st118 %*s\n", 100, "hello");
	printf("st119 %*s\n", 1000, "hello");
	printf("st120 %*s\n", 10000, "hello");
	printf("st121 %*s\n", 100000, "hello");
	printf("ultimate2 %*d %*s %*x %*X %*i %*u\n", 1, 5000, 1, "hey", 10, 54700, 1, 300, 10000, -55, 1, -60);
	printf("ultimate3 %*.*d %*.*s\n", 1, 50, 5000, 1, 0, "hey");
	printf("neg1 %*s\n", -9, "coucou");
	printf("neg2 %*.*s\n", -9, 4, "coucou");
	printf("neg3 %*s\n", -9, NULL);
	printf("neg4 %*.*s\n", 0, 0, "coucou");
	printf("neg5 %*s\n", -100, "coucou");
	printf("neg6 %*s\n", -156, "coucou");
	printf("neg7 %*.*s\n", -1586, 15, "coucou");
	printf("neg8 %*.*s\n", -1586, 15, "coucou");
	printf("neg9 %*.*s\n", 15856, 155, "coucou");
	printf("neg10 %*.*s\n", -15586, 15, "coucou");
	printf("neg11 %*.*s\n", -15586, 15, "coucou");
	printf("***************%*s%*d**************%*u*************\n", 10, "coucou", 10, 10, -50, 20);
	printf("taaa %100s\n", "hello");
}
