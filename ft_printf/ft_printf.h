/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kristori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 15:06:12 by kristori          #+#    #+#             */
/*   Updated: 2022/11/08 10:35:21 by kristori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>

int		ft_printf(const char *format, ...);
int		ft_putchar(char c);
int		ft_printstr(char *str);
int		ft_printstr_nbr(char *str);
int		ft_putnbr(int nb);
int		ft_print_unsigned_decimal(unsigned int nb);
int		ft_printhex(unsigned int nb, const char format);
int		ft_printptr(unsigned long long ptr);

#endif
