/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_parts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 14:52:51 by huolivei          #+#    #+#             */
/*   Updated: 2023/02/13 12:18:48 by huolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_so_long.h"

void	put_enemy(t_data *game, int x, int y)
{
	game->img = mlx_xpm_file_to_image(game->mlx, "./imgs/enemy.xpm",
			&game->px, &game->px);
	mlx_put_image_to_window(game->mlx, game->win, game->img,
		game->px * x, game->px * y);
	mlx_destroy_image(game->mlx, game->img);
}

void	put_enemy2(t_data *game, int x, int y)
{
	game->img = mlx_xpm_file_to_image(game->mlx, "./imgs/enemy1.xpm",
			&game->px, &game->px);
	mlx_put_image_to_window(game->mlx, game->win, game->img,
		game->px * x, game->px * y);
	mlx_destroy_image(game->mlx, game->img);
}

void	see_fs(t_data *game, int x, int y)
{
	if (game->map[y - 1][x] == 'F' || game->map[y + 1][x] == 'F'
		|| game->map[y][x - 1] == 'F' || game->map[y][x + 1] == 'F')
		return ;
	ft_printf("Error, Can't collect or get to the exit!\n");
	destroy_win(game);
}

void	check_path(t_data *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < game->map_y)
	{
		x = 0;
		while (x < game->map_x)
		{
			if (game->map[y][x] == 'C')
				see_fs(game, x, y);
			else if (game->map[y][x] == 'E')
				see_fs(game, x, y);
			x++;
		}
		y++;
	}
}

int	sprite(t_data *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map_y)
	{
		x = 0;
		while (x <= game->map_x)
		{
			if (game->map[y][x] == 'I')
			{
				put_enemy(game, x, y);
				usleep(30000);
				put_enemy2(game, x, y);
			}
			x++;
		}
		y++;
	}
	return (0);
}
