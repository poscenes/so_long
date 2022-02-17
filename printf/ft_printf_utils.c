/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poscenes <poscenes@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 20:10:48 by poscenes          #+#    #+#             */
/*   Updated: 2021/12/17 17:56:41 by poscenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_format(char *fmt, va_list args)
{
	int	len;

	len = 0;
	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt++;
			len += parse_type(fmt, args);
		}
		else
		{
			write(1, fmt, 1);
			len++;
		}
		fmt++;
	}
	return (len);
}

int	parse_type(char *fmt, va_list args)
{
	if (*fmt == 'd' || *fmt == 'i')
		return (print_int(va_arg(args, int)));
	if (*fmt == 's')
		return (print_str(va_arg(args, char *)));
	if (*fmt == 'c')
		return (print_char((char)va_arg(args, int)));
	if (*fmt == 'u')
		return (print_u(va_arg(args, unsigned int)));
	if (*fmt == 'p')
		return (print_pointer(va_arg(args, void *)));
	if (*fmt == 'x')
		return (print_hex(va_arg(args, unsigned int), "0123456789abcdef"));
	if (*fmt == 'X')
		return (print_hex(va_arg(args, unsigned int), "0123456789ABCDEF"));
	if (*fmt == '%')
		return (print_char('%'));
	else
		return (0);
	return (0);
}
