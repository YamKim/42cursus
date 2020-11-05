/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_percent.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrunel <mbrunel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 10:29:29 by abourin           #+#    #+#             */
/*   Updated: 2020/11/05 12:24:46 by yekim            ###   ########.fr       */
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
	ft_printf("%%\n");
	ft_printf("%010%\n");
	ft_printf("%d\n", ft_printf("%%\n")); 
	ft_printf("%d\n", ft_printf("truc\n"));
	ft_printf("percent 1 %012%\n");
	ft_printf("percent 2 %12%\n");
	ft_printf("percent 3 %-12%\n");
	ft_printf("percent 4 %0%\n");
}
