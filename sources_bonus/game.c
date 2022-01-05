/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 14:40:06 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/05 22:14:57 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <sys/time.h>

int	refresh_smart(t_game *game)
{
	struct timeval	time;
	unsigned int	ts;

	if (gettimeofday(&time, NULL) != 0)
		return (-1);
	ts = time.tv_sec * 1000 + time.tv_usec / 1000;
	if (ts > game->last_refresh + game->fps_delay)
	{
		game->id++;
		if (game->id > 5 * FRAME_SPRITE)
			game->id = 0;
		draw_map(game, &(game->map), &(game->img));
		mlx_put_image_to_window(game->mlx, game->win.addr, game->img.img, 0, 0);
		game->last_refresh = ts;
	}
	return (1);
}

void	start_game(t_game *game, t_map *map, t_img *img)
{
	game->player_x = map->origin_x;
	game->player_y = map->origin_y;
	game->count_move = 0;
	game->loot = 0;
	game->end = FALSE;
	if (map->copy)
		array_clear((void **)map->copy);
	map->copy = array_string_duplicate(map->map, map->max_y);
	if (!(map->copy))
		exit_program(game, TRUE, "Unable to copy map\n", 19);
	draw_map(game, map, img);
}
