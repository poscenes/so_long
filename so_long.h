/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poscenes <poscenes@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 10:39:58 by poscenes          #+#    #+#             */
/*   Updated: 2022/02/17 15:37:02 by poscenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define SPRITE 64

typedef struct s_map
{
	int		rows;
	int		cols;
	char	**map_arr;
}	t_map;

typedef struct s_sprite
{
	void	*wall;
	void	*floor;
	void	*collect;
	void	*exit_open;
	void	*exit_closed;
}	t_sprite;

typedef struct s_player
{
	int		r;
	int		c;
	void	*img;
}	t_player;

typedef struct s_data
{
	int			move_cnt;
	int			coll_cnt;
	int			score;
	int			exit_cnt;
	int			player_cnt;
	void		*mlx;
	void		*win;
	t_map		map;
	t_player 	player;
	t_sprite	sprite;
}	t_data;

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "minilibx-linux/mlx.h"
# include "gnl/get_next_line.h"

int		ft_printf(char *format, ...);
void	check_map_ext(char *path, char *ber);
void	rows_in_map(char *path, t_data *data);
int		validation_map(t_data *data);
int		end_game(char *err);
void	load_sprites(t_data *data);
void	clean(t_data *data);
void	read_map(char *path, t_data *data);
void	events_init(t_data *data);
int		draw(t_data *data);

#endif
