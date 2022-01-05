/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 16:19:25 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/05 22:27:57 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "mlx.h"

# define BLOCK_SIZE 48
# define MAX_FPS 60
# define FRAME_SPRITE 6

# define UINT unsigned int    //pour la norme -_-

enum	e_key
{
	ESCAPE = 65307,
	UP = 65362,
	DOWN = 65364,
	RIGHT = 65363,
	LEFT = 65361,
	SPACE = 32,
};

typedef struct s_window
{
	void	*addr;
	int		x;
	int		y;
	int		max_x;
	int		max_y;
}		t_win;

typedef struct s_map
{
	char	**map;
	char	**copy;
	int		max_x;
	int		max_y;
	int		item;
	int		exit;
	int		origin_x;
	int		origin_y;
}		t_map;

typedef struct s_image
{
	void	*img;
	int		*addr;
	int		bits_pixel;
	BOOL	endian;
	int		size_x;
	int		size_y;
	int		size_b;
}		t_img;

typedef struct s_game
{
	void		*mlx;
	int			b_pixel;
	int			player_x;
	int			player_y;
	int			count_move;
	int			loot;
	int			id;
	UINT		last_refresh;
	UINT		fps_delay;
	BOOL		end;
	t_win		win;
	t_img		img;
	t_img		decor;
	t_map		map;
}			t_game;

int		close_window(t_game *game);
void	exit_program(t_game *game, BOOL error, const char *str, int size);
void	import_map(t_game *game, t_map *map, char *file);
BOOL	is_walled(t_map *map);
void	start_game(t_game *game, t_map *map, t_img *img);
int		refresh_smart(t_game *game);
void	draw_map(t_game *game, t_map *map, t_img *img);
int		press_key(int key, t_game *game);

BOOL	is_outofthemap(t_map *map, int x, int y);
BOOL	is_a_wall(char **map, int x, int y);

void	draw_ground(t_img *img, int cursor);
void	draw_wall(t_img *img, int cursor, char c);
void	draw_egg(t_img *img, int cursor);
void	draw_player(t_img *img, int cursor, int id, BOOL end);
void	draw_nest(t_img *img, int cursor);
void	draw_full_nest(t_img *img, int cursor);
void	draw_number(t_img *img, int cursor, int index);
void	draw_monster(t_img *img, int cursor, int id);

int		next_line(t_img *img, int cursor);
int		next_line_xtimes(t_img *img, int cursor, int nb);
int		block_line_feed(t_img *img, int cursor);
int		next_block(int cursor);
int		next_block_xtimes(int cursor, int nb);

void	print_map(t_map *map);
void	print_copy(t_map *map);
#endif
