/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kristori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:28:52 by kristori          #+#    #+#             */
/*   Updated: 2022/11/15 13:59:03 by kristori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx/mlx.h"
# include "gnl/get_next_line.h"
# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include <fcntl.h>

# ifndef ANIMATION_FRAMES
#  define ANIMATION_FRAMES 10000
# endif

typedef struct s_vector
{
	int	x;
	int	y;
}				t_vector;

typedef struct s_window {
	void		*reference;
	t_vector	size;
}				t_window;

typedef struct s_image {
	void		*reference;
	t_vector	size;
	char		*pixels;
	int			bits_per_pixel;
	int			line_size;
	int			endian;
}				t_image;

typedef struct s_program {
	void		*mlx;
	char		**map;
	char		**map2;
	char		*map_path;
	char		*display_moves;
	int			n_lines;
	int			n_moves;
	int			n_object;
	int			state;
	int			cmap;
	t_window	window;
	t_image		sprite;
	t_image		object;
	t_image		ground;
	t_image		wall;
	t_image		exit;
	t_image		enemy;
	t_vector	sprite_position;
	t_vector	enemy_position;
}				t_program;

t_window	ft_new_window(t_program *program, char *name);
t_image		ft_new_sprite(void *mlx, char *path);

int			ft_input(int key, void *program);
int			ft_update(void *param);

void		ft_init(t_program *program, char *map_path);
void		ft_crete_map(t_program *program);
void		ft_create_map2(t_program *program, int k, int i, t_vector *vector);
void		ft_save_map(t_program *program);
void		ft_save_map2(t_program *program);
void		ft_hoocks_state(t_program *program);
void		ft_hooks_if(t_program *program, int key);
void		ft_update2(t_program *program);

void		ft_sprite_position(t_program *program);
void		ft_sprite_position2(t_program *program, int k, int i);
void		ft_count_lines(t_program *program);
void		ft_count_object(t_program *program);

char		*ft_concat(t_program *program);
void		ft_take_object(t_program *program);
void		ft_win(t_program *program);
void		ft_lose(t_program *program);
void		ft_spawn_enemy(t_program *program);
void		ft_move_enemy(t_program *program);
void		ft_free_sprite(t_program *program);
void		ft_free_all(t_program *program);

void		ft_map_check(t_program *program);
int			ft_map_check_contain(t_program *program);
int			ft_map_check_walls(t_program *program);
int			ft_map_check_walls_top_bottom(t_program *program);
int			ft_map_check_walls_left_right(t_program *program);
int			ft_map_check_rectangular(t_program *program);
int			ft_map_check_contain_start(t_program *program);
int			ft_map_check_contain_collectible(t_program *program);
int			ft_map_check_contain_exit(t_program *program);
int			ft_map_check_path(t_program *program);
int			ft_map_check_path1(t_program *program);

void		ft_exit(t_program *program, int key);
int			ft_close(void);

#endif
