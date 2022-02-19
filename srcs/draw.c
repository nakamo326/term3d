#include "term3d.h"

int	calc_pos_in_canvas(double pos, double dim_size, double canvas_size)
{
	double	dimension_pos;
	double	canvas_pos;

	pos += (dim_size / 2);
	dimension_pos = pos / dim_size;
	canvas_pos = round(dimension_pos * canvas_size);
	return ((int)canvas_pos);
}

bool	is_drawable_point(int x_pos, int y_pos)
{
	const bool	is_x_in_screen = x_pos >= 0 && x_pos < CANVAS_X_SIZE;
	const bool	is_y_in_screen = y_pos >= 0 && y_pos < CANVAS_Y_SIZE;

	return (is_x_in_screen && is_y_in_screen);
}

void	draw_point(t_point *point, char **canvas)
{
	int		x_pos;
	int		y_pos;
	char	c;

	x_pos = calc_pos_in_canvas(point->x_pos, DIM_X_SIZE, CANVAS_X_SIZE);
	y_pos = calc_pos_in_canvas(point->y_pos, DIM_Y_SIZE, CANVAS_Y_SIZE);
	if (is_drawable_point(x_pos, y_pos))
	{
		c = *(strchr(" .-=+xX##", canvas[y_pos][x_pos]) + 1);
		canvas[y_pos][x_pos] = c;
	}
}

void	draw_object(t_point *point_list, char **canvas)
{
	t_point	*point;

	point = point_list;
	while (point)
	{
		draw_point(point, canvas);
		point = point->next;
	}
}
