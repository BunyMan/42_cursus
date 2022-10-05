/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuny-fe <jbuny-fe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 15:20:31 by jbuny-fe          #+#    #+#             */
/*   Updated: 2022/08/02 20:27:28 by jbuny-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	draw(t_mlbx *mlbx, int y, int x)
{
	if (mlbx->map.matrix[y][x] == '1')
		mlx_put_image_to_window(mlbx->mlx, mlbx->window,
			mlbx->walltree.img, x * 128, y * 128);
	else if (mlbx->map.matrix[y][x] == 'P')
	{
		mlbx->player.x = x;
		mlbx->player.y = y;
		mlx_put_image_to_window(mlbx->mlx, mlbx->window, mlbx->player.img,
			mlbx->player.x * 128, mlbx->player.y * 128);
	}
	else if (mlbx->map.matrix[y][x] == '0')
		mlx_put_image_to_window(mlbx->mlx, mlbx->window, mlbx->path.img,
			x * 128, y * 128);
	else if (mlbx->map.matrix[y][x] == 'C')
		mlx_put_image_to_window(mlbx->mlx, mlbx->window, mlbx->coll.img,
			x * 128, y * 128);
	else if (mlbx->map.matrix[y][x] == 'E')
		mlx_put_image_to_window(mlbx->mlx, mlbx->window, mlbx->door.img,
			x * 128, y * 128);
}

void	fill_map(t_mlbx *mlbx)
{
	int			y;
	int			x;

	y = 0;
	load_imgs(mlbx);
	while (mlbx->map.matrix[y])
	{
		x = 0;
		while (mlbx->map.matrix[y][x])
		{
			draw(mlbx, y, x);
			x++;
		}
		y++;
	}
}
