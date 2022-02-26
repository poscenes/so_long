/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poscenes <poscenes@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 11:25:47 by poscenes          #+#    #+#             */
/*   Updated: 2022/02/26 16:08:45 by poscenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	enemy_lose(t_data *data)
{
	clean(data);
	ft_printf("YOU LOSE.");
	end_game(NULL);
}

static t_enemy	*new_enemy(t_data *data, int r, int c)
{
	t_enemy	*enem;

	enem = malloc(sizeof(t_enemy));
	if (!enem)
	{
		clean(data);
		end_game("Enemy alloc error.");
	}
	enem->r = r;
	enem->c = c;
	enem->dir = 0;
	enem->next = NULL;
	return (enem);
}

void	add_enem(t_data *data, int r, int c)
{
	t_enemy	*enem;

	enem = new_enemy(data, r, c);
	if (!enem)
	{
		clean(data);
		end_game("Enemy alloc error.");
	}
	enem->next = data->enemy;
	data->enemy = enem;
}
