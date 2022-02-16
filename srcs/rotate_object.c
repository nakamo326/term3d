#include "term3d.h"


// 全ての点の中心を軸にする。原点修正？
// https://imagingsolution.net/imaging/affine-transformation/
// https://imagingsolution.net/math/rotation-scaling-translation-3d-matrix/


void rotate_point(t_point *point, double angle) {
	t_point tmp;
	tmp.x_pos = cos(angle) * point->x_pos + sin(angle) * point->z_pos;
	tmp.y_pos = point->y_pos;
	tmp.z_pos = -sin(angle) * point->x_pos + cos(angle) * point->z_pos;
	point->x_pos = tmp.x_pos;
	point->y_pos = tmp.y_pos;
	point->z_pos = tmp.z_pos;
}

void rotate_object(t_point *list) {
	t_point *point;
	point = list;
	while(point) {
		rotate_point(point, M_PI / 180);
		point = point->next;
	}
}