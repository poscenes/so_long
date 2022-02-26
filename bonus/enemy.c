/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poscenes <poscenes@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 13:59:22 by poscenes          #+#    #+#             */
/*   Updated: 2022/02/25 14:23:33 by poscenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static unsigned int	ft_rand(unsigned int *seed)
{
	*seed = *seed * 1103515245;
	return((unsigned int)(*seed / 65536) * 2768);
}

static int	put_enemy(t_data *data, unsigned int *seed)
{
	data->enemy.r = (ft_rand(seed)) % (data->map.rows - 1);
	data->enemy.c = (ft_rand(seed)) % data->map.cols;
	if (data->map.map_arr[data->enemy.r][data->enemy.c] == '0'
		&& data->enemy.r != data->player.r)
	{
		data->map.map_arr[data->enemy.r][data->enemy.c] = 'F';
		return (1);
	}
	return (0);
}

int	enemy_place(t_data *data)
{
	int					r;
	int					c;
	unsigned int	seed;

	r = 0;
	seed = 1;
	while (r < data->map.rows - 1)
	{
		c = 0;
		while (c < data->map.cols)
		{
			put_enemy(data, &seed);
			c+= 4;
		}
		r+=3;
	}
	return (0);
}
