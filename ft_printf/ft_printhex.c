/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kristori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 11:20:05 by kristori          #+#    #+#             */
/*   Updated: 2022/10/26 14:21:41 by kristori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hexlen(unsigned int nbr)
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

static void	ft_puthex(unsigned int nb, const char format)
{
	if (nb >= 16)
	{
		ft_puthex(nb / 16, format);
		ft_puthex(nb % 16, format);
	}
	else
	{
		if (nb <= 9)
			ft_putchar(nb + '0');
		else
		{
			if (format == 'x')
				ft_putchar(nb - 10 + 'a');
			if (format == 'X')
				ft_putchar(nb - 10 + 'A');
		}
	}
}

int	ft_printhex(unsigned int nb, const char format)
{
	if (nb == 0)
		return (ft_putchar('0'));
	else
		ft_puthex(nb, format);
	return (ft_hexlen(nb));
}
