/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_contain.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kristori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:26:30 by kristori          #+#    #+#             */
/*   Updated: 2022/11/15 15:12:43 by kristori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_map_check_contain(t_program *program)
{
	if (ft_map_check_contain_start(program) == 1
		&& ft_map_check_contain_collectible(program) == 0
		&& ft_map_check_contain_exit(program) == 1)
		return (0);
	ft_printf("Error\nMap not contain essential value\n");
	return (1);
}

int	ft_map_check_contain_exit(t_program *program)
{
	int		k;
	int		x;
	int		i;

	k = 0;
	x = 0;
	i = 0;
	while (program->map[x] != 0)
	{
		while (program->map[x][i])
		{
			if (program->map[x][i] == 'E')
				k++;
			i++;
		}
		i = 0;
		x++;
	}
	return (k);
}

int	ft_map_check_contain_collectible(t_program *program)
{
	int		k;
	int		i;

	k = 0;
	i = 0;
	while (program->map[k] != 0)
	{
		while (program->map[k][i])
		{
			if (program->map[k][i] == 'C')
				return (0);
			i++;
		}
		i = 0;
		k++;
	}
	return (1);
}

int	ft_map_check_contain_start(t_program *program)
{
	int		k;
	int		x;
	int		i;

	k = 0;
	x = 0;
	i = 0;
	while (program->map[x] != 0)
	{
		while (program->map[x][i])
		{
			if (program->map[x][i] == 'P')
				k++;
			i++;
		}
		i = 0;
		x++;
	}
	return (k);
}
