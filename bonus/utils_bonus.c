/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poscenes <poscenes@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 21:32:19 by poscenes          #+#    #+#             */
/*   Updated: 2022/03/02 13:09:10 by poscenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
	int		i;

	i = 0;
	while (data->map.map_arr[i])
		free(data->map.map_arr[i++]);
	free(data->map.map_arr);
}

void	clean_en_lst(t_data *data)
{
	t_enemy	*tmp;

	while (data->enemy)
	{
		tmp = data->enemy->next;
		free(data->enemy);
		data->enemy = tmp;
	}
}

int	ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (haystack[i] && i < len)
	{
		if (haystack[i] == needle[0])
		{
			j = 0;
			while (needle[j] && i + j < len)
			{
				if (haystack[i + j] != needle[j])
					break ;
				j++;
				if (needle[j] == '\0')
					return (1);
			}
		}
		i++;
	}
	return (0);
}

char	*ft_strrchr(const char *s, int c)
{
	char	*s1;

	s1 = (void *)0;
	while (*s)
	{
		if (*s == (char)c)
			s1 = (char *)s;
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (s1);
}
