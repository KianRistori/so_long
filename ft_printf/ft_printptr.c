/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kristori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 11:33:42 by kristori          #+#    #+#             */
/*   Updated: 2022/10/27 15:40:59 by kristori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_ptrlen(uintptr_t nbr)
{
	int	i;

	i = 0;
	while (nbr != 0)
	{
		i++;
		nbr = nbr / 16;
	}
	return (i);
}

static void	ft_putptr(uintptr_t nb)
{
	if (nb >= 16)
	{
		ft_putptr(nb / 16);
		ft_putptr(nb % 16);
	}
	else
	{
		if (nb <= 9)
			ft_putchar(nb + '0');
		else
			ft_putchar(nb - 10 + 'a');
	}
}

int	ft_printptr(unsigned long long ptr)
{
	int		print_len;

	print_len = 0;
	if (ptr == 0)
		print_len += write(1, "(nil)", 5);
	else
	{
		print_len += write(1, "0x", 2);
		ft_putptr(ptr);
		print_len += ft_ptrlen(ptr);
	}
	return (print_len);
}
