/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poscenes <poscenes@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 11:50:29 by poscenes          #+#    #+#             */
/*   Updated: 2022/02/25 14:37:14 by poscenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	walls(t_data *data)
{
	int	c;
	int	r;

	r = 0;
	while (r < data->map.rows - 1)
	{
		c = 0;
		while (c < data->map.cols)
		{
			if (data->map.map_arr[r][c] == '1')
				mlx_put_image_to_window(data->mlx, data->win,
					data->sprite.wall, c * SPRITE, r * SPRITE);
			else if (data->map.map_arr[r][c] == '0'
					|| data->map.map_arr[r][c] == 'P')
				mlx_put_image_to_window(data->mlx, data->win,
					data->sprite.floor, c * SPRITE, r * SPRITE);
			c++;
		}
		r++;
	}
}

static void	game_exit(t_data *data)
{
	int	c;
	int	r;

	r = 0;
	while (r < data->map.rows - 1)
	{
		c = 0;
		while (c < data->map.cols)
		{
			if (data->map.map_arr[r][c] == 'E' && data->coll_cnt == 0)
				mlx_put_image_to_window(data->mlx, data->win,
					data->sprite.exit_open, c * SPRITE, r * SPRITE);
			else if (data->map.map_arr[r][c] == 'E')
				mlx_put_image_to_window(data->mlx, data->win,
					data->sprite.exit_closed, c * SPRITE, r * SPRITE);
			c++;
		}
		r++;
	}
}

static void	collectable(t_data *data)
{
	int	c;
	int	r;

	r = 0;
	while (r < data->map.rows - 1)
	{
		c = 0;
		while (c < data->map.cols)
		{
			if (data->map.map_arr[r][c] == 'C')
				mlx_put_image_to_window(data->mlx, data->win,
					data->sprite.collect, c * SPRITE, r * SPRITE);
			if (data->map.map_arr[r][c] == 'F')
				mlx_put_image_to_window(data->mlx, data->win,
					data->enemy.current, c * SPRITE, r * SPRITE);
			c++;
		}
		r++;
	}
}

static void	player(t_data *data)
{
	int	c;
	int	r;

	r = 0;
	while (r < data->map.rows - 1)
	{
		c = 0;
		while (c < data->map.cols)
		{
			if (data->map.map_arr[r][c] == 'P' && data->player.dir == 'r')
			{
				mlx_put_image_to_window(data->mlx, data->win,
					data->player.img_r, data->player.c * SPRITE,
					data->player.r * SPRITE);
			}
			else if (data->map.map_arr[r][c] == 'P' && data->player.dir == 'l')
			{
				mlx_put_image_to_window(data->mlx, data->win,
					data->player.img_l, data->player.c * SPRITE,
					data->player.r * SPRITE);
			}
			c++;
		}
		r++;
	}
}

int	draw(t_data *data)
{
	char *str;

	walls(data);
	game_exit(data);
	collectable(data);
	player(data);
	enemy(data);
	if (data->enemy.move == 196)
	{
		data->enemy.move = 0;
		draw_enemy(data);
	}
	data->enemy.move++;
	str = ft_itoa(data->move_cnt);
	mlx_string_put(data->mlx, data->win, data->player.c * SPRITE,
		data->player.r * SPRITE, 0xffffff, str);
	free(str);
	return (0);
}
