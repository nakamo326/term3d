#include <term3d.h>

void	zoom_in(t_point *list)
{
	t_point			*point;

	point = list;
	while (point)
	{
		point->x_pos *= 1.02;
		point->y_pos *= 1.02;
		point->z_pos *= 1.02;
		point = point->next;
	}
}

void	zoom_out(t_point *list)
{
	t_point			*point;

	point = list;
	while (point)
	{
		point->x_pos *= 0.98;
		point->y_pos *= 0.98;
		point->z_pos *= 0.98;
		point = point->next;
	}
}
