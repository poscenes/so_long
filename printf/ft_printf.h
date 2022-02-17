/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poscenes <poscenes@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 20:10:10 by poscenes          #+#    #+#             */
/*   Updated: 2021/12/17 17:56:25 by poscenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	print_format(char *fmt, va_list args);
int	parse_type(char *fmt, va_list args);
int	print_int(int n);
int	print_str(char *str);
int	print_char(char c);
int	print_u(unsigned int n);
int	print_hex(unsigned long n, char *digits);
int	print_pointer(void *p);

#endif
