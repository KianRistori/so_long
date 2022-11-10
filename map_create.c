/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kristori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:03:40 by kristori          #+#    #+#             */
/*   Updated: 2022/11/10 13:10:52 by kristori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_crete_map(t_program *program)
{
	t_vector	vector;
	int			k;
	int			i;

	k = 0;
	i = 0;
	vector.x = 0;
	vector.y = 0;
	while (program->map[k] != 0)
	{
		ft_create_map2(program, k, i, &vector);
		i = 0;
		vector.x = 0;
		vector.y += 40;
		k++;
	}
}

void	ft_create_map2(t_program *program, int k, int i, t_vector *vector)
{
	while (program->map[k][i])
	{
		if (program->map[k][i] == '1')
		{
			mlx_put_image_to_window(program->mlx, program->window.reference,
				program->wall.reference, vector->x, vector->y);
		}
		if (program->map[k][i] == 'C')
		{
			mlx_put_image_to_window(program->mlx, program->window.reference,
				program->object.reference, vector->x, vector->y);
		}
		if (program->map[k][i] == 'E')
		{
			mlx_put_image_to_window(program->mlx, program->window.reference,
				program->exit.reference, vector->x, vector->y);
		}
		if (program->map[k][i] == '0' || program->map[k][i] == 'P')
		{
			mlx_put_image_to_window(program->mlx, program->window.reference,
				program->ground.reference, vector->x, vector->y);
		}
		vector->x += 40;
		i++;
	}
}
