/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 13:10:48 by rsanchez          #+#    #+#             */
/*   Updated: 2021/12/08 17:13:14 by rsanchez         ###   ########.fr       */
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

static void	draw_elements(t_img *img, char c, int cursor)
{
	if (c == '0')
		draw_ground(img, cursor);
	else if (c >= '2' && c <= 'A')
		draw_wall(img, cursor, c);
	else if (c == 'C')
		draw_egg(img, cursor);
	else if (c == 'P')
		draw_player(img, cursor);
	else if (c == 'E')
		draw_nest(img, cursor);
	else if (c == 'e')
		draw_full_nest(img, cursor);
}

//else if (c == 'M')

static void	fill_img(t_map *map, t_img *img)
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
			draw_elements(img, map->copy[y][x], cursor);
			cursor = next_block(cursor);
			x++;
		}
		cursor -= img->size_x;
		cursor += BLOCK_SIZE * img->size_x;
		y++;
	}
}

void	draw_map(t_game *game, t_map *map, t_img *img)
{
	init_image(game, &(game->img));
	fill_img(map, &(game->img));
	mlx_put_image_to_window(game->mlx, game->win.addr, img->img, 0, 0);
}
