/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_csp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrunel <mbrunel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 10:29:29 by abourin           #+#    #+#             */
/*   Updated: 2020/11/05 12:16:30 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../../../ft_printf/incs/ft_printf.h"

int main(void)
{
	int t;
	char c;

	c = 'a';
	t = 50;
	ft_printf("r = [%-4.c]\n", c);
	ft_printf("r = [%-4c]\n", c);
	ft_printf("p1 %-4.s\n", "cccc");
	ft_printf("p1 %.4s\n", "cccc");
	ft_printf("p2 %.10s\n", "cccc");
	ft_printf("p3 %.4s\n", NULL);
	ft_printf("p4 %.5s\n", "aaaaa");
	ft_printf("Hello 42 school! %s\n", NULL);
	ft_printf("%p\n", NULL);
	ft_printf("%15p\n", NULL);
	ft_printf("%-15p\n", NULL);
	ft_printf("%c\n", 'a');
	ft_printf("%10c\n", 't');
	ft_printf("%1c\n", 'y');
	ft_printf("%50.2s\n", "Coucou");
	ft_printf("%50.2s\n", NULL);
	ft_printf("%5.0s\n", "Hello");
	ft_printf("%.1s\n", "Test");
	ft_printf("%10s\n", NULL);
	ft_printf("%10s\n", "Ok");
	ft_printf("%d\n", ft_printf("4caractere 1 %12c caractere 2 %12c\n", 'a', 'c'));
	ft_printf("1caractere 1 %c caractere 2 %c\n", 'a', 'c');
	ft_printf("04 Test de chiffre sans h : %d, et %d\n", 432767, -432767);
	ft_printf("%d\n", ft_printf("1string 1 %s string 2 %s\n", "toto", "bonjour"));
	ft_printf("%d\n", ft_printf("4string 1 %12s string 2 %12s\n", "toto", "bonjour"));
	ft_printf("%d\n", ft_printf("4string 1 %-12s string 2 %-12s\n", "toto", "bonjour"));
	ft_printf("st7 %*.*s\n", 1, 50, "hey");
	ft_printf("st8 %*.*s\n", 0, 0, "coucou");
	ft_printf("st9 %*.*s\n", 0, 50, "hey");
	ft_printf("st10 %*.*s\n", 10, 0, "dsa");
	ft_printf("st11 %*.*s\n", 10, 10, "hello");
	ft_printf("st8 %.*s\n", 0, "coucou");
	ft_printf("st9 %*s\n", 0, "hey");
	ft_printf("st10 %*s\n", 10, "dsa");
	ft_printf("st118 %*s\n", 100, "hello");
	ft_printf("st119 %*s\n", 1000, "hello");
	ft_printf("st120 %*s\n", 10000, "hello");
	ft_printf("st121 %*s\n", 100000, "hello");
	ft_printf("ultimate2 %*d %*s %*x %*X %*i %*u\n", 1, 5000, 1, "hey", 10, 54700, 1, 300, 10000, -55, 1, -60);
	ft_printf("ultimate3 %*.*d %*.*s\n", 1, 50, 5000, 1, 0, "hey");
	ft_printf("neg1 %*s\n", -9, "coucou");
	ft_printf("neg2 %*.*s\n", -9, 4, "coucou");
	ft_printf("neg3 %*s\n", -9, NULL);
	ft_printf("neg4 %*.*s\n", 0, 0, "coucou");
	ft_printf("neg5 %*s\n", -100, "coucou");
	ft_printf("neg6 %*s\n", -156, "coucou");
	ft_printf("neg7 %*.*s\n", -1586, 15, "coucou");
	ft_printf("neg8 %*.*s\n", -1586, 15, "coucou");
	ft_printf("neg9 %*.*s\n", 15856, 155, "coucou");
	ft_printf("neg10 %*.*s\n", -15586, 15, "coucou");
	ft_printf("neg11 %*.*s\n", -15586, 15, "coucou");
	ft_printf("***************%*s%*d**************%*u*************\n", 10, "coucou", 10, 10, -50, 20);
	ft_printf("taaa %100s\n", "hello");
#if 0
#endif
}
