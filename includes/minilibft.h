#ifndef MINILIBFT_H
# define MINILIBFT_H

#include "stdlib.h"
#include "unistd.h"

# define GNL_BUFFER_SIZE 1024


typedef enum e_bool
{
	FALSE,
	TRUE
}				t_bool;


char	*ft_find_new_line(const char *s, size_t len);
int	ft_get_next_line(int fd, char **line);
void	ft_safe_free_split(char ***target);
char	**ft_split(char const *s, char c);
void	ft_safe_free_char(char **target);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s1);

#endif