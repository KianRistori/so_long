/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kristori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:45:40 by kristori          #+#    #+#             */
/*   Updated: 2022/11/15 15:12:04 by kristori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_program	program;

	if (argc == 2)
	{
		program.mlx = mlx_init();
		ft_init(&program, argv[1]);
		ft_count_lines(&program);
		ft_save_map(&program);
		ft_map_check(&program);
		program.window = ft_new_window(&program, "So_long");
		ft_sprite_position(&program);
		ft_spawn_enemy(&program);
		ft_crete_map(&program);
		ft_count_object(&program);
		mlx_key_hook(program.window.reference, *ft_input, &program);
		mlx_loop_hook(program.mlx, *ft_update, &program);
		mlx_loop(program.mlx);
	}
	return (0);
}
