/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_initialize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:41:59 by huolivei          #+#    #+#             */
/*   Updated: 2023/02/13 12:05:10 by huolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_so_long.h"

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
	game->en_mvs = NULL;
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
	if (str[i] != 'r' || str[i - 1] != 'e' || str[i - 2] != 'b'
		|| str[i - 3] != '.')
		return (0);
	return (1);
}

void	f_fill(t_data *game, char target, int row, int col)
{
	if (row < 0 || col < 0)
		return ;
	else if (game->map[row][col] == 'F' || game->map[row][col] == 'E'
		|| game->map[row][col] == '1' || game->map[row][col] == 'I')
		return ;
	else if (game->map[row][col] == 'C')
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
