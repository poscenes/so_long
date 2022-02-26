/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poscenes <poscenes@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 12:54:42 by poscenes          #+#    #+#             */
/*   Updated: 2022/02/26 13:26:53 by poscenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	check_action(t_data *data, int r, int c)
{
	if (data->map.map_arr[r][c] != '1')
	{
		if (data->map.map_arr[r][c] == 'C')
		{
			data->score++;
			data->coll_cnt--;
			data->map.map_arr[r][c] = '0';
		}
		if (data->map.map_arr[r][c] == 'F')
			enemy_lose(data);
		if (data->map.map_arr[r][c] == 'E')
		{
			if (data->coll_cnt == 0)
			{
				ft_printf("Congratulations! You won this game! SCORE: %d\n",
					data->score);
				end_game(NULL);
				//mlx_loop_end(data->mlx);
				return (1);
			}
		}
		data->move_cnt++;
		return (1);
	}
	return (0);
}

static void	player_dir(char c, t_data *data)
{
	if (c == 'l')
	{
		data->player.dir = 'l';
		data->player.c -= 1;
	}
	else if (c == 'r')
	{
		data->player.dir = 'r';
		data->player.c += 1;
	}
}

static int	key_hook(int keycode, t_data *data)
{
	if (keycode == 53)
	{
		mlx_destroy_window(data->mlx, data->win);
		clean(data);
		end_game(NULL);
	}
	if (keycode == 13)
		if (check_action(data, data->player.r - 1, data->player.c))
			data->player.r -= 1;
	if (keycode == 0)
		if (check_action(data, data->player.r, data->player.c - 1))
			player_dir('l', data);
	if (keycode == 1)
		if (check_action(data, data->player.r + 1, data->player.c))
			data->player.r += 1;
	if (keycode == 2)
		if (check_action(data, data->player.r, data->player.c + 1))
			player_dir('r', data);
	mlx_clear_window(data->mlx, data->win);
	draw(data);
	return (0);
}

void	events_init(t_data *data)
{
	mlx_key_hook(data->win, key_hook, data);
	mlx_hook(data->win, 17, 0, end_game, NULL);
	mlx_hook(data->win, 12, 0, draw, data);
}
