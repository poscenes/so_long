/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poscenes <poscenes@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 16:43:27 by poscenes          #+#    #+#             */
/*   Updated: 2022/03/02 12:52:40 by poscenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	enemy(t_data *data)
{
	static int	basic_count;

	if (basic_count == data->sprite.enemy_anim)
		data->sprite.current = data->sprite.img_0;
	else if (basic_count == data->sprite.enemy_anim * 2)
		data->sprite.current = data->sprite.img_1;
	else if (basic_count == data->sprite.enemy_anim * 3)
		data->sprite.current = data->sprite.img_2;
	else if (basic_count > data->sprite.enemy_anim * 4)
	{
		data->sprite.current = data->sprite.img_3;
		basic_count = 0;
	}
	basic_count++;
}

static void	left(t_enemy *enem, t_data *data)
{
	if (data->map.map_arr[enem->r][enem->c - 1] == '0')
	{
		data->map.map_arr[enem->r][enem->c] = '0';
		data->map.map_arr[enem->r][enem->c - 1] = 'F';
	}
	else if (data->map.map_arr[enem->r][enem->c - 1] == '1'
			|| data->map.map_arr[enem->r][enem->c - 1] == 'C')
		enem->dir = 0;
	(enem->c)--;
}

static void	right(t_enemy *enem, t_data *data)
{
	if (data->map.map_arr[enem->r][enem->c + 1] == '0')
	{
		data->map.map_arr[enem->r][enem->c] = '0';
		data->map.map_arr[enem->r][enem->c + 1] = 'F';
	}
	else if (data->map.map_arr[enem->r][enem->c + 1] == '1'
			|| data->map.map_arr[enem->r][enem->c + 1] == 'C')
		enem->dir = 1;
	(enem->c)++;
}

void	move_enemy(t_data *data)
{
	t_enemy	*tmp;

	tmp = data->enemy;
	while (tmp)
	{
		if (tmp->dir == 0)
			right(tmp, data);
		else
			left(tmp, data);
		if (tmp->r == data->player.r && tmp->c == data->player.c)
		{
			ft_printf("YOU ARE DEFEATED! Score: %d\n", data->score);
			clean_en_lst(data);
			clean(data);
			end_game(NULL);
		}
		tmp = tmp->next;
	}
}
