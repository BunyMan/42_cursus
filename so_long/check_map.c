/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuny-fe <jbuny-fe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 02:41:04 by jbuny-fe          #+#    #+#             */
/*   Updated: 2022/08/29 22:22:37 by jbuny-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	check_items(t_mlbx *mlbx, int i, int j)
{
	if (mlbx->map.matrix[i][j] == 'C')
		mlbx->map.collect++;
	else if (mlbx->map.matrix[i][j] == 'P')
	{
		if (mlbx->map.player > 0)
			ft_error("This game is single player!\n");
		mlbx->map.player++;
		mlbx->coor.y = i;
		mlbx->coor.x = j;
	}
	else if (mlbx->map.matrix[i][j] == 'E')
	{
		if (mlbx->map.door > 0)
			ft_error("Too many exits!\n");
		mlbx->map.door++;
	}
	else if (mlbx->map.matrix[i][j] < '0' || mlbx->map.matrix[i][j] > '1')
		return (0);
	return (1);
}

int	wallborder(t_mlbx *mlbx)
{
	int	i;
	int	size;
	int	j;

	i = -1;
	size = (int) ft_strlen(mlbx->map.matrix[0]);
	while (mlbx->map.matrix[++i])
	{
		if (size != (int) ft_strlen(mlbx->map.matrix[i]))
			return (0);
		if (size > 15)
			ft_error("The map is too large for the screen.\n");
		if (mlbx->map.matrix[i][0] != '1'
			|| mlbx->map.matrix[i][size - 1] != '1')
			return (0);
		j = -1;
		while ((i == 0 || mlbx->map.matrix[i + 1] == NULL)
			&& mlbx->map.matrix[i][++j])
		{
			if (mlbx->map.matrix[i][j] != '1')
				return (0);
		}
	}
	return (1);
}

int	fill_check(t_mlbx *mlbx)
{
	int	i;
	int	j;

	i = -1;
	mlbx->map.collect = 0;
	mlbx->map.player = 0;
	mlbx->map.door = 0;
	while (mlbx->map.matrix[++i])
	{
		j = -1;
		while (mlbx->map.matrix[i][++j])
		{
			if (!check_items(mlbx, i, j))
				return (0);
		}
	}
	if (mlbx->map.collect > 0 && mlbx->map.player > 0 && mlbx->map.door > 0)
		return (1);
	return (0);
}

int	map_checks(t_mlbx *mlbx)
{
	mlbx->valid = 0;
	if (!wallborder(mlbx))
		return (0);
	if (!fill_check(mlbx))
		return (0);
	mlbx->map.tmp_mat = copy_mat(mlbx->map.matrix);
	printf("\n");
	mlbx->valid = is_valid(*mlbx, mlbx->map.collect, 'C');
	if (mlbx->valid == 0)
		return (0);
	mlbx->valid = 0;
	free_mat(mlbx->map.tmp_mat);
	mlbx->map.tmp_mat = copy_mat(mlbx->map.matrix);
	printf("\n");
	mlbx->valid = is_valid(*mlbx, mlbx->map.door, 'E');
	if (mlbx->valid == 0)
		return (0);
	free_mat(mlbx->map.tmp_mat);
	return (1);
}
