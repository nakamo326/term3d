#include "term3d.h"

void	loop(t_point *list, char **canvas)
{
	char	c;

	puts("\033[2J");
	while (1)
	{
		c = get_control_char();
		if (c == 'q')
			break ;
		render_object(list, canvas, c);
		print_canvas(canvas);
		usleep(60000);
	}
}
