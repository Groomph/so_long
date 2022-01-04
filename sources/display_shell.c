/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_shell.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 10:09:18 by rsanchez          #+#    #+#             */
/*   Updated: 2021/12/08 16:33:18 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <unistd.h>

void	print_copy(t_map *map)
{
	int	y;

	y = 0;
	while (map->copy[y])
	{
		write(1, map->copy[y], map->max_x);
		write(1, "\n", 1);
		y++;
	}
}

void	print_map(t_map *map)
{
	int	y;

	y = 0;
	while (map->map[y])
	{
		write(1, map->map[y], map->max_x);
		write(1, "\n", 1);
		y++;
	}
}
