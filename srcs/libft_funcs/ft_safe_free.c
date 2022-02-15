/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_safe_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: totaisei <totaisei@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 18:58:20 by totaisei          #+#    #+#             */
/*   Updated: 2022/02/16 00:22:20 by totaisei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibft.h"

void	ft_safe_free_char(char **target)
{
	free(*target);
	*target = NULL;
}

void	ft_safe_free_split(char ***target)
{
	size_t	index;

	index = 0;
	if (!*target)
		return ;
	while ((*target)[index])
	{
		free((*target)[index]);
		(*target)[index] = NULL;
		index++;
	}
	free(*target);
	*target = NULL;
}
