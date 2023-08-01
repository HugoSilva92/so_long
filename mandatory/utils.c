/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huolivei <huolivei <marvin@42.fr>>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 11:10:06 by huolivei          #+#    #+#             */
/*   Updated: 2023/02/12 11:50:28 by huolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	f_fill(t_data *game, char target, int row, int col)
{
	if (row < 0 || col < 0)
		return ;
	if (game->map[row][col] == 'F' || game->map[row][col] == 'E'
		|| game->map[row][col] == '1')
		return ;
	if (game->map[row][col] == 'C')
		game->map[row][col] = 'C';
	else
		game->map[row][col] = 'F';
	f_fill(game, target, row +1, col);
	f_fill(game, target, row -1, col);
	f_fill(game, target, row, col - 1);
	f_fill(game, target, row, col + 1);
}

void	flood_fill(t_data *game)
{
	char	target;

	target = '0';
	f_fill(game, target, game->pl_y, game->pl_x);
}

void	free_split(t_data *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y <= game->map_y)
	{
		free(game->map[y]);
		y++;
	}
	free (game->map);
}

int	press_cross(t_data *game)
{
	destroy_win(game);
	return (0);
}

void	destroy_win(t_data *game)
{
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free_split(game);
	free(game->mlx);
	free(game);
	exit(0);
}
