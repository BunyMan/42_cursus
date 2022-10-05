/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuny-fe <jbuny-fe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 16:12:27 by jbuny-fe          #+#    #+#             */
/*   Updated: 2022/08/29 21:56:09 by jbuny-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	ext_check(char *map_file)
{
	unsigned int	index;
	char			*map_verif;

	index = ft_strlen(map_file) - 4;
	map_verif = ft_substr(map_file, index, 5);
	if (!ft_strncmp(map_verif, ".ber", 5))
	{
		free(map_verif);
		return (1);
	}
	free(map_verif);
	return (0);
}

int	file_check(char *map_str)
{
	int	i;

	i = 0;
	if (!map_str)
		return(0);
	while (map_str[i])
	{
		if (map_str[i] != '\t' && map_str[i] != ' ' && map_str[i] != '1'
			&& map_str[i] != '0' && map_str[i] != 'C' && map_str[i] != 'P'
			&& map_str[i] != 'E' && map_str[i] != '\n')
			{
				free(map_str);
				return (0);
			}
		i++;
	}
	return (1);
}

char	*rm_empty(char *map_str)
{
	int		i;
	char	*tmp;

	i = 0;
	while (map_str[i] && map_str[i] != '1')
		i++;
	tmp = ft_substr(map_str, i, ft_strlen(map_str));
	free(map_str);
	map_str = ft_strdup(tmp);
	free(tmp);
	while (map_str[i] != '\0')
	{
		i++;
		if (map_str[i] == '\n' && map_str[i + 1] == '\n')
			break ;
	}
	tmp = ft_substr(map_str, 0, i);
	free(map_str);
	map_str = ft_strdup(tmp);
	free(tmp);
	return (map_str);
}

char	**turn_to_matrix(char *map_str, t_map *map)
{
	char	*tmp;

	if (!strchr(map_str, '1'))
		return (0);
	tmp = ft_strtrim(map_str, "\t ");
	free(map_str);
	map_str = ft_strdup(tmp);
	free(tmp);
	tmp = rm_empty(map_str);
	map->matrix = ft_split(tmp, '\n');
	free(tmp);
	return (map->matrix);
}

char	**read_map(char *map_file, t_map *map)
{
	char	*tmp;
	char	*tmp2;
	char	*map_str;

	if (!ext_check(map_file))
		return (0);
	map->fd = open(map_file, O_RDONLY);
	tmp = get_next_line(map->fd);
	map_str = ft_strdup(tmp);
	free(tmp);
	while (1)
	{
		tmp = get_next_line(map->fd);
		if (!tmp)
			break ;
		tmp2 = ft_strjoin(map_str, tmp);
		free(tmp);
		free(map_str);
		map_str = ft_strdup(tmp2);
		free(tmp2);
	}
	if (!file_check(map_str))
		return (0);
	map->matrix = turn_to_matrix(map_str, map);
	return (map->matrix);
}
