/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poscenes <poscenes@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 11:51:02 by poscenes          #+#    #+#             */
/*   Updated: 2022/02/17 16:34:21 by poscenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_init(t_data *data)
{
	data->map.rows = 0;
	data->map.cols = 0;
	data->mlx = mlx_init();
}

void	window(t_data *data)
{
	data->win = mlx_new_window(data->mlx, data->map.cols * SPRITE,
			(data->map.rows - 1) * SPRITE, "so_long");
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 2)
	{
		game_init(&data);
		read_map(argv[1], &data);
		load_sprites(&data);
		window(&data);
		events_init(&data);
		mlx_loop(data.mlx);
	}
	else
		end_game("Usage: ./so_long *YOUR_MAP*.ber");
}
