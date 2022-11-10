/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kristori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:05:07 by kristori          #+#    #+#             */
/*   Updated: 2022/11/10 15:54:52 by kristori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>

int	ft_close(void)
{
	exit(0);
}

t_window	ft_new_window(t_program *program, char *name)
{
	t_window	window;
	int			width;
	int			height;

	width = (ft_strlen(program->map[0]) - 1) * 40;
	height = (program->n_lines - 1) * 40 + 20;
	window.reference = mlx_new_window(program->mlx, width, height, name);
	window.size.x = width;
	window.size.y = height;
	mlx_hook(window.reference, 17, 0, ft_close, 0);
	return (window);
}
