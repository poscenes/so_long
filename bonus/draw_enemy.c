/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poscenes <poscenes@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 16:43:27 by poscenes          #+#    #+#             */
/*   Updated: 2022/02/25 15:57:00 by poscenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	enemy(t_data *data)
{
	static int	basic_count;

	if (basic_count == data->enemy.anim)
		data->enemy.current = data->enemy.img_0;
	else if (basic_count == data->enemy.anim * 2)
		data->enemy.current = data->enemy.img_1;
	else if (basic_count == data->enemy.anim * 3)
		data->enemy.current = data->enemy.img_2;
	else if (basic_count > data->enemy.anim * 4)
	{
		data->enemy.current = data->enemy.img_3;
		basic_count = 0;
	}
	basic_count++;
}

static void	left(t_data *data, int r, int c)
{
	if (data->map.map_arr[r][c - 1] == '0')
	{
		data->map.map_arr[r][c] = '0';
		data->map.map_arr[r][c - 1] = 'F';
	}
	if (data->map.map_arr[r][c - 1] == '1' || data->map.map_arr[r][c - 1] == 'C')
		data->enemy.dir = 0;
}

static void	right(t_data *data, int r, int c)
{
	if (data->map.map_arr[r][c + 1] == '0')
	{
		data->map.map_arr[r][c] = '0';
		data->map.map_arr[r][c + 1] = 'F';
	}
	if (data->map.map_arr[r][c + 1] == '1' || data->map.map_arr[r][c + 1] == 'C')
		data->enemy.dir = 1;
}

static void	move_enemy(t_data *data, int r, int c)
{
	if (data->enemy.dir == 0)
		right(data, r, c);
	if (data->enemy.dir == 1)
		left(data, r, c);
}

int	draw_enemy(t_data *data)
{
	int	r;
	int	c;

	r = 0;
	while (r < data->map.rows - 1)
	{
		c = 0;
		while (c < data->map.cols)
		{
			if (data->map.map_arr[r][c] == 'F')
			{
				move_enemy(data, r, c);
				r++;
			}
			c++;
		}
		r++;
	}
	data->enemy.move++;
	return (0);
}
