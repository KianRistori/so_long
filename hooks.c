/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kristori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:45:45 by kristori          #+#    #+#             */
/*   Updated: 2022/11/14 15:19:23 by kristori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_input(int key, void *param)
{
	t_program	*program;

	program = (t_program *)param;
	if (program->state == 1)
	{
		mlx_clear_window(program->mlx, program->window.reference);
		ft_hooks_if(program, key);
		if (key == 65364
			&& (program->map[(program->sprite_position.y / 40 + 1)]
				[program->sprite_position.x / 40] != '1'))
		{
			program->sprite_position.y += program->sprite.size.y;
			program->n_moves++;
		}
		if (key == 65362
			&& (program->map[(program->sprite_position.y / 40 - 1)]
				[program->sprite_position.x / 40] != '1'))
		{
			program->sprite_position.y -= program->sprite.size.y;
			program->n_moves++;
		}
	}
	ft_exit(program, key);
	ft_hoocks_state(program);
	return (0);
}

void	ft_hoocks_state(t_program *program)
{
	if (program->state == 1)
	{
		ft_crete_map(program);
		mlx_put_image_to_window(program->mlx, program->window.reference,
			program->sprite.reference, program->sprite_position.x,
			program->sprite_position.y);
		ft_take_object(program);
		ft_move_enemy(program);
	}
	ft_lose(program);
	ft_win(program);
}

int	ft_update(void *param)
{
	t_program	*program;
	static int	frame;

	program = (t_program *)param;
	frame++;
	if (frame == ANIMATION_FRAMES)
	{
		program->sprite_position.y += 1;
	}
	else if (frame >= ANIMATION_FRAMES * 2)
	{
		program->sprite_position.y -= 1;
		frame = 0;
	}
	if (program->state == 1)
	{
		ft_update2(program);
	}
	return (0);
}

void	ft_update2(t_program *program)
{
	mlx_put_image_to_window(program->mlx, program->window.reference,
		program->sprite.reference, program->sprite_position.x,
		program->sprite_position.y);
	mlx_put_image_to_window(program->mlx, program->window.reference,
		program->enemy.reference, program->enemy_position.x,
		program->enemy_position.y);
	mlx_string_put(program->mlx, program->window.reference,
		program->window.size.x / 2,
		program->window.size.y - 5, 100000, ft_concat(program));
}

void	ft_hooks_if(t_program *program, int key)
{
	if (key == 65363 && (program->map[program->sprite_position.y / 40]
			[(program->sprite_position.x / 40) + 1] != '1'))
	{
		program->sprite_position.x += program->sprite.size.x;
		program->n_moves++;
	}
	if (key == 65361 && (program->map[program->sprite_position.y / 40]
			[(program->sprite_position.x / 40) - 1] != '1'))
	{
		program->sprite_position.x -= program->sprite.size.x;
		program->n_moves++;
	}
}
