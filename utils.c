/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kristori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:55:01 by kristori          #+#    #+#             */
/*   Updated: 2022/11/15 12:23:32 by kristori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_concat(t_program *program)
{
	char	*ris;
	char	*display;
	char	*num;

	display = "Total Moves ";
	num = ft_itoa(program->n_moves);
	ris = (char *)malloc(sizeof(char)
			* (ft_strlen(display) + ft_strlen(num) + 1));
	if (!ris)
		return (NULL);
	ft_strcpy(ris, display);
	ft_strcat(ris, num);
	free(num);
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
