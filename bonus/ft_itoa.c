/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poscenes <poscenes@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 17:06:54 by poscenes          #+#    #+#             */
/*   Updated: 2022/02/21 16:28:39 by poscenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	num_len(int n)
{
	int	res;

	res = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		res++;
	while (n != 0)
	{
		res++;
		n /= 10;
	}
	return (res);
}

static char	*reverse(char *s)
{
	char	tmp;
	char	*src;
	char	*dst;
	size_t	j;

	if (s)
	{
		j = ft_strlen(s);
		src = s;
		dst = s + j - 1;
		while (src < dst)
		{
			tmp = *src;
			*src++ = *dst;
			*dst-- = tmp;
		}
	}
	return (s);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		i;

	res = malloc(sizeof(char) * (num_len(n) + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (n)
	{
		res[i++] = (n % 10) + '0';
		n /= 10;
	}
	res[i] = '\0';
	return (reverse(res));
}
