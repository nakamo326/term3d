/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: totaisei <totaisei@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 14:15:53 by totaisei          #+#    #+#             */
/*   Updated: 2022/02/15 19:56:09 by totaisei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	free_all(char *storage, char *buf, char *line)
{
	free(buf);
	free(storage);
	free(line);
	return (-1);
}

static int	success_gnl(char *nl_p, char **storage, char *buf, char **line)
{
	char	*tmp;

	tmp = NULL;
	*nl_p = '\0';
	*line = ft_strjoin(*storage, buf);
	if (!(*line))
		return (free_all(*storage, buf, *line));
	tmp = *storage;
	*storage = ft_strjoin((nl_p + 1), NULL);
	if (!(*storage))
		return (free_all(tmp, buf, *line));
	ft_safe_free_char(&tmp);
	ft_safe_free_char(&buf);
	return (1);
}

static int	finish_gnl(char **storage, char *buf, char **line)
{
	*line = ft_strjoin(*storage, buf);
	if (!(*line))
		return (free_all(*storage, buf, *line));
	ft_safe_free_char(storage);
	ft_safe_free_char(&buf);
	return (0);
}

static int	loop_gnl(int fd, char **storage, char *buf, char **line)
{
	char		*tmp;
	size_t		len;
	ssize_t		read_len;

	while (1)
	{
		read_len = read(fd, buf, GNL_BUFFER_SIZE);
		if (read_len < 0)
			return (free_all(*storage, buf, *line));
		buf[read_len] = '\0';
		len = GNL_BUFFER_SIZE;
		if (read_len < GNL_BUFFER_SIZE)
			len = read_len;
		tmp = ft_find_new_line(buf, len);
		if (tmp)
			return (success_gnl(tmp, storage, buf, line));
		if (read_len < GNL_BUFFER_SIZE && !tmp)
			return (finish_gnl(storage, buf, line));
		tmp = ft_strjoin(*storage, buf);
		if (!tmp)
			return (free_all(*storage, buf, *line));
		ft_safe_free_char(storage);
		*storage = tmp;
	}
}

int	ft_get_next_line(int fd, char **line)
{
	static char	*storage;
	char		*buf;
	char		*tmp;

	buf = NULL;
	if (!line || fd < 0 || GNL_BUFFER_SIZE <= 0)
		return (free_all(storage, buf, NULL));
	*line = NULL;
	if (storage)
	{
		tmp = ft_find_new_line(storage, ft_strlen(storage));
		if (tmp)
			return (success_gnl(tmp, &storage, buf, line));
	}
	buf = malloc(GNL_BUFFER_SIZE + 1);
	if (!buf)
		return (free_all(storage, buf, *line));
	return (loop_gnl(fd, &storage, buf, line));
}
