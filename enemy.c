/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kristori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:03:32 by kristori          #+#    #+#             */
/*   Updated: 2022/11/10 15:16:51 by kristori         ###   ########.fr       */
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
	if (program->state == 1)
	{
		if (program->map[program->enemy_position.y / 40]
			[(program->enemy_position.x / 40) + 1] != '1' && x == 0)
			program->enemy_position.x += 40;
		else if (program->map[program->enemy_position.y / 40]
			[(program->enemy_position.x / 40) - 1] != '1' && x == 1)
			program->enemy_position.x -= 40;
		else if (program->map[(program->enemy_position.y / 40) + 1]
			[program->enemy_position.x / 40] != '1' && x == 2)
			program->enemy_position.y += 40;
		else if (program->map[(program->sprite_position.y / 40) - 1]
			[program->sprite_position.x / 40] != '1' && x == 3)
			program->enemy_position.y -= 40;
	}
}
