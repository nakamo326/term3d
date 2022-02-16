/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_new_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: totaisei <totaisei@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 14:11:52 by totaisei          #+#    #+#             */
/*   Updated: 2022/02/16 00:19:48 by totaisei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibft.h"

char	*ft_find_new_line(const char *s, size_t len)
{
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] != '\n')
	{
		if (!(i < len))
			return (NULL);
		i++;
	}
	return ((char *)&s[i]);
}
