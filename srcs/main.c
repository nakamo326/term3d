#include "term3d.h"

int main(int argc, char **argv) {
	t_point *list;
	char **canvas;

	if (argc != 2)
		return (1);
	list = NULL;
	canvas = NULL;
	parse_arguments(argv[1], &list);
	canvas = allocate_canvas();
	draw_object(list, canvas);
	print_canvas(canvas);
	free_point_list(&list);
	free_canvas(&canvas);
	canvas = NULL;
	return (0);
}