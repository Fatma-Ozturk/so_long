/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faozturk <faozturk@42kocaeli.tr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 13:15:35 by faozturk          #+#    #+#             */
/*   Updated: 2022/04/26 14:33:21 by faozturk         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libraries/minilibx/mlx.h"
# include "../libraries/libft/libft.h"
# include <stdio.h>
# include <fcntl.h>

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	void	*img_backg;
	void	*img_wall;
	void	*img_player;
	void	*img_collect;
	void	*img_exit;
	int		map_w;
	int		map_h;
	int		img_w;
	int		img_h;
	int		n_collect;
	int		n_player;
	int		n_exit;
	int		x_player; // playerın x eksenindeki konumu
	int		y_player; // playerın y eksenindeki konumu
	int		moves;
	int		endgame;
}	t_game;

# define KEY_ESC 53
# define KEY_Q 12

# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2

void	img_draw(t_game *game, void *image, int x, int y);
int		map_draw(t_game *game);
void	game_init(t_game *game);
char	**read_map(char *path);
int		map_checker(t_game *game);
void	gameplay(t_game *game);
void	player_w(t_game *game);
void	player_d(t_game *game);
void	player_s(t_game *game);
void	player_a(t_game *game);
int		exit_game(t_game *game);
void	free_map(char **map);

#endif
