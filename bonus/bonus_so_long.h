/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_so_long.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 15:47:03 by huolivei          #+#    #+#             */
/*   Updated: 2023/02/13 12:07:43 by huolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_SO_LONG_H
# define BONUS_SO_LONG_H

# include "../libft/libft.h"
# include "../libft/get_next_line_bonus.h"
# include "../minilbx/mlx.h"
# include "../minilbx/mlx_int.h"
# include "../libft/ft_printf.h"
# include <stdlib.h>

typedef struct s_data
{
	char	*img;
	void	*mlx;
	void	*win;
	char	**map;
	int		player;
	int		map_x;
	int		map_y;
	int		colect;
	int		px;
	int		exit;
	int		pl_x;
	int		pl_y;
	int		pl_mvs;
	int		enemy;
	char	*en_mvs;
}		t_data;

void	move_right(t_data *game);
void	move_left(t_data *game);
void	move_up(t_data *game);
void	move_down(t_data *game);
int		press_key(int keycode, t_data *game);
void	put_objects(t_data *game);
void	put_player(t_data *game, int x, int y);
void	put_exit(t_data *game, int x, int y);
void	put_collect(t_data *game, int x, int y);
void	put_boundry(t_data *game, int x, int y);
void	put_floor(t_data *game, int x, int y);
void	destroy_win(t_data *game);
void	check_map(t_data *game);
void	exit_suc(char **str, int y, int x, t_data *game);
void	check_size(char *str, t_data *game);
void	read_map(char *str, t_data *game);
void	map_corr(t_data	*game);
void	put_enemy(t_data *game, int x, int y);
void	move_enemy(t_data	*game, int x, int y);
t_data	*game_init(t_data *game);
void	window_init(t_data *game);
int		check_input(char *str);
char	*ft_free(char *str, char *buf);
void	free_split(t_data *game);
void	flood_fill(t_data *game);
void	f_fill(t_data *game, char target, int row, int col);
void	check_path(t_data *game);
void	see_fs(t_data *game, int x, int y);
void	error_map(t_data *game);
void	put_enemy2(t_data *game, int x, int y);
int		not_wall_up(t_data *game);
int		not_wall_down(t_data *game);
int		not_wall_left(t_data *game);
int		not_wall_right(t_data *game);
int		sprite(t_data *game);
int		press_cross(t_data *game);

#endif
