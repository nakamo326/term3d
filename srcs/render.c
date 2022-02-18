#include "term3d.h"

void	render_object(t_point *list, char **canvas, char c)
{
	static bool	rotate_flag = true;

	init_canvas(canvas);
	puts("\033[1;1H");
	if (c == ' ')
		rotate_flag = !rotate_flag;
	if (rotate_flag)
		rotate_object(list, c);
	if (c == 'r')
		zoom_out(list);
	if (c == 'f')
		zoom_in(list);
	draw_object(list, canvas);
}
