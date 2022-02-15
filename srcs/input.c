#include "term3d.h"

void parse_arguments(char *file_name)
{
	int fd;
	int res;
	char *str_res;

	fd = open(file_name, O_RDONLY);
	res = 1;
	if (fd < 0)
		exit(EXIT_FAILURE); //error

	while(res)
	{
		res = ft_get_next_line(fd, &str_res);
		if (res < 0)
			exit(EXIT_FAILURE); //error
		printf("%s\n", str_res);
	}
}