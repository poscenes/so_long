/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poscenes <poscenes@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 21:32:19 by poscenes          #+#    #+#             */
/*   Updated: 2022/02/17 12:03:50 by poscenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	end_game(char *err)
{
	if (err)
	{
		ft_printf("ERROR\n%s\n", err);
		exit(1);
	}
	exit(0);
}

void	clean(t_data *data)
{
	int	i;

	i = 0;
	while(data->map.map_arr[i])
		free(data->map.map_arr[i++]);
	free(data->map.map_arr);
}
