#include "term3d.h"

t_point	calc_center(t_point *list)
{
	t_point	res;
	size_t	i;
	t_point	*point;

	memset(&res, 0, sizeof(t_point));
	i = 0;
	point = list;
	while (point)
	{
		res.x_pos += point->x_pos;
		res.y_pos += point->y_pos;
		res.z_pos += point->z_pos;
		point = point->next;
		i++;
	}
	res.x_pos /= i;
	res.y_pos /= i;
	res.z_pos /= i;
	return (res);
}

void	fix_center(t_point *list)
{
	t_point	*point;
	t_point	new_center;

	new_center = calc_center(list);
	point = list;
	while (point)
	{
		point->x_pos -= new_center.x_pos;
		point->y_pos -= new_center.y_pos;
		point->z_pos -= new_center.z_pos;
		point = point->next;
	}
}
