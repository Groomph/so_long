/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_walled.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 20:08:39 by rsanchez          #+#    #+#             */
/*   Updated: 2021/12/08 16:28:31 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static BOOL	does_it(t_map *map)
{
	int	x;
	int	y;
	int	last;

	x = 0;
	last = map->max_y - 1;
	while (x < map->max_x)
	{
		if (map->map[0][x] != '1' || map->map[last][x] != '1')
			return (FALSE);
		x++;
	}
	y = 0;
	last = map->max_x - 1;
	while (y < map->max_y)
	{
		if (map->map[y][0] != '1' || map->map[y][last] != '1')
			return (FALSE);
		y++;
	}
	return (TRUE);
}

static char	special_case(char wall, int link)
{
	if (wall == '5' && link == 2)
		wall = '=';
	else if (wall == '6' && link == 3)
		wall = '>';
	else if (wall == '7' && link == 6)
		wall = '?';
	else if (wall == '8' && link == 8)
		wall = '@';
	else if (wall == '9' && link == 8)
		wall = 'A';
	return (wall);
}

static char	get_wall(t_map *map, int x, int y)
{
	char	wall;
	int		link;

	wall = '2';
	link = 1;
	if (is_outofthemap(map, x, y - 1) || is_a_wall(map->map, x, y - 1))
		wall += 1;
	if (is_outofthemap(map, x + 1, y) || is_a_wall(map->map, x + 1, y))
	{
		wall += 2;
		link *= 2;
	}
	if (is_outofthemap(map, x, y + 1) || is_a_wall(map->map, x, y + 1))
	{
		wall += 3;
		link *= 3;
	}
	if (is_outofthemap(map, x - 1, y) || is_a_wall(map->map, x - 1, y))
	{
		wall += 4;
		link *= 4;
	}
	return (special_case(wall, link));
}

BOOL	is_walled(t_map *map)
{
	int	x;
	int	y;

	if (!does_it(map))
		return (FALSE);
	y = 0;
	while (y < map->max_y)
	{
		x = 0;
		while (x < map->max_x)
		{
			if (map->map[y][x] == '1')
				map->map[y][x] = get_wall(map, x, y);
			x++;
		}
		y++;
	}
	return (TRUE);
}
