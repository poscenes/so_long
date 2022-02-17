/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poscenes <poscenes@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 20:11:18 by poscenes          #+#    #+#             */
/*   Updated: 2021/12/23 16:45:54 by poscenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	int_checker(int n)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	return (0);
}

int	print_int(int n)
{
	char	a[10];
	int		i;
	int		len;

	if (n == -2147483648 || n == 0)
		return (int_checker(n));
	len = 0;
	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
		len++;
	}
	i = 0;
	while (n > 0)
	{
		a[i] = n % 10 + '0';
		n /= 10;
		i++;
	}
	while (--i >= 0)
		len += print_char(a[i]);
	return (len);
}

int	print_u(unsigned int n)
{
	char	a[10];
	int		i;
	int		len;

	i = 0;
	len = 0;
	if (n == 0)
		return (int_checker(n));
	while (n > 0)
	{
		a[i] = n % 10 + '0';
		n /= 10;
		i++;
	}
	while (--i >= 0)
		len += print_char(a[i]);
	return (len);
}

int	print_str(char *str)
{
	int	i;

	if (!str)
	{
		print_str("(null)");
		return (6);
	}
	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
	return (i);
}

int	print_char(char c)
{
	return (write(1, &c, 1));
}
