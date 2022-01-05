/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 15:27:16 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/05 23:25:13 by rsanchez         ###   ########.fr       */
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
	if (game->map.map)
		array_clear((void **)game->map.map);
	if (game->map.copy)
		array_clear((void **)game->map.copy);
	if (game->win.addr)
		mlx_destroy_window(game->mlx, game->win.addr);
	if (game->img.img)
		mlx_destroy_image(game->mlx, game->img.img);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	exit(1);
}

int	close_window(t_game *game)
{
	exit_program(game, FALSE, NULL, -1);
	return (1);
}

/*
int	update(t_scene *scene)
{
	mlx_put_image_to_window(scene->mlx, scene->window, scene->img.img, 0, 0);
	return (1);
}
*/

static void	init_window(t_game *game, t_win *win)
{
	game->mlx = mlx_init();
	if (!(game->mlx))
		exit_program(game, TRUE, "Unable to init mlx\n", 19);
	mlx_get_screen_size(game->mlx, &(win->max_x), &(win->max_y));
	if (game->map.max_x * BLOCK_SIZE > win->max_x
		|| game->map.max_y * BLOCK_SIZE > win->max_y)
		exit_program(game, TRUE, "map too big\n", 12);
	win->x = game->map.max_x * BLOCK_SIZE;
	win->y = game->map.max_y * BLOCK_SIZE;
	win->addr = mlx_new_window(game->mlx, win->x, win->y, "so_long");
	if (!(win->addr))
		exit_program(game, TRUE, "Unable to create window\n", 24);
	game->img.size_x = win->x;
	game->img.size_y = win->y;
	game->img.size_b = game->img.size_x * game->img.size_y;
}

int	main(int ac, char **av)
{
	t_game	game;

	init_zero(&game, sizeof(game));
	if (ac != 2)
		exit_program(&game, TRUE, "Wrong number of arguments\n", 26);
	import_map(&game, &(game.map), av[1]);
	init_window(&game, &(game.win));
	start_game(&game, &(game.map), &(game.img));
	mlx_hook(game.win.addr, 2, (1L << 0), press_key, &game);
	mlx_hook(game.win.addr, 33, (1L << 17), close_window, &game);
	mlx_loop(game.mlx);
	exit_program(&game, FALSE, NULL, -1);
	return (1);
}
