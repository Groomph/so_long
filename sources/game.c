/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 14:40:06 by rsanchez          #+#    #+#             */
/*   Updated: 2021/12/08 17:18:22 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
