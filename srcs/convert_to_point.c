#include "term3d.h"

double convert_to_double(const char* str)
{
	double res;

	errno = 0;
	res = strtod(str, NULL);
	if (errno == ERANGE)
		exit(EXIT_FAILURE); //error
	// TODO validation nan,inf
	return (res);
}

t_point *convert_to_point(const char* str, t_point *prev)
{
	t_point *res;
	char **split_str;

	// TODO validation
	split_str = ft_split(str, ',');
	res = malloc(sizeof(t_point));
	if(!res || !split_str)
		exit(EXIT_FAILURE); //error
	res->x_pos = convert_to_double(split_str[X_INDEX]);
	res->y_pos = convert_to_double(split_str[Y_INDEX]);
	res->z_pos = convert_to_double(split_str[Z_INDEX]);
	res->next = NULL;
	if (prev)
		prev->next = res;
	ft_safe_free_split(&split_str);
	return (res);
}

void free_point_list(t_point **list)
{
	t_point *now;
	t_point *tmp;

	now = *list;
	while (now)
	{
		tmp = now->next;
		free(now);
		now = tmp;
	}
	*list = NULL;
}