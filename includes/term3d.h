/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynakamot <ynakamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 16:09:03 by ynakamot          #+#    #+#             */
/*   Updated: 2022/02/20 14:56:52 by ynakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

# define RESET_CURSOR "\033[1;1H"
# define CLEAR_TERMINAL "\033[2J"
# define CLEAR_UNDER "\033[0J"
# define DISABLE_CURSOR "\033[?25l"
# define ENABLE_CURSOR "\033[?25h"

# define CANVAS_X_SIZE 80
# define CANVAS_Y_SIZE 40

# define DIM_X_SIZE 7
# define DIM_Y_SIZE 7

# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif

typedef enum e_index {
	X_INDEX,
	Y_INDEX,
	Z_INDEX
}	t_index;

typedef struct s_point	t_point;

struct s_point {
	double	x_pos;
	double	y_pos;
	double	z_pos;
	t_point	*next;
};

typedef struct s_angle {
	int	x;
	int	y;
	int	z;
}	t_angle;

void	parse_arguments(char *file_name, t_point **list_start);

char	**allocate_canvas(void);
void	init_canvas(char **canvas);
void	free_canvas(char ***canvas);
void	print_canvas(char **canvas);

t_point	*convert_to_point(const char *str, t_point *prev);
void	free_point_list(t_point **list);

void	loop(t_point *list, char **canvas);
void	render_object(t_point *list, char **canvas, char c);

void	draw_object(t_point *list, char **canvas, const t_angle *camera_state);

void	rotate_object(t_point *list, char control);
void	rotate_camera(t_angle *camera_state, char control);
void	rotate_points(t_index axis, t_point *list, double angle);
t_point	apply_camera_angle(t_point *point, const t_angle *camera_state);

void	fix_center(t_point *list);

char	get_control_char(void);
void	set_terminal_setting(void);
void	reset_terminal_setting(void);

void	zoom_in(t_point *list);
void	zoom_out(t_point *list);

void	error_exit(const char *reason);

#endif
