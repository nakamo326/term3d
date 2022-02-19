/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_object.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynakamot <ynakamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 19:28:03 by ynakamot          #+#    #+#             */
/*   Updated: 2022/02/20 01:39:55 by ynakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "term3d.h"

void	rotate_point_x_axis(t_point *point, double angle)
{
	t_point	tmp;

	tmp.y_pos = cos(angle) * point->y_pos - sin(angle) * point->z_pos;
	tmp.z_pos = sin(angle) * point->y_pos + cos(angle) * point->z_pos;
	point->y_pos = tmp.y_pos;
	point->z_pos = tmp.z_pos;
}

void	rotate_point_y_axis(t_point *point, double angle)
{
	t_point	tmp;

	tmp.x_pos = cos(angle) * point->x_pos + sin(angle) * point->z_pos;
	tmp.z_pos = -sin(angle) * point->x_pos + cos(angle) * point->z_pos;
	point->x_pos = tmp.x_pos;
	point->z_pos = tmp.z_pos;
}

void	rotate_point_z_axis(t_point *point, double angle)
{
	t_point	tmp;

	tmp.x_pos = cos(angle) * point->x_pos - sin(angle) * point->y_pos;
	tmp.y_pos = sin(angle) * point->x_pos + cos(angle) * point->y_pos;
	point->x_pos = tmp.x_pos;
	point->y_pos = tmp.y_pos;
}

void	rotate_points(t_index axis, t_point *list, double angle)
{
	t_point	*point;
	void	(*rotate_fp[3])(t_point*, double);

	rotate_fp[0] = rotate_point_x_axis;
	rotate_fp[1] = rotate_point_y_axis;
	rotate_fp[2] = rotate_point_z_axis;
	point = list;
	while (point)
	{
		rotate_fp[axis](point, angle);
		point = point->next;
	}
}
