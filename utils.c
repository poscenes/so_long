/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poscenes <poscenes@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 21:32:19 by poscenes          #+#    #+#             */
/*   Updated: 2022/02/21 18:35:37 by poscenes         ###   ########.fr       */
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
	while (data->map.map_arr[i])
		free(data->map.map_arr[i++]);
	free(data->map.map_arr);
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
