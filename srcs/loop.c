/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynakamot  <ynakamot@student.42tokyo.j      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 21:03:55 by ynakamot          #+#    #+#             */
/*   Updated: 2022/02/19 11:16:28 by ynakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "term3d.h"

void	clear_terminal(void)
{
	puts("\033[2J");
}

void	clear_terminal_under_here(void)
{
	puts("\033[0J");
}

void	print_help(void)
{
	clear_terminal_under_here();
	puts("WASD: rotate object   HJKL: rotate camera"
		"   space: toggle object rotating\n"
		"R: zoom out   F: zoom in   Q: quit");
}

void	loop(t_point *list, char **canvas)
{
	char	c;

	clear_terminal();
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
