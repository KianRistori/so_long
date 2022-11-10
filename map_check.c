/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kristori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:38:07 by kristori          #+#    #+#             */
/*   Updated: 2022/11/10 15:51:28 by kristori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_map_check(t_program *program)
{
	if (ft_map_check_walls(program) == 1
		|| ft_map_check_contain(program) == 1
		|| ft_map_check_rectangular(program) == 1)
	{
		ft_free_all(program);
		ft_close();
	}
	return ;
}

int	ft_map_check_walls(t_program *program)
{
	if (ft_map_check_walls_left_right(program) == 0
		&& ft_map_check_walls_top_bottom(program) == 0)
		return (0);
	return (1);
}

int	ft_map_check_walls_top_bottom(t_program *program)
{
	int		i;

	i = 0;
	while (program->map[0][i] != '\n')
	{
		if (program->map[0][i] != '1')
		{
			ft_printf("%s\n" "Error\nMap not closed by walls\n");
			return (1);
		}
		i++;
	}
	i = 0;
	while (program->map[program->n_lines - 2][i] != '\n')
	{
		if (program->map[program->n_lines - 2][i] != '1')
		{
			ft_printf("%s\n" "Error\nMap not closed by walls\n");
			return (1);
		}
		i++;
	}
	return (0);
}

int	ft_map_check_walls_left_right(t_program *program)
{
	int		i;

	i = program->n_lines - 2;
	while (i > -1)
	{
		if (program->map[i][0] != '1'
			|| program->map[i][ft_strlen(program->map[i]) - 2] != '1')
		{
			ft_printf("%s\n" "Error \nMap not closed by walls\n");
			return (1);
		}
		i--;
	}
	return (0);
}

int	ft_map_check_rectangular(t_program *program)
{
	int		k;

	k = ft_strlen(program->map[0]);
	if (program->n_lines < k)
		return (0);
	ft_printf("%s\n" "Error\nMap not rectangular");
	return (1);
}
