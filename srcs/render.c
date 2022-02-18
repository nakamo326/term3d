#include "term3d.h"

void	reset_cursor(void)
{
	puts("\033[1;1H");
}

bool	is_camera_control(char c)
{
	return (c == 'h' || c == 'j' || c == 'k' || c == 'l');
}

void	render_object(t_point *list, char **canvas, char c)
{
	static bool	rotate_flag = true;

	init_canvas(canvas);
	reset_cursor();
	if (c == ' ')
		rotate_flag = !rotate_flag;
	if (rotate_flag)
		rotate_object(list, c);
	if (is_camera_control(c))
		rotate_camera(list, c);
	if (c == 'r')
		zoom_out(list);
	if (c == 'f')
		zoom_in(list);
	draw_object(list, canvas);
}
