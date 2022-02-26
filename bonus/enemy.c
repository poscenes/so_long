/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poscenes <poscenes@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 13:59:22 by poscenes          #+#    #+#             */
/*   Updated: 2022/02/26 16:52:55 by poscenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	enemy_place(t_data *data)
{
	int					r;
	int					c;

	r = 0;
	while (r < data->map.rows - 1)
	{
		c = 0;
		while (c < data->map.cols)
		{
			if (data->map.map_arr[r][c] == 'F')
				add_enem(data, r, c);
			c++;
		}
		r++;
	}
	return (0);
}
