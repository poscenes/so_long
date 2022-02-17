/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poscenes <poscenes@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 20:11:15 by poscenes          #+#    #+#             */
/*   Updated: 2021/12/23 16:45:30 by poscenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	numlen_hex(unsigned long n)
{
	int	cnt;

	cnt = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 16;
		cnt++;
	}
	return (cnt);
}

int	print_hex(unsigned long n, char *digits)
{
	int		numlen;
	char	a[20];
	int		i;

	i = 0;
	numlen = numlen_hex(n);
	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	while (n)
	{
		a[i] = digits[n % 16];
		n /= 16;
		i++;
	}
	while (--i >= 0)
		print_char(a[i]);
	return (numlen);
}

int	print_pointer(void *p)
{
	unsigned long	n;

	n = (unsigned long)p;
	write(1, "0x", 2);
	return (print_hex(n, "0123456789abcdef") + 2);
}
