/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 10:48:34 by rsanchez          #+#    #+#             */
/*   Updated: 2021/10/25 13:56:03 by rsanchez         ###   ########.fr       */
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

void	draw_map(t_scene *scene, t_map *map)
{
	int	size_element;
	t_img	back;

	size_element = 40;
	init_image(scene, &back, NULL, size_element);
	init_image(scene, &(scene->img), &(scene->map), size_element);
	
	int	x;
	int	y;
	int	xy[2];

	y = 0;
	printf("%i\n", map->max_x);
	printf("%i\n", map->max_y);
	while (y < map->max_y)
	{
		x = 0;
		while (x < map->max_x)
		{
			xy[0] = x;
			xy[1] = y;
//			printf("x: %i\n", x);
//			printf("y: %i\n", y);
			if (x >= map->x[y] || map->map[y][x] == ' ')
				draw_color(&(scene->img), xy, size_element, 0x00FF0000);
			else if (map->map[y][x] == '1')
				draw_color(&(scene->img), xy, size_element, 0x0000FF00);
			else
				draw_back(&(scene->img), &back, xy, size_element);
			x++;
//			set_window(scene, &(scene->img));
		}
		y++;
	}
	write(1," done\n", 5);

}
