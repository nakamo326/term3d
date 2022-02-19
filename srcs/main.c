/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynakamot  <ynakamot@student.42tokyo.j      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 19:28:03 by ynakamot          #+#    #+#             */
/*   Updated: 2022/02/19 11:18:06 by ynakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "term3d.h"

void	error_exit(const char *reason)
{
	printf("%s\n", reason);
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_point	*list;
	char	**canvas;

	if (argc != 2)
		return (1);
	list = NULL;
	canvas = NULL;
	parse_arguments(argv[1], &list);
	canvas = allocate_canvas();
	fix_center(list);
	loop(list, canvas);
	free_point_list(&list);
	free_canvas(&canvas);
	canvas = NULL;
	return (0);
}
