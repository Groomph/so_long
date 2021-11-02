/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 16:19:25 by rsanchez          #+#    #+#             */
/*   Updated: 2021/11/02 13:52:27 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "mlx.h"

# define BLOCK_SIZE 48
# define BACK_DISTANCE 5
# define WINDOW_X 720
# define WINDOW_Y 576
# define BACK_GROUND "backscreen.xmp"

typedef struct	s_window
{
	void	*addr;
	int	x;
	int	y;
}		t_win;

typedef struct s_map
{
	char	**map;
	int	*x;
	int	max_x;
	int	max_y;
	t_list	*origin;
	t_list	*item;
	t_list	*exit;
	t_list	*monster;
}		t_map;

typedef struct	s_image
{
	void	*img;
	int	*addr;
	int	bits_pixel;
	BOOL	endian;
	int	size_x;
	int	size_y;
	int	size_p;
	int	cursor_x;
	int	cursor_y;
	int	cursor_p;
	int	center_x;
	int	center_y;
	int	center_p;
	int	top_left_x;
	int	top_left_y;
	int	top_left_p;
}		t_img;

typedef struct s_game
{
	void	*mlx;
	int	b_size;
	int	b_pixel;
	int	back_dist;
	t_win	win;
	t_img	back;
	t_img	decor;
	t_map	map;
}		t_game;

void	exit_program(t_game *game, BOOL error, const char *str, int size);
void	import_map(t_game *game, t_map *map, char *file);
void	draw_map(t_game *game, t_map *map);
void	create_window(t_win *win)
void	set_window(t_game *game, t_img *img);
int	which_wall(t_map *map, int x, int y, int size);

BOOL	is_endedmap(t_game *game, t_map *map);
BOOL	go_to(t_map *map, int x, int y);

BOOL	is_outofthemap(t_map *map, int x, int y);
BOOL	is_a_wall(t_map *map, int x, int y);

int	get_color_block1(int i, int i2);

void	print_map(t_map *map);
#endif
