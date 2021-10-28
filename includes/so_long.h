/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 16:19:25 by rsanchez          #+#    #+#             */
/*   Updated: 2021/10/27 16:02:01 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "mlx.h"

# define BLOCK_SIZE 2304;

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

typedef struct		s_window_image
{
	void			*img;
	int				*addr;
	int				x;
	int				y;
	t_list				c;
	int				p_c;
	int				bits_pixel;
	int				endian;
	BOOL			set;
}					t_img;

typedef struct s_scene
{
	void	*mlx;
	void	*window;
	int	x;
	int	y;
	t_img	img;
	t_map	map;
}		t_scene;

enum	e_color
{
	B0 = 4152,
	B1 = 3149928,
	B2 = 4728976,
	B3 = 6291472,
	B4 = 7229109,
	B5 = 7887040,
	B6 = 10255582,
	B7 = 11045096,
	B8 = 14207224,
	B9 = 15129833,
	BA = 15394038,
	BB = 16316664
};

void	exit_program(t_scene *scene, BOOL error, const char *str, int size);
void	import_map(t_scene *scene, t_map *map, char *file);
void	draw_map(t_scene *scene, t_map *map);
void	set_window(t_scene *scene, t_img *img);
int	which_wall(t_map *map, int x, int y, int size);

BOOL	is_endedmap(t_scene *scene, t_map *map);
BOOL	go_to(t_map *map, int x, int y);

BOOL	is_outofthemap(t_map *map, int x, int y);
BOOL	is_a_wall(t_map *map, int x, int y);

int	get_color_block1(int i, int i2);

void	print_map(t_map *map);
#endif
