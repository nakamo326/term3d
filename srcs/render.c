/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynakamot <ynakamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 19:28:03 by ynakamot          #+#    #+#             */
/*   Updated: 2022/02/20 11:47:00 by ynakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "term3d.h"

bool	is_camera_control(char c)
{
	return (c == 'h' || c == 'j' || c == 'k' || c == 'l'
		|| c == 'u' || c == 'i');
}

void	render_object(t_point *list, char **canvas, char c)
{
	static bool		rotate_flag = true;
	static t_angle	camera_state;

	init_canvas(canvas);
	puts(RESET_CURSOR);
	if (c == ' ')
		rotate_flag = !rotate_flag;
	if (rotate_flag)
		rotate_object(list, c);
	if (is_camera_control(c))
		rotate_camera(&camera_state, c);
	if (c == 'r')
		zoom_out(list);
	if (c == 'f')
		zoom_in(list);
	draw_object(list, canvas, &camera_state);
}
