/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_images.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huolivei <huolivei <marvin@42.fr>>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 12:11:15 by huolivei          #+#    #+#             */
/*   Updated: 2023/02/11 23:28:22 by huolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_so_long.h"

void	put_player(t_data *game, int x, int y)
{
	game->img = mlx_xpm_file_to_image(game->mlx, "./imgs/robocop.xpm",
			&game->px, &game->px);
	mlx_put_image_to_window(game->mlx, game->win, game->img,
		game->px * x, game->px * y);
	game->pl_x = x;
	game->pl_y = y;
	mlx_destroy_image(game->mlx, game->img);
}

void	put_exit(t_data *game, int x, int y)
{
	game->img = mlx_xpm_file_to_image(game->mlx, "./imgs/carro.xpm",
			&game->px, &game->px);
	mlx_put_image_to_window(game->mlx, game->win, game->img,
		game->px * x, game->px * y);
	mlx_destroy_image(game->mlx, game->img);
}

void	put_collect(t_data *game, int x, int y)
{
	game->img = mlx_xpm_file_to_image(game->mlx, "./imgs/chip.xpm",
			&game->px, &game->px);
	mlx_put_image_to_window(game->mlx, game->win, game->img,
		game->px * x, game->px * y);
	mlx_destroy_image(game->mlx, game->img);
}

void	put_boundry(t_data *game, int x, int y)
{
	game->img = mlx_xpm_file_to_image(game->mlx, "./imgs/fim.xpm",
			&game->px, &game->px);
	mlx_put_image_to_window(game->mlx, game->win, game->img,
		game->px * x, game->px * y);
	mlx_destroy_image(game->mlx, game->img);
}

void	put_floor(t_data *game, int x, int y)
{
	game->img = mlx_xpm_file_to_image(game->mlx, "./imgs/asphalt.xpm",
			&game->px, &game->px);
	mlx_put_image_to_window(game->mlx, game->win, game->img,
		(game->px * x), (game->px * y));
	mlx_destroy_image(game->mlx, game->img);
}
