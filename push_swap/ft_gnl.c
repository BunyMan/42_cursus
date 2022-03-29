/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuny-fe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 05:34:44 by jbuny-fe          #+#    #+#             */
/*   Updated: 2022/03/18 04:28:15 by jbuny-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strjoin(char *str1, char *str2)
{
	char		*res;
	int			i;

	if (!str1)
		return (ft_strdup(str2, '\0'));
	res = (char *)malloc(sizeof(char) * (ft_strlen(str1)
				+ ft_strlen(str2) + 1));
	if (!res)
		return (NULL);
	i = -1;
	while (str1[++i] != '\0')
		res[i] = str1[i];
	while (str2[i - ft_strlen(str1)] != '\0')
	{
		res[i] = str2[i - ft_strlen(str1)];
		i++;
	}
	res[i] = '\0';
	return (res);
}

int	ft_check_line(char *str)
{
	int		i;

	if (str == NULL)
		return (1);
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\n')
		return (0);
	return (1);
}

char	*ft_strdup(char *str, char c)
{
	int		i;
	char	*res;

	i = 0;
	while (str[i] != c && str[i] != '\0')
		i++;
	res = (char *)malloc(sizeof(char) * (i + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (str[i] != c && str[i] != '\0')
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_subdup(char *str)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	j = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		while (str[i + j] != '\0')
			j++;
	if (j == 0)
		return (NULL);
	res = (char *)malloc(sizeof(char) * (j + 1));
	if (!res)
		return (NULL);
	j = 0;
	while (str[i++] != '\0')
	{
		res[j] = str[i];
		j++;
	}
	return (res);
}

/*adjusting gnl for buffer size of 1 */
char	*get_next_line(void)
{
	char		*buf;
	static char	*res;
	int			fr;
	char		*temp;
	char		*line;

	buf = (char *)malloc(sizeof(char) * (2));
	fr = 1;
	while (ft_check_line(res) == 1 && fr > 0)
	{
		fr = read(0, buf, 1);
		buf[fr] = '\0';
		temp = ft_strjoin(res, buf);
		free(res);
		res = temp;
	}
	line = ft_strdup(res, '\n');
	temp = ft_subdup(res);
	free(res);
	res = temp;
	free(buf);
	return (line);
}
