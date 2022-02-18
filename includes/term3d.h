#ifndef TERM3D_H
# define TERM3D_H

# include <stdbool.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <math.h>
# include <termios.h>
# include "minilibft.h"

# define X_INDEX 0
# define Y_INDEX 1
# define Z_INDEX 2

# define CANVAS_X_SIZE 80
# define CANVAS_Y_SIZE 40

# define DIM_X_SIZE 7
# define DIM_Y_SIZE 7

# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif

typedef struct s_point	t_point;

struct s_point {
	double	x_pos;
	double	y_pos;
	double	z_pos;
	t_point	*next;
};

void	parse_arguments(char *file_name, t_point **list_start);

char	**allocate_canvas(void);
void	init_canvas(char **canvas);
void	free_canvas(char ***canvas);
void	print_canvas(char **canvas);

t_point	*convert_to_point(const char *str, t_point *prev);
void	free_point_list(t_point **list);

void	loop(t_point *list, char **canvas);
void	render_object(t_point *list, char **canvas, char c);

void	draw_object(t_point *point_list, char **canvas);

void	rotate_object(t_point *list, char control);
void	rotate_point(t_point *point, double angle);

void	fix_center(t_point *list);

char	get_control_char(void);
bool	set_terminal_setting(void);
bool	reset_terminal_setting(void);

void	zoom_in(t_point *list);
void	zoom_out(t_point *list);

void	error_exit(const char *reason);

#endif
