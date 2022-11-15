/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kristori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:45:53 by kristori          #+#    #+#             */
/*   Updated: 2022/11/15 12:25:31 by kristori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_sprite_position(t_program *program)
{
	int		k;
	int		i;

	k = 0;
	i = 0;
	ft_sprite_position2(program, k, i);
}

void	ft_sprite_position2(t_program *program, int k, int i)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (program->map[k] != 0)
	{
		while (program->map[k][i])
		{
			if (program->map[k][i] == 'P')
			{
				program->sprite_position.x = x;
				program->sprite_position.y = y;
			}
			x += 40;
			i++;
		}
		i = 0;
		x = 0;
		y += 40;
		k++;
	}
}

void	ft_save_map(t_program *program)
{
	char	*line;
	int		fd;
	int		k;

	k = 0;
	fd = open(program->map_path, O_RDONLY);
	line = "";
	program->map = (char **)malloc(sizeof(char *) * (program->n_lines + 1));
	if (!program->map)
		return ;
	while (line != NULL)
	{
		line = get_next_line(fd);
		program->map[k] = line;
		k++;
	}
	program->map[k] = 0;
	ft_save_map2(program);
	fd = close(fd);
}

void	ft_save_map2(t_program *program)
{
	int		k;

	k = 0;
	program->map2 = (char **)malloc(sizeof(char *) * (program->n_lines + 1));
	if (!program->map2)
		return ;
	while (program->map[k])
	{
		program->map2[k] = ft_strdup(program->map[k]);
		k++;
	}
	program->map2[k] = 0;
}
