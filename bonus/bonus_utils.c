/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huolivei <huolivei <marvin@42.fr>>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 10:35:41 by huolivei          #+#    #+#             */
/*   Updated: 2023/02/12 11:50:57 by huolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_so_long.h"

void	free_split(t_data *game)
{
	int	y;

	y = 0;
	while (y <= game->map_y)
	{
		free(game->map[y]);
		y++;
	}
	free(game->map);
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
