/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huolivei <huolivei <marvin@42.fr>>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 22:17:49 by huolivei          #+#    #+#             */
/*   Updated: 2023/02/12 11:06:54 by huolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_so_long.h"

void	map_corr(t_data	*game)
{
	if (game->colect < 1 || game->exit != 1 || game->player != 1)
	{
		ft_printf("Error\n");
		error_map(game);
	}
}

void	check_map(t_data *game)
{
	int	x;
	int	y;

	x = -1;
	y = -1;
	while (++x < (game->map_x - 1))
		if (game->map[0][x] != '1' || game->map[game->map_y - 1][x] != '1')
			error_map(game);
	while (++y < (game->map_y - 1))
		if (game->map[y][0] != '1' || game->map[y][game->map_x - 1] != '1')
			error_map(game);
	if (game->map_x == game->map_y)
		error_map(game);
}

void	check_size(char *str, t_data *game)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'P')
			game->player++;
		else if (str[i] == 'C')
			game->colect++;
		else if (str[i] == 'E')
			game->exit++;
		else if (str[i] == 'I')
			game->enemy++;
		else if (str[i] == '\n' || str[i + 1] == '\0')
			game->map_y++;
		i++;
	}
}

char	*ft_free(char *str, char *buf)
{
	char	*tmp;

	tmp = ft_strjoin(str, buf);
	free(str);
	return (tmp);
}

void	read_map(char *str, t_data *game)
{
	int		fd;
	char	*buffer;
	char	*map;

	map = NULL;
	fd = open(str, O_RDONLY);
	while (1)
	{
		buffer = get_next_line(fd);
		if (buffer == NULL)
		{
			free(buffer);
			break ;
		}
		check_size(buffer, game);
		game->map_x = (ft_strlen(buffer) - 1);
		map = ft_free(map, buffer);
		free(buffer);
	}
	game->map = ft_split(map, '\n');
	map_corr(game);
	free (map);
	free (buffer);
	close(fd);
}
