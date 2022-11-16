/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kristori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 10:17:27 by kristori          #+#    #+#             */
/*   Updated: 2022/11/16 13:11:14 by kristori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_map_check_path(t_program *program)
{
	ft_map_check_path1(program);
	if (program->cmap == 1)
		return (0);
	ft_printf("Error\nMap not have valid path\n");
	return (1);
}

static int	ft_map_check_path2(t_program *program, int y, int x)
{
	if (program->map2[y][x] == 'E')
	{
		program->cmap = 1;
		return (1);
	}
	program->map2[y][x] = '1';
	if (program->map2[y][x + 1] != '1')
		ft_map_check_path2(program, y, (x + 1));
	if (program->map2[y][x - 1] != '1')
		ft_map_check_path2(program, y, (x - 1));
	if (program->map2[y + 1][x] != '1')
		ft_map_check_path2(program, (y + 1), x);
	if (program->map2[y - 1][x] != '1')
		ft_map_check_path2(program, (y - 1), x);
	return (0);
}

int	ft_map_check_path1(t_program *program)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (program->map2[y][x] != 'P')
	{
		while (program->map2[y][x])
		{
			if (program->map2[y][x] == 'P')
				return (ft_map_check_path2(program, y, x));
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}
