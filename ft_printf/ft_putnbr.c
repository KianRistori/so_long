/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kristori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 15:51:05 by kristori          #+#    #+#             */
/*   Updated: 2022/11/08 10:35:24 by kristori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_intlen(int nbr)
{
	int	i;

	i = 0;
	while (nbr != 0)
	{
		i++;
		nbr = nbr / 10;
	}
	return (i);
}

static int	ft_absolute_value(int nbr)
{
	if (nbr < 0)
		return (-nbr);
	return (nbr);
}

static char	*ft_itoa(int nbr)
{
	char	*ris;
	int		len;

	if (!nbr)
		return (NULL);
	len = ft_intlen(nbr);
	if (nbr < 0)
		len = len + 1;
	ris = (char *)malloc(sizeof(char) * (len + 1));
	if (!ris)
		return (NULL);
	if (nbr < 0)
		ris[0] = '-';
	else if (nbr == 0)
		ris[0] = '0';
	ris[len] = '\0';
	while (nbr != 0)
	{
		ris[len - 1] = ft_absolute_value(nbr % 10) + '0';
		nbr = nbr / 10;
		len--;
	}
	return (ris);
}

int	ft_putnbr(int nb)
{
	int		len;
	char	*ris;

	len = 0;
	ris = ft_itoa(nb);
	len = ft_printstr_nbr(ris);
	free(ris);
	return (len);
}
