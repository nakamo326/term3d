/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynakamot <ynakamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 21:03:55 by ynakamot          #+#    #+#             */
/*   Updated: 2022/02/20 01:47:55 by ynakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "term3d.h"

void	print_help(void)
{
	puts(CLEAR_UNDER);
	puts("WASD: rotate object   HJKL: rotate camera"
		"   space: toggle object rotating\n"
		"R: zoom out   F: zoom in   Q: quit");
}

void	loop(t_point *list, char **canvas)
{
	char	c;

	puts(CLEAR_TERMINAL);
	set_terminal_setting();
	while (1)
	{
		c = get_control_char();
		if (c == 'q')
			break ;
		render_object(list, canvas, c);
		print_canvas(canvas);
		print_help();
		usleep(60000);
	}
	reset_terminal_setting();
}
