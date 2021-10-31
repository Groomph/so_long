/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 15:27:16 by rsanchez          #+#    #+#             */
/*   Updated: 2021/10/31 17:20:52 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	exit_program(t_game *game, BOOL error, const char *str, int size)
{
	if (error)
	{
		write(2, "Error\n", 6);
		if (size > -1)
			write(2, str, size);
		else
			perror(str);
	}
	array_clear((void **)game->map.map);
	free(game->map.x);
	lst_clear(&(game->map.origin), &free);
	lst_clear(&(game->map.item), &free);
	lst_clear(&(game->map.exit), &free);
	lst_clear(&(game->map.monster), &free);
	if (game->win.addr)
		mlx_destroy_window(game->win.mlx, game->win.addr);
	if (game->back.img)
		mlx_destroy_image(game->win.mlx, game->back.img);
	if (game->decor.img)
		mlx_destroy_image(game->win.mlx, game->decor.img);
	if (game->win.mlx)
	{
		mlx_destroy_display(game->win.mlx);
		free(game->win.mlx);
	}
	exit(1);
}

int	update(t_scene *scene)
{
	mlx_put_image_to_window(scene->mlx, scene->window, scene->img.img, 0, 0);
	return (1);
}

void	set_window(t_game *game, t_img *img)
{
	mlx_put_image_to_window(game->win.mlx, game->win.addr, img->img,
			(img->x - scene->x) / -2, (img->y - scene->y) / -2);
//	mlx_put_image_to_window(scene->mlx, scene->window, img->img,
//			img->x / -2 + 360, img->y / -2 + 288);
/*	int	i;

	i = 0;
	while (img2.addr[i])
	{
		printf("%u\n", img2.addr[i]);
		i++;
	}
*/	
}

static void	init_window(t_game *game, t_win *win)
{
	win->mlx = mlx_init();
	if (!(scene.mlx))
		exit_program(&scene, TRUE, "Unable to init mlx\n", 17);
	game->b_size = BLOCK_SIZE;
	game->b_pixel = game->b_size * game->b_size;
	game->back_dist = BACK_DISTANCE;
	win->x = WINDOW_X;
	win->y = WINDOW_Y;
	win->addr = mlx_new_window(win->mlx, win->x, win->y, "so_long");
	if (!(win->addr))
		exit_program(scene, TRUE, "Unable to create window\n", 24);
}

int	main(int ac, char **av)
{
	t_game	game;

	init_zero(&scene, sizeof(scene));
	if (ac != 2)
		exit_program(&scene, TRUE, "Wrong number of arguments\n", 26);
	init_window(&game, &(game.win));
	import_map(&game, &(game.map), av[1]);
	draw_map(&game, &(game.map));
	set_window(&game, &(game.img));
	mlx_loop(game.win.mlx);
	return (1);
}
