/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huolivei <huolivei <marvin@42.fr>>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 10:45:11 by huolivei          #+#    #+#             */
/*   Updated: 2023/02/12 11:04:49 by huolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	not_wall_up(t_data *game)
{
	if (game->map[game->pl_y - 1][game->pl_x] != '1'
		&& game->map[game->pl_y - 1][game->pl_x] == 'E' && game->colect == 0)
		return (1);
	else if (game->map[game->pl_y - 1][game->pl_x] != '1'
		&& game->map[game->pl_y - 1][game->pl_x] != 'E')
		return (1);
	return (0);
}

int	not_wall_down(t_data *game)
{
	if (game->map[game->pl_y + 1][game->pl_x] != '1'
		&& game->map[game->pl_y + 1][game->pl_x] == 'E' && game->colect == 0)
		return (1);
	else if (game->map[game->pl_y + 1][game->pl_x] != '1'
		&& game->map[game->pl_y + 1][game->pl_x] != 'E')
		return (1);
	return (0);
}

int	not_wall_left(t_data *game)
{
	if (game->map[game->pl_y][game->pl_x - 1] != '1'
		&& game->map[game->pl_y][game->pl_x - 1] == 'E' && game->colect == 0)
		return (1);
	else if (game->map[game->pl_y][game->pl_x - 1] != '1'
		&& game->map[game->pl_y][game->pl_x - 1] != 'E')
		return (1);
	return (0);
}

int	not_wall_right(t_data *game)
{
	if (game->map[game->pl_y][game->pl_x + 1] != '1'
		&& game->map[game->pl_y][game->pl_x + 1] == 'E' && game->colect == 0)
		return (1);
	else if (game->map[game->pl_y][game->pl_x + 1] != '1'
		&& game->map[game->pl_y][game->pl_x + 1] != 'E')
		return (1);
	return (0);
}

void	exit_suc(char **str, int y, int x, t_data *game)
{
	if (str[y][x] == 'E' && game->colect == 0)
	{
		ft_printf("Thank you for playing :)\n");
		destroy_win(game);
	}
}
