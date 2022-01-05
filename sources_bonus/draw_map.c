/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 13:10:48 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/05 22:54:33 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_image(t_game *game, t_img *img)
{
	if (img->img)
		mlx_destroy_image(game->mlx, img->img);
	img->img = mlx_new_image(game->mlx, img->size_x, img->size_y);
	if (!(img->img))
		exit_program(game, TRUE, "Unable to create img\n", 21);
	img->addr = (int *)mlx_get_data_addr(img->img, &(img->bits_pixel),
			&(img->size_x), &(img->endian));
	if (!(img->addr))
		exit_program(game, TRUE, "Unable to get image adress\n", 27);
	img->size_x /= 4;
}

static void	draw_elements(t_game *game, char c, int cursor, int id)
{
	t_img	*img;

	img = &(game->img);
	if (c == '0')
		draw_ground(img, cursor);
	else if (c >= '2' && c <= 'A')
		draw_wall(img, cursor, c);
	else if (c == 'C')
		draw_egg(img, cursor);
	else if (c == 'P')
		draw_player(img, cursor, id, game->end);
	else if (c == 'E')
		draw_nest(img, cursor);
	else if (c == 'M')
		draw_monster(img, cursor, id);
	else if (c == 'e')
		draw_full_nest(img, cursor);
}

static void	fill_img(t_game *game, t_map *map, t_img *img, int id)
{
	int	x;
	int	y;
	int	cursor;

	y = 0;
	cursor = 0;
	while (y < map->max_y)
	{
		x = 0;
		while (x < map->max_x)
		{
			draw_elements(game, map->copy[y][x], cursor, id);
			cursor = next_block(cursor);
			x++;
		}
		cursor -= img->size_x;
		cursor += BLOCK_SIZE * img->size_x;
		y++;
	}
}

static void	write_timer(t_game *game, t_img *img, int y, int x)
{
	char	buff[20];
	int		size;
	int		cursor;
	int		i;

	size = utoa_base(game->count_move, buff, "0123456789", 10);
	cursor = next_line_xtimes(img, 0, y * BLOCK_SIZE);
	i = 0;
	while (i < x - size)
	{
		draw_number(img, 10, cursor);
		cursor = next_block(cursor);
		i++;
	}
	i = 0;
	if (x < size)
		i = size - x;
	while (i < size)
	{
		draw_number(img, buff[i] - '0', cursor);
		cursor = next_block(cursor);
		i++;
	}
}

void	draw_map(t_game *game, t_map *map, t_img *img)
{
	init_image(game, &(game->img));
	fill_img(game, map, &(game->img), game->id);
	write_timer(game, img, map->max_y, map->max_x);
	mlx_put_image_to_window(game->mlx, game->win.addr, img->img, 0, 0);
}
