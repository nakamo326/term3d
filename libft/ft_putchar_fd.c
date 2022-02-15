/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: totaisei <totaisei@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 01:16:12 by totaisei          #+#    #+#             */
/*   Updated: 2022/02/15 20:06:19 by totaisei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	char	c1;
	char	c2;

	if ((unsigned char)c <= 127)
		write(fd, &c, 1);
	else
	{
		c1 = ((unsigned char)c >> 6) | 0b11000000;
		c2 = ((unsigned char)c & 0b00111111) | 0b10000000;
		write(fd, &c1, 1);
		write(fd, &c2, 1);
	}
}
