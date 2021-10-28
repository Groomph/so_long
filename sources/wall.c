/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 19:13:58 by rsanchez          #+#    #+#             */
/*   Updated: 2021/10/28 10:40:15 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char     special_case(char wall, int link)
{
        if (wall == '5' && link == 2)
                wall = '=';
        else if (wall == '6' && link == 3)
                wall = '>';
        else if (wall == '6' && link == 8)
                wall = '?';
        else if (wall == '7' && link == 4)
                wall = '@';
        else if (wall == '9' && link == 6)
                wall = 'A';
        return (wall);
}

static char     get_wall(t_map *map, int x, int y)
{
        char    wall;
        int     link;

        wall = '2';
        link = 1;
        if (is_outofthemap(map, x, y - 1) || is_a_wall(map, x, y - 1))
                wall += 1;
        if (is_outofthemap(map, x + 1, y) || is_a_wall(map, x + 1, y))
        {
                wall += 2;
                link *= 2;
        }
        if (is_outofthemap(map, x, y + 1) || is_a_wall(map, x, y + 1))
        {
                wall += 3;
                link *= 3;
        }
        if (is_outofthemap(map, x - 1, y) || is_a_wall(map, x - 1, y))
        {
                wall += 4;
                link *= 4;
        }
        return (special_case(wall, link));
}

#include <stdio.h>

int	which_wall(t_map *map, int x, int y, int size)
{
	int	big_x;
	int	big_y;
	char	wall;

	big_x = x / size;
	big_y = y / size;
	if (map->map[big_y][big_x] == '1')
		map->map[big_y][big_x] = get_wall(map, big_x, big_y);
	wall = map->map[big_y][big_x];
	big_x = x % size;
	big_y = y % size;
	return (get_color_block1(wall - '2', 48 * big_y + big_x));
}
