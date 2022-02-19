/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynakamot <ynakamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 19:28:03 by ynakamot          #+#    #+#             */
/*   Updated: 2022/02/20 02:19:07 by ynakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "term3d.h"

bool	is_camera_control(char c)
{
	return (c == 'h' || c == 'j' || c == 'k' || c == 'l');
}

void	render_object(t_point *list, char **canvas, char c)
{
	static bool	rotate_flag = true;
	t_angle rotatation_angle;

	memset(&rotatation_angle, 0, sizeof(t_angle));
	init_canvas(canvas);
	puts(RESET_CURSOR);
	if (c == ' ')
		rotate_flag = !rotate_flag;
	if (rotate_flag)
		rotate_object(list, c);
	if (is_camera_control(c))
		rotate_camera(list, c);
	if (c == 'r')
		zoom_out(list);
	if (c == 'f')
		zoom_in(list);
	draw_object(list, canvas);
}
