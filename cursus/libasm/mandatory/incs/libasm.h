/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <yekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 12:14:48 by yekim             #+#    #+#             */
/*   Updated: 2021/01/21 12:22:26 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _LIBASM_H
# define _LIBASM_H

# include <stdio.h>
# include <unistd.h>
# include <errno.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>

size_t	ft_strlen(const char *s);

char	*ft_strcpy(
		char *dst,
		const char *src);

int		ft_strcmp(
		const char *s1,
		const char *s2);

ssize_t	ft_write(
		int fildes,
		const void *buf,
		size_t nbyte);

ssize_t ft_read(
		int fildes,
		void *buf,
		size_t nbyte);

char	*ft_strdup(const char *s1);

#endif
