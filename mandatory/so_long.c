/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huolivei <huolivei <marvin@42.fr>>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 12:03:28 by huolivei          #+#    #+#             */
/*   Updated: 2023/02/12 11:55:09 by huolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_map(t_data *game)
{
	ft_printf("Error\n");
	if (game->map)
		free_split(game);
	free(game);
	exit(1);
}

void	see_fs(t_data *game, int x, int y)
{
	if (game->map[y - 1][x] == 'F' || game->map[y + 1][x] == 'F'
		|| game->map[y][x - 1] == 'F' || game->map[y][x + 1] == 'F')
		return ;
	ft_printf("Error\n Can't collect or get to the exit!\n");
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

void	put_objects(t_data *game)
{
	int	y;
	int	x;

	y = -1;
	while (++y < game->map_y)
	{
		x = -1;
		while (++x <= game->map_x)
		{
			if (game->map[y][x] == '1')
				put_boundry(game, x, y);
			else if (game->map[y][x] == 'C')
				put_collect(game, x, y);
			else if (game->map[y][x] == 'E' && game->colect == 0)
				put_exit(game, x, y);
			else if (game->map[y][x] == 'P')
				put_player(game, x, y);
			else if (game->map[y][x] == '0' ||
					(game->map[y][x] == 'E' && game->colect > 0))
				put_floor(game, x, y);
		}
	}
}

int	main(int ac, char **av)
{
	t_data	*game;

	if (ac < 2)
		return (0);
	if (!(check_input(av[1])))
	{
		ft_printf("Error\nYou got the wrong map!\n");
		exit(1);
	}
	game = malloc(sizeof(t_data));
	game = game_init(game);
	read_map(av[1], game);
	check_map(game);
	window_init(game);
	flood_fill(game);
	check_path(game);
	mlx_hook(game->win, 2, 1L << 0, press_key, game);
	mlx_hook(game->win, 17, 1L << 0, press_cross, game);
	mlx_loop(game->mlx);
}
