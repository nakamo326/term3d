#include "term3d.h"

int calc_pos_in_canvas(double pos, int dim_size, int canvas_size)
{
	double dimension_pos;
	double canvas_pos;

	pos += (dim_size / 2);
	dimension_pos = pos / dim_size;
	canvas_pos = round(dimension_pos * canvas_size);
	return (int)(canvas_pos);
}

bool is_drawable_point(int pos, int canvas_size)
{
	if (pos >= 0 && pos < canvas_size)
	{
		return (true);
	}
	return (false);
}

void draw_point(t_point *point, char **canvas)
{
	int x_pos;
	int y_pos;

	x_pos = calc_pos_in_canvas(point->x_pos, DIM_X_SIZE, CANVAS_X_SIZE);
	y_pos = calc_pos_in_canvas(point->y_pos, DIM_Y_SIZE, CANVAS_Y_SIZE);
	if (is_drawable_point(x_pos, CANVAS_X_SIZE)
		&& is_drawable_point(y_pos, CANVAS_Y_SIZE))
	{
		canvas[y_pos][x_pos] = '.';
	}
}

void draw_object(t_point *point_list, char **canvas)
{
	t_point *point;

	point = point_list;
	while (point)
	{
		draw_point(point, canvas);
		point = point->next;
	}
}