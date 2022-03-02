/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poscenes <poscenes@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 12:54:42 by poscenes          #+#    #+#             */
/*   Updated: 2022/02/27 11:52:44 by poscenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
		if (data->map.map_arr[r][c] == 'E')
		{
			if (data->coll_cnt == 0)
			{
				ft_printf("Congratulations! You won this game! SCORE: %d\n",
					data->score);
				mlx_loop_end(data->mlx);
				return (1);
			}
		}
		ft_printf("Moves: %d\n", data->move_cnt++);
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
	if (keycode == 65307)
	{
		mlx_destroy_window(data->mlx, data->win);
		clean(data);
		end_game(NULL);
	}
	if (keycode == 119)
		if (check_action(data, data->player.r - 1, data->player.c))
			data->player.r -= 1;
	if (keycode == 97)
		if (check_action(data, data->player.r, data->player.c - 1))
			player_dir('l', data);
	if (keycode == 115)
		if (check_action(data, data->player.r + 1, data->player.c))
			data->player.r += 1;
	if (keycode == 100)
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
