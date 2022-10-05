/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_valid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuny-fe <jbuny-fe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 01:57:03 by jbuny-fe          #+#    #+#             */
/*   Updated: 2022/08/29 22:31:47 by jbuny-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	go_right(t_mlbx *mlbx, int *amount, char target)
{
	printf("right\n");
	if (mlbx->map.tmp_mat[mlbx->coor.y][mlbx->coor.x] != 'P')
		mlbx->map.tmp_mat[mlbx->coor.y][mlbx->coor.x] = 'v';
	mlbx->coor.x++;
	if (mlbx->map.tmp_mat[mlbx->coor.y][mlbx->coor.x] == target)
		(*amount)--;
	if (*amount == 0)
		mlbx->valid = 1;
	else
		return (is_valid(*mlbx, *amount, target));
	return (mlbx->valid);
}

int	go_down(t_mlbx *mlbx, int *amount, char target)
{
	printf("down\n");
	if (mlbx->map.tmp_mat[mlbx->coor.y][mlbx->coor.x] != 'P')
		mlbx->map.tmp_mat[mlbx->coor.y][mlbx->coor.x] = 'v';
	mlbx->coor.y++;
	if (mlbx->map.tmp_mat[mlbx->coor.y][mlbx->coor.x] == target)
		(*amount)--;
	if (*amount == 0)
		mlbx->valid = 1;
	else
		return (is_valid(*mlbx, *amount, target));
	return (mlbx->valid);
}

int	go_left(t_mlbx *mlbx, int *amount, char target)
{
	printf("left\n");
	if (mlbx->map.tmp_mat[mlbx->coor.y][mlbx->coor.x] != 'P')
		mlbx->map.tmp_mat[mlbx->coor.y][mlbx->coor.x] = 'v';
	mlbx->coor.x--;
	if (mlbx->map.tmp_mat[mlbx->coor.y][mlbx->coor.x] == target)
		(*amount)--;
	if (*amount == 0)
		mlbx->valid = 1;
	else
		return (is_valid(*mlbx, *amount, target));
	return (mlbx->valid);
}

int	go_up(t_mlbx *mlbx, int *amount, char target)
{
	printf("up\n");
	if (mlbx->map.tmp_mat[mlbx->coor.y][mlbx->coor.x] != 'P')
		mlbx->map.tmp_mat[mlbx->coor.y][mlbx->coor.x] = 'v';
	mlbx->coor.y--;
	if (mlbx->map.tmp_mat[mlbx->coor.y][mlbx->coor.x] == target)
		(*amount)--;
	if (*amount == 0)
		mlbx->valid = 1;
	else
		return (is_valid(*mlbx, *amount, target));
	return (mlbx->valid);
}

int	is_valid(t_mlbx mlbx, int amount, char target)
{
	
	while (amount > 0)
	{
		printf("pos %c\n", mlbx.map.tmp_mat[mlbx.coor.y][mlbx.coor.x + 2]);
		printf("amount %d\n", amount);

		if (mlbx.map.tmp_mat[mlbx.coor.y - 1][mlbx.coor.x] != '1'
			&& mlbx.map.tmp_mat[mlbx.coor.y - 1][mlbx.coor.x] != 'v')
			mlbx.valid = go_up(&mlbx, &amount, target);
		else if (mlbx.map.tmp_mat[mlbx.coor.y][mlbx.coor.x - 1] != '1'
			&& mlbx.map.tmp_mat[mlbx.coor.y][mlbx.coor.x - 1] != 'v')
			mlbx.valid = go_left(&mlbx, &amount, target);
		else if (mlbx.map.tmp_mat[mlbx.coor.y + 1][mlbx.coor.x] != '1'
			&& mlbx.map.tmp_mat[mlbx.coor.y + 1][mlbx.coor.x] != 'v')
			mlbx.valid = go_down(&mlbx, &amount, target);
		else if (mlbx.map.tmp_mat[mlbx.coor.y][mlbx.coor.x + 1] != '1'
			&& mlbx.map.tmp_mat[mlbx.coor.y][mlbx.coor.x + 1] != 'v')
			mlbx.valid = go_right(&mlbx, &amount, target);
		else
			break ;
	}
	return (mlbx.valid);
}
