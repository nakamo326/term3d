/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: totaisei <totaisei@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 16:48:37 by totaisei          #+#    #+#             */
/*   Updated: 2022/02/15 20:04:48 by totaisei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	remove_c(char *src, char c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		if (src[i] == c)
			src[i] = '\0';
		i++;
	}
}

static size_t	count_separated(char *src, size_t len)
{
	size_t	i;
	size_t	res;

	i = 0;
	res = 0;
	while (i < len)
	{
		if (src[i] != '\0')
		{
			i += ft_strlen(&src[i]);
			res++;
		}
		i++;
	}
	return (res);
}

static t_bool	set_separated(char *src, size_t len, char **result)
{
	size_t	i;
	size_t	parent_count;

	i = 0;
	parent_count = 0;
	while (i < len)
	{
		if (src[i] != '\0')
		{
			result[parent_count] = ft_strdup(&src[i]);
			if (!result[parent_count])
			{
				while (parent_count > 0)
					free(result[--parent_count]);
				return (FALSE);
			}
			i += ft_strlen(&src[i]);
			parent_count++;
		}
		i++;
	}
	return (TRUE);
}

char	**ft_split(char const *s, char c)
{
	char	*src;
	size_t	len;
	size_t	sep_count;
	char	**res;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	src = ft_strdup(s);
	if (!src)
		return (NULL);
	sep_count = 0;
	remove_c(src, c, len);
	sep_count = count_separated(src, len);
	res = malloc(sizeof(char *) * (sep_count + 1));
	if (!res)
		return (NULL);
	res[sep_count] = NULL;
	if (!set_separated(src, len, res))
	{
		free(res);
		res = NULL;
	}
	free(src);
	return (res);
}
