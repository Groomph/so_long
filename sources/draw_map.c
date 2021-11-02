G
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 10:48:34 by rsanchez          #+#    #+#             */
/*   Updated: 2021/11/02 16:58:29 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#include <unistd.h>	//test
#include <stdio.h>	//test

void	init_image(t_scene *scene, t_img *img, t_map *map, int size)
{
	if (map)
	{
		img->img = mlx_new_image(scene->mlx, map->max_x * size, map->max_y * size);
		if (!(img->img))
			exit_program(scene, TRUE, "Unable to create img\n", 21);
		img->y = map->max_y * size;
	}
	else
	{
		img->img = mlx_xpm_file_to_image(scene->mlx, "backscreen.xpm",
				&(img->x), &(img->y));
		if (!(img->img))
			exit_program(scene, TRUE, "Unable to open xpm file\n", 24);
	}
	img->addr = (int*)mlx_get_data_addr(img->img, &(img->bits_pixel),
			&(img->x), &(img->endian));
	if (!(img->addr))
		exit_program(scene, TRUE, "Unable to get image adress\n", 27);
	img->x /= 4;
	img->c.x = img->x / 2;
	img->c.y = img->y / 2;
	img->p_c = img->c.y * img->x;
	img->p_c += img->c.x;
}

void	draw_color(t_img *img, int *xy, int size, int color)
{
	int	i;
	int	i2;
	int	pixel;

	i = 0;
	pixel = xy[1] * size * img->x;
	pixel += xy[0] * size;
	while (i < size)
	{
		i2 = 0;
		while(i2 < size)
		{
			//			printf("%i\n", pixel);
			img->addr[pixel] = color;
			pixel++;
			i2++;
		}
		pixel -= i2;
		pixel += img->x;
		i++;
	}
}

void	draw_back(t_img *img, t_img *back, int *xy, int size)
{
	int	i;
	int	i2;
	int	pixel;
	int	pixel_back;

	i = 0;
	pixel = xy[1] * size * back->x;
	pixel += xy[0] * size;
	pixel_back = (back->y / 2) * back->x + back->x / 2;
	pixel_back += xy[1] *size * back->x;
	pixel_back += xy[0] * size;
	while (i < size)
	{
		i2 = 0;
		while(i2 < size)
		{
			img->addr[pixel] = back->addr[pixel_back];
			pixel++;
			pixel_back++;
			i2++;
		}
		pixel -= i2;
		pixel += img->x;
		pixel_back -= i2;
		pixel_back += back->x;
		i++;
	}
}

static void	init_back(t_game *game, t_img *back)
{
	back->img = mlx_xpm_file_to_image(scene->mlx, BACK_GROUND,
			&(back->size_x), &(back->size_y));
	if (!(back->img))
		exit_program(scene, TRUE, "Unable to open back file\n", 25);
	back->addr = (int*)mlx_get_data_addr(back->img, &(back->bits_pixel),
			&(back->size_x), &(back->endian));
	if (!(back->addr))
		exit_program(scene, TRUE, "Unable to get back adress\n", 26);
	back->size_x /= 4;
	back->size_p = back->size_x * back->size_y;
	back->center_x = back->x / 2;
	back->center_y = back->y / 2;
	back->center_p = back->center_y * back->size_x;
	back->center_p += back->center_x;
	back->top_left_x = back->center_x - scene->x / 2;
	back->top_left_y = back->center_y - scene->y / 2;
	back->top_left_p = back->top_left_y * back->size_x;
	back->top_left_p += back->top_left_x;

}

static void	fill_decor(t_img *decor)
{
	int	i;

	i = 0;
	while (i < decor->size_p)
	{
		decor->addr[i] = 4152;
		i++;
	}
}

static void	init_decor(t_game *game, t_img *decor, t_map *map)
{
	int	x;
	int	y;

	decor->size_x = game->win.x * 2 + map->max_x * game->b_size;
	decor->size_y = game->win.y * 2 + map->max_y * game->b_size;
	decor->img = mlx_new_image(game->mlx, decor->size_x, decor->size_y);
	if (!(decor->img))
		exit_program(scene, TRUE, "Unable to create img\n", 21);
	decor->addr = (int*)mlx_get_data_addr(decor->img, &(decor->bits_pixel),
			&(decor->size_x), &(decor->endian));
	if (!(decor->addr))
		exit_program(scene, TRUE, "Unable to get final adress\n", 27);
	decor->size_x /= 4;
	decor->size_p = decor->size_x * decor->size_y;
	decor->center_x = decor->x / 2;
	decor->center_y = decor->y / 2;
	decor->center_p = decor->center_y * decor->size_x;
	decor->center_p += decor->center_x;
	decor->top_left_x = decor->center_x - scene->x / 2;
	decor->top_left_y = decor->center_y - scene->y / 2;
	decor->top_left_p = decor->top_left_y * decor->size_x;
	decor->top_left_p += decor->top_left_x;
	fill_decor(decor);
}



void	draw_map(t_game *game, t_map *map)
{
	int	x;
	int	y;

	init_back(game, &(game->back));
	init_decor(game, &(game->decor), map);
	place_cursor(&(game->decor), map);

	while (y < map->max_y)
	{
		x = 0;
		while (x < map->max_x)
		{
			if (x >= map->x[y] || map->map[y][x] == ' ')
				scene->img.addr[pixel] = 4152;
			else if (is_a_wall(map, x, y))
				scene->img.addr[pixel] = which_wall(map, x2, y2,size_element) ;
			else
				scene->img.addr[pixel] = back.addr[pixel_b];
			move_next_block();
			x++;
		}
		move_next_line();
		y++;
	}
	write(1," done\n", 5);
}
