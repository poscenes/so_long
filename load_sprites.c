/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poscenes <poscenes@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 13:12:37 by poscenes          #+#    #+#             */
/*   Updated: 2022/02/17 16:34:56 by poscenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	load_t_sprite(t_data *data, int w, int h)
{
	data->sprite.collect = mlx_xpm_file_to_image(data->mlx,
	"images/collect.xpm", &w, &h);
	data->sprite.floor = mlx_xpm_file_to_image(data->mlx,
	"images/floor.xpm", &w, &h);
	data->sprite.wall = mlx_xpm_file_to_image(data->mlx,
	"images/wall.xpm", &w, &h);
	data->sprite.exit_closed = mlx_xpm_file_to_image(data->mlx,
	"images/door_c.xpm", &w, &h);
	data->sprite.exit_open = mlx_xpm_file_to_image(data->mlx,
	"images/door_o.xpm", &w, &h);
	if (!data->sprite.collect || !data->sprite.floor || !data->sprite.wall
	|| !data->sprite.exit_closed || !data->sprite.exit_open)
	{
		clean(data);
		end_game("Game sprites wasn't successfully loaded, check images");
	}
}

static void	load_player(t_data *data, int w, int h)
{
	data->player.img = mlx_xpm_file_to_image(data->mlx,
	"images/player.xpm", &w, &h);
	if (!data->player.img)
	{
		clean(data);
		end_game("Player sprite wasn't successfully loaded, check images");
	}
}

void	load_sprites(t_data *data)
{
	int	w;
	int	h;

	w = 0;
	h = 0;
	load_t_sprite(data, w, h);
	load_player(data, w, h);
}
