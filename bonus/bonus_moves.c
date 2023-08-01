/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 11:56:15 by huolivei          #+#    #+#             */
/*   Updated: 2023/02/13 12:08:48 by huolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_so_long.h"

void	move_right(t_data *game)
{
	game->en_mvs = ft_itoa(game->pl_mvs++);
	if (game->map[game->pl_y][game->pl_x + 1] == 'C')
		game->colect--;
	else if (game->map[game->pl_y][game->pl_x + 1] == 'I')
	{
		free(game->en_mvs);
		destroy_win(game);
	}
	exit_suc(game->map, game->pl_y, (game->pl_x + 1), game);
	game->map[game->pl_y][game->pl_x] = '0';
	game->map[game->pl_y][game->pl_x + 1] = 'P';
	put_objects(game);
	mlx_string_put(game->mlx, game->win, 25, 25, 0, game->en_mvs);
	free(game->en_mvs);
}

void	move_left(t_data *game)
{
	game->en_mvs = ft_itoa(game->pl_mvs++);
	if (game->map[game->pl_y][game->pl_x - 1] == 'C')
		game->colect--;
	else if (game->map[game->pl_y][game->pl_x - 1] == 'I')
	{
		free(game->en_mvs);
		destroy_win(game);
	}
	exit_suc(game->map, game->pl_y, (game->pl_x - 1), game);
	game->map[game->pl_y][game->pl_x] = '0';
	game->map[game->pl_y][game->pl_x - 1] = 'P';
	put_objects(game);
	mlx_string_put(game->mlx, game->win, 25, 25, 0, game->en_mvs);
	free(game->en_mvs);
}

void	move_down(t_data *game)
{
	game->en_mvs = ft_itoa(game->pl_mvs++);
	if (game->map[game->pl_y + 1][game->pl_x] == 'C')
		game->colect--;
	else if (game->map[game->pl_y + 1][game->pl_x] == 'I')
	{
		free(game->en_mvs);
		destroy_win(game);
	}
	exit_suc(game->map, (game->pl_y + 1), game->pl_x, game);
	game->map[game->pl_y][game->pl_x] = '0';
	game->map[game->pl_y + 1][game->pl_x] = 'P';
	put_objects(game);
	mlx_string_put(game->mlx, game->win, 25, 25, 0, game->en_mvs);
	free(game->en_mvs);
}

void	move_up(t_data *game)
{
	game->en_mvs = ft_itoa(game->pl_mvs++);
	if (game->map[game->pl_y - 1][game->pl_x] == 'C')
		game->colect--;
	else if (game->map[game->pl_y - 1][game->pl_x] == 'I')
	{
		free(game->en_mvs);
		destroy_win(game);
	}
	exit_suc(game->map, (game->pl_y - 1), game->pl_x, game);
	game->map[game->pl_y][game->pl_x] = '0';
	game->map[game->pl_y - 1][game->pl_x] = 'P';
	put_objects(game);
	mlx_string_put(game->mlx, game->win, 25, 25, 0, game->en_mvs);
	free(game->en_mvs);
}

int	press_key(int keycode, t_data *game)
{
	if ((keycode == 119 || keycode == 65362) && not_wall_up(game))
		move_up(game);
	else if ((keycode == 115 || keycode == 65364) && not_wall_down(game))
		move_down(game);
	else if ((keycode == 97 || keycode == 65361) && not_wall_left(game))
		move_left(game);
	else if ((keycode == 100 || keycode == 65363) && not_wall_right(game))
		move_right(game);
	else if (keycode == 65307)
		destroy_win(game);
	return (0);
}
