#ifndef TERM3D_H
# define TERM3D_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "libft.h"
#include "errno.h"
#include <string.h>

#define X_INDEX 0
#define Y_INDEX 1
#define Z_INDEX 2

#define CANVAS_X_SIZE 60
#define CANVAS_Y_SIZE 30

typedef struct s_point t_point; 

struct s_point {
	double x_pos;
	double y_pos;
	double z_pos;
	t_point *next;
};

void parse_arguments(char *file_name, t_point** list_start);

char **allocate_canvas(void);
void init_canvas(char** canvas);
void free_canvas(char ***canvas);
void print_canvas(char **canvas);

t_point *convert_to_point(const char* str, t_point *prev);
void free_point_list(t_point **list);

#endif