#include "term3d.h"

void	init_canvas(char **canvas)
{
	size_t	index;

	index = 0;
	while (canvas[index])
	{
		memset(canvas[index], ' ', (sizeof(char) * CANVAS_X_SIZE));
		index++;
	}
}

char	**allocate_canvas(void)
{
	char	**res;
	size_t	index;

	index = 0;
	res = malloc(sizeof(char *) * (CANVAS_Y_SIZE + 1));
	if (!res)
		error_exit("ERROR: malloc Fail.");
	res[CANVAS_Y_SIZE] = NULL;
	while (index < CANVAS_Y_SIZE)
	{
		res[index] = malloc(sizeof(char) * CANVAS_X_SIZE + 1);
		if (!res[index])
			error_exit("ERROR: malloc Fail.");
		res[index][CANVAS_X_SIZE] = '\0';
		index++;
	}
	init_canvas(res);
	return (res);
}

void	print_canvas(char **canvas)
{
	size_t	index;

	index = 0;
	while (canvas[index])
	{
		printf("%s\n", canvas[index]);
		index++;
	}
}

void	free_canvas(char ***canvas)
{
	size_t	index;
	char	**canvas_mem;

	canvas_mem = *canvas;
	index = 0;
	while (canvas_mem[index])
	{
		free(canvas_mem[index]);
		index++;
	}
	free(canvas_mem);
	*canvas = NULL;
}
