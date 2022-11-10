/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kristori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 14:29:22 by kristori          #+#    #+#             */
/*   Updated: 2022/10/26 14:22:28 by kristori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	comand(va_list list, const char *format, int i)
{
	int	print_len;

	print_len = 0;
	if (format[i + 1] == 'c')
		print_len += ft_putchar(va_arg(list, int));
	else if (format[i + 1] == 's')
		print_len += ft_printstr(va_arg(list, char *));
	else if (format[i + 1] == 'p')
		print_len += ft_printptr(va_arg(list, unsigned long long));
	else if (format[i + 1] == 'd')
		print_len += ft_putnbr(va_arg(list, int));
	else if (format[i + 1] == 'i')
		print_len += ft_putnbr(va_arg(list, int));
	else if (format[i + 1] == 'u')
		print_len += ft_print_unsigned_decimal(va_arg(list, unsigned int));
	else if (format[i + 1] == 'x' || format[i + 1] == 'X')
		print_len += ft_printhex(va_arg(list, int), format[i + 1]);
	else if (format[i + 1] == '%')
		print_len += ft_putchar('%');
	return (print_len);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		print_len;
	va_list	list;

	va_start(list, format);
	i = 0;
	print_len = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			print_len += comand(list, format, i);
			i++;
		}
		else
			print_len += ft_putchar(format[i]);
		i++;
	}
	va_end(list);
	return (print_len);
}
