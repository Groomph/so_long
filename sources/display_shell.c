/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_shell.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 10:09:18 by rsanchez          #+#    #+#             */
/*   Updated: 2021/10/25 10:36:31 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <unistd.h>

void	print_map(t_map *map)
{
	int	i;

	i = 0;
	while (map->map[i])
	{
		write(1, map->map[i], map->x[i]);
		write(1, "\n", 1);
		i++;
	}
}
