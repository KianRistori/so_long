/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kristori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:55:01 by kristori          #+#    #+#             */
/*   Updated: 2022/11/10 15:51:47 by kristori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_concat(t_program *program)
{
	char	*ris;

	ris = malloc(ft_strlen(program->display)
			+ ft_strlen(ft_itoa(program->n_moves)) + 1);
	ft_strcpy(ris, program->display);
	ft_strcat(ris, ft_itoa(program->n_moves));
	return (ris);
}

void	ft_take_object(t_program *program)
{
	if (program->n_object > 0)
	{
		if (program->map[program->sprite_position.y / 40]
			[program->sprite_position.x / 40] == 'C')
		{
			program->map[program->sprite_position.y / 40]
			[program->sprite_position.x / 40] = '0';
			program->n_object--;
		}
	}
}

void	ft_win(t_program *program)
{
	if (program->n_object == 0)
	{
		if (program->map[program->sprite_position.y / 40]
			[program->sprite_position.x / 40] == 'E')
		{
			program->state = 0;
			mlx_clear_window(program->mlx, program->window.reference);
			mlx_string_put(program->mlx, program->window.reference,
				program->window.size.x / 2, program->window.size.y / 2,
				100000, "YOU WIN");
			mlx_string_put(program->mlx, program->window.reference,
				program->window.size.x / 2,
				program->window.size.y / 2 + 15, 100000, "press ESC to close");
		}
	}
}

void	ft_lose(t_program *program)
{
	if (program->sprite_position.y == program->enemy_position.y
		&& program->sprite_position.x == program->enemy_position.x)
	{
		program->state = 0;
		mlx_clear_window(program->mlx, program->window.reference);
		mlx_string_put(program->mlx, program->window.reference,
			program->window.size.x / 2, program->window.size.y / 2,
			100000, "YOU LOSE");
		mlx_string_put(program->mlx, program->window.reference,
			program->window.size.x / 2, program->window.size.y / 2 + 15,
			100000, "press ESC to close");
	}
}

void	ft_exit(t_program *program, int key)
{
	if (key == 65307)
	{
		ft_free_all(program);
		ft_close();
	}
}
