/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poscenes <poscenes@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 10:39:58 by poscenes          #+#    #+#             */
/*   Updated: 2022/02/25 14:37:31 by poscenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

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
	char	dir;
	void	*img_l;
	void	*img_r;
}	t_player;

typedef struct s_enemy
{
	int				r;
	int				c;
	int				dir;
	int				anim;
	int				move;
	void			*current;
	void			*img_0;
	void			*img_1;
	void			*img_2;
	void			*img_3;
}	t_enemy;

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
	t_enemy		enemy;
}	t_data;

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "../minilibx-linux/mlx.h"
# include "../gnl/get_next_line.h"

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
char	*ft_itoa(int n);
int		ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strrchr(const char *s, int c);
int		enemy_place(t_data *data);
int		draw_enemy(t_data *data);
void	enemy_lose(t_data *data);
void	move(t_data *data);
void	enemy(t_data *data);

#endif
