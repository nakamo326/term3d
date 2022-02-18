#include <term3d.h>

void	zoom_in(t_point *list)
{
	t_point			*point;

	point = list;
	while (point)
	{
		point->x_pos *= 1.05;
		point->y_pos *= 1.05;
		point->z_pos *= 1.05;
		point = point->next;
	}
}

void	zoom_out(t_point *list)
{
	t_point			*point;

	point = list;
	while (point)
	{
		point->x_pos *= 0.95;
		point->y_pos *= 0.95;
		point->z_pos *= 0.95;
		point = point->next;
	}
}
