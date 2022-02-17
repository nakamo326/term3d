#include "term3d.h"

t_point	calc_center(t_point *list)
{
	t_point	ret;
	size_t	i;
	t_point	*point;

	memset(&ret, 0, sizeof(t_point));
	i = 0;
	point = list;
	while (point)
	{
		ret.x_pos += point->x_pos;
		ret.y_pos += point->y_pos;
		ret.z_pos += point->z_pos;
		point = point->next;
		i++;
	}
	ret.x_pos /= i;
	ret.y_pos /= i;
	ret.z_pos /= i;
	return (ret);
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
