/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_%.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrunel <mbrunel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 10:29:29 by abourin           #+#    #+#             */
/*   Updated: 2020/10/29 19:02:58 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int main(void)
{
	int t;
	char c;

	c = 'a';
	t = 50;
	printf("%%\n");
	printf("%010%\n");
	printf("%d\n", printf("%%\n")); 
	printf("%d\n", printf("truc\n"));
	printf("percent 1 %012%\n");
	printf("percent 2 %12%\n");
	printf("percent 3 %-12%\n");
	printf("percent 4 %0%\n");
}
