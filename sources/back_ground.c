/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_ground.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 13:26:08 by rsanchez          #+#    #+#             */
/*   Updated: 2021/10/28 15:33:28 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_full_bg(t_game *game, t_img *back)
{
	back->img = mlx_xpm_file_to_image(scene->mlx, "backscreen.xpm",
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

void	init_background(t_game *game, t_map *map, void *mlx)
{
	t_img	tmp;

	init_full_bg(g, &tmp);
	g->back.img = mlx_new_image(mlx, map->max_x * , gmap->max_y * size);
	if (!(img->img))
		exit_program(scene, TRUE, "Unable to create img\n", 21);
	img->y = map->max_y * size;
	{
		
	}
}
