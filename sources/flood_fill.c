/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 20:08:39 by rsanchez          #+#    #+#             */
/*   Updated: 2021/10/27 16:53:45 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#include <stdio.h>	//test

/*
static BOOL	is_valid(t_map *map, int x, int y)
{
	if (x < 0 || y < 0 || x >= map->max_x || y >= map->max_y
						|| map->map[y][x] == '\0')
		exit_program(map, TRUE, "wrong map\n", 10);
	if (map->map[y][x] == '1' || map->map[y][x] == '8')
		return (FALSE);
	return (TRUE);
}

BOOL	is_endedmap(t_map *map, int x, int y)
{
	map->map[y][x] = '8';
	print_map(map, x, y);
	printf("x: %i, y: %i\n", x, y);
	if (is_valid(map, x - 1, y))
		is_endedmap(map, x - 1, y);
	if (is_valid(map, x + 1, y))
		is_endedmap(map, x + 1, y);
	if (is_valid(map, x, y - 1))
		is_endedmap(map, x, y - 1);
	if (is_valid(map, x, y + 1))
		is_endedmap(map, x, y + 1);
	return (TRUE);
}

static BOOL	is_outofthemap(t_map *map, int x, int y)
{
	if (x < 0 || y < 0)
		return (TRUE);
	if (x >= map->max_x[y] || map->map[y][x] == ' ')
		return (TRUE);
	if (map->map[y] == NULL)
		return (TRUE);
	return (FALSE);
}

BOOL	is_endedmap(t_map *map, int x, int y)
{
	print_map(map);
	if (is_outofthemap(map, x, y))
		return (FALSE);
	else if (map->map[y][x] == '@' || map->map[y][x] == '1')
		return (TRUE);
	map->map[y][x] = '@';
	if (is_endedmap(map, x - 1, y) && is_endedmap(map, x, y - 1)
		&& is_endedmap(map, x + 1, y) && is_endedmap(map, x, y + 1))
		return (TRUE);
	return (FALSE);
}
*/

BOOL	is_outofthemap(t_map *map, int x, int y)
{
	if (x < 0 || y < 0)
		return (TRUE);
	if (x >= map->x[y] || map->map[y][x] == ' ')
		return (TRUE);
	if (map->map[y] == NULL)
		return (TRUE);
	return (FALSE);
}

BOOL	is_a_wall(t_map *map, int x, int y)
{
	if (map->map[y][x] >= '1' && map->map[y][x] <= 'A')
		return (TRUE);
	return (FALSE);
}

static BOOL	is_accessible(t_map *map, int x, int y)
{
	if (is_outofthemap(map, x, y))
		return (FALSE);
	else if (map->map[y][x] == '#' || is_a_wall(map, x, y))
	{
/*		if (map->map[y][x] == '1')
		{
			map->map[y][x] = set_wall(map, x, y);
			printf("%c\n", map->map[y][x]);
		}
*/		return (TRUE);
	}
	return (go_to(map, x, y));
}

BOOL	go_to(t_map *map, int x, int y)
{
	print_map(map);
	map->map[y][x] = '#';
	if (is_accessible(map, x - 1, y) && is_accessible(map, x, y - 1)
		&& is_accessible(map, x + 1, y) && is_accessible(map, x, y + 1))
		return (TRUE);
	return (FALSE);

}

BOOL	is_endedmap(t_scene *scene, t_map *map)
{
	t_list	*tmp;
	char	**copy;
	BOOL	check;

	while (map->origin)
	{
		copy = array_string_duplicate(map->map, map->max_y);
		if (!copy)
			exit_program(scene, TRUE, "malloc error\n", 13);
		check = go_to(map, map->origin->x, map->origin->y);
	print_map(map);
		array_clear((void **)map->map);
		map->map = copy;
		if (check)
			return (TRUE);
		tmp = map->origin;
		map->origin = map->origin->next;
		free(tmp);
	}
	return (FALSE);
}
