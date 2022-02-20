/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynakamot <ynakamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 19:28:03 by ynakamot          #+#    #+#             */
/*   Updated: 2022/02/20 11:45:33 by ynakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "term3d.h"

void	rotate_object(t_point *list, char control)
{
	static t_index	axis = Y_INDEX;
	static double	angle = M_PI / 180;

	if (control == 'a' || control == 'd')
		axis = Y_INDEX;
	else if (control == 'w' || control == 's')
		axis = X_INDEX;
	if (control == 'w' || control == 'd')
		angle = M_PI / 180;
	else if (control == 'a' || control == 's')
		angle = -M_PI / 180;
	rotate_points(axis, list, 2 * angle);
}

void	add_angle(t_angle *angle_state, t_index axis, int degree)
{
	if (axis == X_INDEX)
	{
		angle_state->x = (angle_state->x + degree) % 360;
	}
	else if (axis == Y_INDEX)
	{
		angle_state->y = (angle_state->y + degree) % 360;
	}
	else if (axis == Z_INDEX)
	{
		angle_state->z = (angle_state->z + degree) % 360;
	}
}

void	rotate_camera(t_angle *camera_state, char control)
{
	if (control == 'h')
	{
		add_angle(camera_state, Y_INDEX, 5);
	}
	else if (control == 'j')
	{
		add_angle(camera_state, X_INDEX, 5);
	}
	else if (control == 'k')
	{
		add_angle(camera_state, X_INDEX, -5);
	}
	else if (control == 'l')
	{
		add_angle(camera_state, Y_INDEX, -5);
	}
	else if (control == 'u')
	{
		add_angle(camera_state, Z_INDEX, -5);
	}
	else if (control == 'i')
	{
		add_angle(camera_state, Z_INDEX, 5);
	}
}
