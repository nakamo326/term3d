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

void rotate_object(t_point *list) {
	t_point *point;
	point = list;
	while(point) {
		rotate_point_y_axis(point, M_PI / 180);
		point = point->next;
	}
}