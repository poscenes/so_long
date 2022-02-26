/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poscenes <poscenes@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 10:53:00 by poscenes          #+#    #+#             */
/*   Updated: 2022/02/25 13:55:09 by poscenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_map_ext(char *path, char *ber)
{
	char	*p;
	int		i;
	int		j;

	p = ft_strrchr(path, '.');
	i = 0;
	while (p[i])
	{
		j = 0;
		if (p[i + j] == ber[j])
		{
			while (p[i + j] || ber[j])
			{
				if (p[i + j] != ber[j])
					end_game("Incorrect extension, must be '.ber'!");
				j++;
			}
		}
		i++;
	}
}

static int	check_map_length(char *str, t_data *data)
{
	return ((int)ft_strlen(str) == data->map.cols);
}

void	rows_in_map(char *path, t_data *data)
{
	char	*str;
	int		fd;
	char	*tmp;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		end_game("Map doesn't open!");
	str = get_next_line(fd);
	if (!str)
		end_game("Map reading error");
	data->map.cols = ft_strlen(str);
	data->map.rows++;
	while (str)
	{
		tmp = str;
		str = get_next_line(fd);
		free(tmp);
		data->map.rows++;
	}
	close(fd);
}

static int	is_valid(char c, t_data *data, int r, int col)
{
	if (c == 'P')
	{
		data->player_cnt++;
		data->player.c = col;
		data->player.r = r;
		return (1);
	}
	else if (c == 'C')
	{
		data->coll_cnt++;
		return (1);
	}
	else if (c == 'E')
	{
		data->exit_cnt++;
		return (1);
	}
	else if (c == '1' || c == '0')
		return (1);
	return (0);
}

int	validation_map(t_data *data)
{
	int		r;
	int		c;

	r = 0;
	while (data->map.map_arr[r])
	{
		if (!check_map_length(data->map.map_arr[r], data))
			return (0);
		c = 0;
		while (data->map.map_arr[r][c])
		{
			if (!is_valid(data->map.map_arr[r][c], data, r, c))
				return (0);
			if (r == 0 || (r == data->map.rows - 1) || c == 0
				|| (c == data->map.cols - 1))
				if (data->map.map_arr[r][c] != '1')
					return (0);
			c++;
		}
		r++;
	}
	if (data->player_cnt > 1 || data->coll_cnt < 1 || data->exit_cnt < 1)
		return (0);
	return (1);
}
