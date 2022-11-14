/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kristori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:47:16 by kristori          #+#    #+#             */
/*   Updated: 2022/11/14 15:07:11 by kristori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init(t_program *program, char *map_path)
{
	program->map_path = map_path;
	program->sprite = ft_new_sprite(program->mlx, "img/player.xpm");
	program->object = ft_new_sprite(program->mlx, "img/key.xpm");
	program->ground = ft_new_sprite(program->mlx, "img/ground.xpm");
	program->wall = ft_new_sprite(program->mlx, "img/wall.xpm");
	program->exit = ft_new_sprite(program->mlx, "img/exit.xpm");
	program->enemy = ft_new_sprite(program->mlx, "img/enemy.xpm");
	program->n_moves = 0;
	program->n_object = 0;
	program->state = 1;
	program->cmap = 0;
}
