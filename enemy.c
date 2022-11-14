/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kristori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:03:32 by kristori          #+#    #+#             */
/*   Updated: 2022/11/14 11:49:16 by kristori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <time.h>

void	ft_spawn_enemy(t_program *program)
{
	int		x;
	int		y;

	srand(time(NULL));
	x = 0;
	y = 0;
	while (program->map[y][x] != '0')
	{
		y = rand() % (program->n_lines - 2);
		x = rand() % (ft_strlen(program->map[0]) - 1);
	}
	program->enemy_position.x = x * 40;
	program->enemy_position.y = y * 40;
	mlx_put_image_to_window(program->mlx, program->window.reference,
		program->enemy.reference, program->enemy_position.x,
		program->enemy_position.y);
}

void	ft_move_enemy(t_program *program)
{
	int		x;

	x = rand() % 4;
	if (x == 0 && program->map[program->enemy_position.y / 40]
		[(program->enemy_position.x / 40) + 1] != '1')
		program->enemy_position.x += program->enemy.size.x;
	else if (x == 1 && program->map[program->enemy_position.y / 40]
		[(program->enemy_position.x / 40) - 1] != '1')
		program->enemy_position.x -= program->enemy.size.x;
	else if (x == 2 && program->map[(program->enemy_position.y / 40 + 1)]
		[program->enemy_position.x / 40] != '1')
		program->enemy_position.y += program->enemy.size.y;
	else if (x == 3 && program->map[(program->enemy_position.y / 40 - 1)]
		[program->enemy_position.x / 40] != '1')
		program->enemy_position.y -= program->enemy.size.y;
}
