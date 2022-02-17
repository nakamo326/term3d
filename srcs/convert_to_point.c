#include "term3d.h"

double convert_to_double(const char* str)
{
	double res;
	char *end_ptr;

	end_ptr = NULL;
	errno = 0;
	res = strtod(str, &end_ptr);
	if (errno == ERANGE || *end_ptr || isnan(res) || isinf(res))
		exit(EXIT_FAILURE); //error
	return (res);
}

bool is_valid_format(char** strs)
{
	size_t p_index;
	size_t c_index;

	p_index = 0;
	while (strs[p_index])
	{
		c_index = 0;
		while (strs[p_index][c_index])
		{
			if (strchr("1234567890+-.", strs[p_index][c_index]) == NULL)
				exit(EXIT_FAILURE); //error
			c_index++;
		}
		p_index++;
	}
	if (p_index != 3)
		exit(EXIT_FAILURE); //error
	return (true);
}


t_point *convert_to_point(const char* str, t_point *prev)
{
	t_point *res;
	char **split_str;

	if (strlen(str) == 0)
		return (prev);
	split_str = ft_split(str, ',');
	res = malloc(sizeof(t_point));
	if(!res || !split_str || !is_valid_format(split_str))
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