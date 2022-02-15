#include "term3d.h"

int main(int argc, char **argv) {
	t_point *list;

	if (argc != 2)
		return (1);
	list = NULL;
	parse_arguments(argv[1], &list);

	free_point_list(&list);
	return (0);
}