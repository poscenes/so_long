/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poscenes <poscenes@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 17:06:11 by poscenes          #+#    #+#             */
/*   Updated: 2022/02/15 13:10:21 by poscenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		++i;
	return (i);
}

int	check_endl(char *str)
{
	size_t	i;

	if (!str)
		return (1);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	size_t	s1_size;
	size_t	s2_size;
	int		i;

	if (!s2)
		return (NULL);
	if (!s1)
	{
		s1 = (char *)malloc(1);
		s1[0] = '\0';
	}
	s1_size = ft_strlen(s1);
	s2_size = ft_strlen(s2);
	res = malloc(sizeof(char) * (s1_size + s2_size + 1));
	if (!res)
		return (NULL);
	i = -1;
	while (s1[++i])
		res[i] = s1[i];
	while (*s2)
		res[i++] = *s2++;
	res[i] = '\0';
	free(s1);
	return (res);
}

char	*get_line(char *str)
{
	char	*line;
	int		i;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*get_remain(char *str)
{
	char	*rmn;
	int		i;
	int		j;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	rmn = malloc(sizeof(char) * (ft_strlen(str) - i + 2));
	if (!rmn)
		return (NULL);
	i++;
	j = 0;
	while (str[i])
		rmn[j++] = str[i++];
	rmn[j] = '\0';
	free(str);
	return (rmn);
}
