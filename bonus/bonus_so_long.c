/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_so_long.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huolivei <huolivei <marvin@42.fr>>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 12:03:28 by huolivei          #+#    #+#             */
/*   Updated: 2023/02/12 11:06:31 by huolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_so_long.h"

void	error_map(t_data *game)
{
	ft_printf("Error\n");
	free_split(game);
	free(game);
	exit(1);
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
			else if (game->map[y][x] == '0'
				|| (game->map[y][x] == 'E' && game->colect > 0))
				put_floor(game, x, y);
			else if (game->map[y][x] == 'I')
				put_enemy(game, x, y);
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
	mlx_loop_hook(game->mlx, sprite, game);
	mlx_loop(game->mlx);
}
