#include "term3d.h"

int main(int argc, char **argv) {
	if (argc != 2)
		return (1);
	parse_arguments(argv[1]);
	return (0);
}