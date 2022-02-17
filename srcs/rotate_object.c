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

void	rotate_object(t_point *list, char control)
{
	t_point			*point;
	static int		axis = 1;
	static double	angle = M_PI / 180;
	void			(*fp[2])(t_point*, double);

	fp[0] = rotate_point_x_axis;
	fp[1] = rotate_point_y_axis;
	if (control == 'a' || control == 'd')
		axis = 1;
	else if (control == 'w' || control == 's')
		axis = 0;
	if (control == 'w' || control == 'd')
		angle = M_PI / 180;
	else if (control == 'a' || control == 's')
		angle = -M_PI / 180;
	point = list;
	while (point)
	{
		fp[axis](point, angle);
		point = point->next;
	}
}
