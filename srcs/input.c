/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynakamot  <ynakamot@student.42tokyo.j      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 18:51:00 by ynakamot          #+#    #+#             */
/*   Updated: 2022/02/18 18:51:00 by ynakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "term3d.h"

void	parse_arguments(char *file_name, t_point **list_start)
{
	int		fd;
	int		gnl_res;
	char	*str_res;
	t_point	*list_res;

	gnl_res = 1;
	list_res = NULL;
	str_res = NULL;
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		error_exit("ERROR: Open Fail.");
	while (gnl_res)
	{
		gnl_res = ft_get_next_line(fd, &str_res);
		if (gnl_res < 0)
			error_exit("ERROR: GNL Fail.");
		list_res = convert_to_point(str_res, list_res);
		if (*list_start == NULL)
			*list_start = list_res;
		free(str_res);
	}
}
