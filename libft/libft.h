/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kristori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 13:35:09 by kristori          #+#    #+#             */
/*   Updated: 2022/11/14 13:48:59 by kristori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include "../gnl/get_next_line.h"
# include "../ft_printf/ft_printf.h"

char	*ft_itoa(int n);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strcat(char *dest, char *src);
char	*ft_strdup(char *s);

#endif
