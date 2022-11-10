/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kristori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:43:17 by kristori          #+#    #+#             */
/*   Updated: 2022/11/10 15:17:20 by kristori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_free_map(t_program *program)
{
	int		x;

	x = 0;
	while (program->map[x])
	{
		free(program->map[x]);
		x++;
	}
	free(program->map);
}

void	ft_free_sprite(t_program *program)
{
	mlx_destroy_image(program->mlx, program->sprite.reference);
	mlx_destroy_image(program->mlx, program->wall.reference);
	mlx_destroy_image(program->mlx, program->object.reference);
	mlx_destroy_image(program->mlx, program->ground.reference);
	mlx_destroy_image(program->mlx, program->enemy.reference);
}

void	ft_free_all(t_program *program)
{
	ft_free_sprite(program);
	mlx_destroy_window(program->mlx, program->window.reference);
	mlx_destroy_display(program->mlx);
	free(program->mlx);
	ft_free_map(program);
}
