/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huolivei <huolivei <marvin@42.fr>>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:39:21 by huolivei          #+#    #+#             */
/*   Updated: 2023/02/12 11:17:24 by huolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_data	*game_init(t_data *game)
{
	game->player = 0;
	game->colect = 0;
	game->map_x = 0;
	game->map_y = 0;
	game->exit = 0;
	game->pl_x = 0;
	game->pl_y = 0;
	game->pl_mvs = 1;
	game->map = NULL;
	return (game);
}

void	window_init(t_data *game)
{
	game->px = 40;
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, (game->px * game->map_x),
			(game->px * game->map_y), "So Long!");
	put_objects(game);
}

int	check_input(char *str)
{
	int	i;

	i = ft_strlen(str);
	i--;
	if (str[i] != 'r' || str[i - 1] != 'e'
		|| str[i - 2] != 'b' || str[i - 3] != '.')
		return (0);
	return (1);
}
