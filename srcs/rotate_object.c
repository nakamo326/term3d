#include "term3d.h"


// 全ての点の中心を軸にする。原点修正？
// https://imagingsolution.net/imaging/affine-transformation/
// https://imagingsolution.net/math/rotation-scaling-translation-3d-matrix/


void rotate_point_x_axis(t_point *point, double angle) {
	t_point tmp;
	tmp.x_pos = point->x_pos;
	tmp.y_pos = cos(angle) * point->y_pos - sin(angle) * point->z_pos;
	tmp.z_pos = sin(angle) * point->y_pos + cos(angle) * point->z_pos;
	point->x_pos = tmp.x_pos;
	point->y_pos = tmp.y_pos;
	point->z_pos = tmp.z_pos;
}

void rotate_point_y_axis(t_point *point, double angle) {
	t_point tmp;
	tmp.x_pos = cos(angle) * point->x_pos + sin(angle) * point->z_pos;
	tmp.y_pos = point->y_pos;
	tmp.z_pos = -sin(angle) * point->x_pos + cos(angle) * point->z_pos;
	point->x_pos = tmp.x_pos;
	point->y_pos = tmp.y_pos;
	point->z_pos = tmp.z_pos;
}

void rotate_point_z_axis(t_point *point, double angle) {
	t_point tmp;
	tmp.x_pos = cos(angle) * point->x_pos - sin(angle) * point->y_pos;
	tmp.y_pos = sin(angle) * point->x_pos + cos(angle) * point->y_pos;
	tmp.z_pos = point->z_pos;
	point->x_pos = tmp.x_pos;
	point->y_pos = tmp.y_pos;
	point->z_pos = tmp.z_pos;
}

void rotate_object(t_point *list, char control) {
	t_point *point;
	static int axis = 1;
	static double angle = M_PI / 180;
	void (*fp[2])(t_point*, double) = {rotate_point_x_axis, rotate_point_y_axis};

	switch (control)
	{
	case 'w':
		angle = M_PI / 180;
		axis = 0;
		break;
	case 'a':
		angle = -M_PI / 180;
		axis = 1;
		break;
	case 's':
		angle = -M_PI / 180;
		axis = 0;
		break;
	case 'd':
		angle = M_PI / 180;
		axis = 1;
		break;
	default:
		break;
	}

	point = list;
	while(point) {
		fp[axis](point, angle);
		point = point->next;
	}
}