/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_object.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynakamot <ynakamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 19:28:03 by ynakamot          #+#    #+#             */
/*   Updated: 2022/02/20 11:41:35 by ynakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "term3d.h"

t_point	rotate_point_x_axis(t_point *point, double angle)
{
	t_point	res;

	res = *point;
	res.y_pos = cos(angle) * point->y_pos - sin(angle) * point->z_pos;
	res.z_pos = sin(angle) * point->y_pos + cos(angle) * point->z_pos;
	return res;
}

t_point	rotate_point_y_axis(t_point *point, double angle)
{
	t_point	res;

	res = *point;
	res.x_pos = cos(angle) * point->x_pos + sin(angle) * point->z_pos;
	res.z_pos = -sin(angle) * point->x_pos + cos(angle) * point->z_pos;
	return res;
}

t_point	rotate_point_z_axis(t_point *point, double angle)
{
	t_point	res;

	res = *point;
	res.x_pos = cos(angle) * point->x_pos - sin(angle) * point->y_pos;
	res.y_pos = sin(angle) * point->x_pos + cos(angle) * point->y_pos;
	return res;
}

void	rotate_points(t_index axis, t_point *list, double angle)
{
	t_point	*point;
	t_point	(*rotate_fp[3])(t_point*, double);

	rotate_fp[0] = rotate_point_x_axis;
	rotate_fp[1] = rotate_point_y_axis;
	rotate_fp[2] = rotate_point_z_axis;
	point = list;
	while (point)
	{
		*point = rotate_fp[axis](point, angle);
		point = point->next;
	}
}

t_point	apply_camera_angle(t_point *point, const t_angle *camera_state)
{
	t_point res;
	res = *point;
	if (camera_state->x != 0)
		res = rotate_point_x_axis(&res, M_PI / 180 * camera_state->x);
	if (camera_state->y != 0)
		res = rotate_point_y_axis(&res, M_PI / 180 * camera_state->y);
	if (camera_state->z != 0)
		res = rotate_point_z_axis(&res, M_PI / 180 * camera_state->z);
	return res;
}
