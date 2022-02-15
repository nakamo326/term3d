#ifndef TERM3D_H
# define TERM3D_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "libft.h"

typedef struct s_point t_point; 

struct s_point {
	double x_pos;
	double y_pos;
	double z_pos;
	t_point *next;
};

void parse_arguments(char *file_name);

#endif