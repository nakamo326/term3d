/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: totaisei <totaisei@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 12:53:58 by totaisei          #+#    #+#             */
/*   Updated: 2022/02/15 19:32:17 by totaisei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*make_emptyline(void)
{
	char	*res;

	res = malloc(sizeof(char));
	if (!res)
		return (NULL);
	*res = '\0';
	return (res);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*res;
	size_t			char_count;
	size_t			i;

	if (!s)
		return (NULL);
	if (len == 0 || start > ft_strlen(s))
		return (make_emptyline());
	char_count = len;
	if (!(ft_strlen(&s[start]) > len))
		char_count = ft_strlen(&s[start]);
	res = malloc(sizeof(char) * (char_count + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		res[i] = s[start + i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
