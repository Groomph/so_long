/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 13:06:23 by rsanchez          #+#    #+#             */
/*   Updated: 2021/12/08 16:27:28 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

BOOL	is_outofthemap(t_map *map, int x, int y)
{
	if (x < 0 || y < 0)
		return (TRUE);
	if (x >= map->max_x || y >= map->max_y)
		return (TRUE);
	return (FALSE);
}

BOOL	is_a_wall(char **map, int x, int y)
{
	if (map[y][x] >= '1' && map[y][x] <= 'A')
		return (TRUE);
	return (FALSE);
}
