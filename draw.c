/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poscenes <poscenes@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 11:50:29 by poscenes          #+#    #+#             */
/*   Updated: 2022/02/17 16:42:57 by poscenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
			if (data->map.map_arr[r][c] == 'P')
			{
				mlx_put_image_to_window(data->mlx, data->win,
					data->player.img, data->player.c * SPRITE,
					data->player.r * SPRITE);
			}
			c++;
		}
		r++;
	}
}

int	draw(t_data *data)
{
	walls(data);
	game_exit(data);
	collectable(data);
	player(data);
	return (0);
}
