/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 15:42:47 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/05 22:20:16 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

//draw_map(game, map, &(game->img));

void	end_game(t_game *game, t_map *map, int x, int y)
{
	if (map->copy[y][x] == 'M')
	{
		game->end = TRUE + 1;
		game->count_move++;
		refresh_smart(game);
		printf("You lose!\nPress space to restart\n");
	}
	else if (game->loot == game->map.item)
	{
		map->copy[y][x] = 'e';
		game->count_move++;
		refresh_smart(game);
		printf("You win!\nPress space to restart\n");
		game->end = TRUE;
	}
}

void	moving(t_game *game, t_map *map, int x, int y)
{
	x += game->player_x;
	y += game->player_y;
	if (!is_a_wall(map->copy, x, y) && !is_outofthemap(map, x, y))
	{
		if (map->copy[y][x] == 'C')
			game->loot++;
		if (map->copy[y][x] == 'E' || map->copy[y][x] == 'M')
		{
			end_game(game, map, x, y);
			return ;
		}
		map->copy[game->player_y][game->player_x] = '0';
		map->copy[y][x] = 'P';
		game->player_x = x;
		game->player_y = y;
		game->count_move++;
		refresh_smart(game);
	}
}

int	press_key(int key, t_game *game)
{
	if (key == ESCAPE)
		close_window(game);
	if (!game->end)
	{
		if (key == UP)
			moving(game, &(game->map), 0, -1);
		else if (key == DOWN)
			moving(game, &(game->map), 0, 1);
		else if (key == LEFT)
			moving(game, &(game->map), -1, 0);
		else if (key == RIGHT)
			moving(game, &(game->map), 1, 0);
	}
	else if (game->end && key == SPACE)
		start_game(game, &(game->map), &(game->img));
	return (1);
}
