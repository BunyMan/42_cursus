
#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	error(char *str_error)
{
	write(2, str_error, ft_strlen(str_error));
	exit(1);
}
