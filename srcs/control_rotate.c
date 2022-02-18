#include "term3d.h"

void	rotate_object(t_point *list, char control)
{
	static int		axis = Y_INDEX;
	static double	angle = M_PI / 180;

	if (control == 'a' || control == 'd')
		axis = Y_INDEX;
	else if (control == 'w' || control == 's')
		axis = X_INDEX;
	if (control == 'w' || control == 'd')
		angle = M_PI / 180;
	else if (control == 'a' || control == 's')
		angle = -M_PI / 180;
	rotate_points(axis, list, 2 * angle);
}

void	rotate_camera(t_point *list, char control)
{
	double angle;

	angle = M_PI / 180 * 5;
	if (control == 'h') {
		rotate_points(Y_INDEX, list, angle);
	} else if (control == 'j') {
		rotate_points(X_INDEX, list, -angle);
	} else if (control == 'k') {
		rotate_points(X_INDEX, list, angle);
	} else if (control == 'l') {
		rotate_points(Y_INDEX, list, -angle);
	}
}
