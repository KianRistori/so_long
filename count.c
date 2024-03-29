/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kristori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:31:34 by kristori          #+#    #+#             */
/*   Updated: 2022/11/15 13:25:32 by kristori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_count_lines(t_program *program)
{
	char	*line;
	int		fd;

	fd = open(program->map_path, O_RDONLY);
	line = "";
	while (line != NULL)
	{
		line = get_next_line(fd);
		program->n_lines++;
		free(line);
	}
	fd = close(fd);
}

void	ft_count_object(t_program *program)
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
			{
				program->n_object++;
			}
			i++;
		}
		i = 0;
		k++;
	}
}
