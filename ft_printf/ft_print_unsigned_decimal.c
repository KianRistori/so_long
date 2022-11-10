/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_decimal.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kristori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 10:36:00 by kristori          #+#    #+#             */
/*   Updated: 2022/10/27 15:42:02 by kristori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <string.h>

static char	*ft_strcpy(char *dest, const char *src)
{
	int	i;

	i = 0;
	if (!dest)
		return (NULL);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static int	ft_intlen_unsigned(unsigned int nbr)
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

static char	*ft_itoa_unsigned(unsigned int nbr)
{
	char	*ris;
	int		len;

	if (!nbr)
		return (NULL);
	len = ft_intlen_unsigned(nbr);
	ris = (char *)malloc(sizeof(char) * (len + 1));
	if (!ris)
		return (NULL);
	if (nbr == 4294967295)
	{
		ft_strcpy(ris, "4294967295");
		return (ris);
	}
	ris[len] = '\0';
	while (nbr != 0)
	{
		ris[len - 1] = (nbr % 10) + '0';
		nbr = nbr / 10;
		len--;
	}
	return (ris);
}

int	ft_print_unsigned_decimal(unsigned int nb)
{
	char	*ris;
	int		print_len;

	print_len = 0;
	if (nb == 0)
		print_len += ft_putchar('0');
	else
	{
		ris = ft_itoa_unsigned(nb);
		print_len += ft_printstr(ris);
		free(ris);
	}
	return (print_len);
}
