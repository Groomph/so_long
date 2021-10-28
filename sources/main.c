/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 15:27:16 by rsanchez          #+#    #+#             */
/*   Updated: 2021/10/28 14:22:36 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	exit_program(t_scene *scene, BOOL error, const char *str, int size)
{
	if (error)
	{
		write(2, "Error\n", 6);
		if (size > -1)
			write(2, str, size);
		else
			perror(str);
	}
	array_clear((void **)scene->map.map);
	free(scene->map.x);
	lst_clear(&(scene->map.origin), &free);
	lst_clear(&(scene->map.item), &free);
	lst_clear(&(scene->map.exit), &free);
	lst_clear(&(scene->map.monster), &free);
	if (scene->window)
		mlx_destroy_window(scene->mlx, scene->window);
	if (scene->img.img)
		mlx_destroy_image(scene->mlx, scene->img.img);
	if (scene->mlx)
	{
		mlx_destroy_display(scene->mlx);
		free(scene->mlx);
	}
	exit(1);
}

int	update(t_scene *scene)
{
	mlx_put_image_to_window(scene->mlx, scene->window, scene->img.img, 0, 0);
	return (1);
}

void	set_window(t_scene *scene, t_img *img)
{
	mlx_put_image_to_window(scene->mlx, scene->window, img->img,
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

void	create_window(t_win *win)
{
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
	import_map(&scene, &(scene.map), av[1]);
	game.win.mlx = mlx_init();
	if (!(scene.mlx))
		exit_program(&scene, TRUE, "Unable to init mlx\n", 17);
	create_window(&scene);
	draw_map(&scene, &(scene.map));
	set_window(&scene, &(scene.img));
	mlx_loop(scene.mlx);
	return (1);
}
