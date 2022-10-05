/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuny-fe <jbuny-fe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 22:37:11 by jbuny-fe          #+#    #+#             */
/*   Updated: 2022/08/12 17:47:47 by jbuny-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	destroy_imgs(t_mlbx *mlbx)
{
	mlx_destroy_image(mlbx->mlx, mlbx->walltree.img);
	mlx_destroy_image(mlbx->mlx, mlbx->player.img);
	mlx_destroy_image(mlbx->mlx, mlbx->path.img);
	mlx_destroy_image(mlbx->mlx, mlbx->coll.img);
	mlx_destroy_image(mlbx->mlx, mlbx->door.img);
}

int	ft_close(t_mlbx *mlbx)
{
	mlx_destroy_window(mlbx->mlx, mlbx->window);
	exit(0);
	return (0);
}

int	move_pl(t_mlbx *mlbx, int ver, int hor)
{
	if (mlbx->map.matrix[mlbx->player.y + ver][mlbx->player.x + hor] == 'E')
	{
		if (mlbx->coll_count == mlbx->map.collect)
			ft_close(mlbx);
		else
			return (0);
	}
	mlbx->map.matrix[mlbx->player.y][mlbx->player.x] = '0';
	mlbx->player.x += hor;
	mlbx->player.y += ver;
	if (mlbx->map.matrix[mlbx->player.y][mlbx->player.x] == 'C')
		mlbx->coll_count++;
	mlbx->map.matrix[mlbx->player.y][mlbx->player.x] = 'P';
	mlbx->moves++;
	ft_printf("Moves used: %d\n", mlbx->moves);
	destroy_imgs(mlbx);
	fill_map(mlbx);
	return (0);
}

static int	key_press(int keycode, t_mlbx *mlbx)
{
	if (keycode == ESC_KEY)
		ft_close(mlbx);
	else if (keycode == D_KEY
		&& mlbx->map.matrix[mlbx->player.y][mlbx->player.x + 1] != '1')
		move_pl(mlbx, 0, 1);
	else if (keycode == A_KEY
		&& mlbx->map.matrix[mlbx->player.y][mlbx->player.x - 1] != '1')
		move_pl(mlbx, 0, -1);
	else if (keycode == W_KEY
		&& mlbx->map.matrix[mlbx->player.y - 1][mlbx->player.x] != '1')
		move_pl(mlbx, -1, 0);
	else if (keycode == S_KEY
		&& mlbx->map.matrix[mlbx->player.y + 1][mlbx->player.x] != '1')
		move_pl(mlbx, 1, 0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_mlbx	mlbx;

	if (argc != 2)
		ft_error("This program requires exactly 1 map to work.\n");
	mlbx.map.matrix = read_map(argv[1], &mlbx.map);
	if (!mlbx.map.matrix)
		ft_error("Couldn't process the map.\n");
	if (!map_checks(&mlbx))
		ft_error("Poorly constructed map.\n");
	if (map_height(mlbx.map.matrix) > 8)
		ft_error("The map is too large for the screen.\n");
	mlbx.moves = 0;
	mlbx.coll_count = 0;
	mlbx.mlx = mlx_init();
	mlbx.win_wid = ft_strlen(mlbx.map.matrix[0]) * 128;
	mlbx.win_hei = map_height(mlbx.map.matrix) * 128;
	mlbx.window = mlx_new_window(mlbx.mlx, mlbx.win_wid, mlbx.win_hei,
			"ONIGIRI");
	fill_map(&mlbx);
	mlx_hook(mlbx.window, 17, 0, ft_close, &mlbx);
	mlx_hook(mlbx.window, 2, 1L << 0, key_press, &mlbx);
	mlx_loop(mlbx.mlx);
	free_mat(mlbx.map.matrix);
}
