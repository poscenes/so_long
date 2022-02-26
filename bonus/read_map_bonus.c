/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poscenes <poscenes@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 10:39:41 by poscenes          #+#    #+#             */
/*   Updated: 2022/02/25 13:55:28 by poscenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	form_map_arr(int fd, t_data *data)
{
	char	*str;
	int		i;

	data->map.map_arr = malloc(sizeof(char *) * (data->map.rows + 1));
	if (!(data->map.map_arr))
		end_game("Map allocation error");
	str = get_next_line(fd);
	if (!str)
		end_game("Map reading error");
	i = 0;
	while (str)
	{
		data->map.map_arr[i] = str;
		data->map.map_arr[i + 1] = NULL;
		str = get_next_line(fd);
		i++;
	}
}

void	read_map(char *path, t_data *data)
{
	int		fd;

	check_map_ext(path, ".ber");
	rows_in_map(path, data);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		end_game("Map doesn't open");
	form_map_arr(fd, data);
	if (!validation_map(data))
	{
		clean(data);
		end_game("Map validation error");
	}
	close(fd);
}
