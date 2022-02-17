#include "term3d.h"

void	rotate_loop_tmp(t_point *list, char **canvas)
{
	char	c;

	printf("\033[2J");
	while (1)
	{
		c = get_control_char();
		if (c == 'q')
			break ;
		usleep(60000);
		printf("\033[%d;%dH", 1, 1);
		init_canvas(canvas);
		rotate_object(list, c);
		if (c == 'r')
			zoom_out(list);
		if (c == 'f')
			zoom_in(list);
		draw_object(list, canvas);
		print_canvas(canvas);
	}
}

int	main(int argc, char **argv)
{
	t_point	*list;
	char	**canvas;

	if (argc != 2)
		return (1);
	list = NULL;
	canvas = NULL;
	parse_arguments(argv[1], &list);
	canvas = allocate_canvas();
	fix_center(list);
	rotate_loop_tmp(list, canvas);
	free_point_list(&list);
	free_canvas(&canvas);
	canvas = NULL;
	return (0);
}
