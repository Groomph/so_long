/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   import_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 16:52:50 by rsanchez          #+#    #+#             */
/*   Updated: 2021/12/08 15:02:20 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

static void	check_elements(t_game *game, t_map *map, int y, char *line)
{
	int		x;

	x = 0;
	while (line[x])
	{
		if (line[x] == 'P')
		{
			if (map->origin_x == -1)
			{
				map->origin_x = x;
				map->origin_y = y;
			}
			else
				line[x] = '0';
		}
		else if (line[x] == 'C')
			map->item++;
		else if (line[x] == 'E')
			map->exit++;
		else if (line[x] != '0' && line[x] != '1')
			exit_program(game, TRUE, "unknown map char\n", 17);
		x++;
	}
}

static void	leave_gnl(t_game *game, char *buffer, int error)
{
	free(buffer);
	if (error == 1)
		exit_program(game, TRUE, "gnl error\n", 10);
	else
		exit_program(game, TRUE, "not rectangular map\n", 20);
}

static void	fill_map(t_game *game, t_map *map, int fd)
{
	BOOL	eof;
	char	*buffer;
	int		y;
	int		size;

	eof = FALSE;
	buffer = NULL;
	y = 0;
	while (!eof)
	{
		size = get_next_line(fd, &buffer, &(map->map[y]), &eof);
		if (size == 0 && eof)
		{
			free(map->map[y]);
			map->map[y] = NULL;
			return ;
		}
		if (size == -1)
			leave_gnl(game, buffer, 1);
		check_elements(game, map, y, map->map[y]);
		y++;
	}
}

static void	get_max_y(t_game *game, t_map *map, int fd)
{
	BOOL	eof;
	char	*buffer;
	char	*line;
	int		size;

	eof = FALSE;
	buffer = NULL;
	line = NULL;
	map->max_y = 0;
	map->max_x = -1;
	while (!eof)
	{
		size = get_next_line(fd, &buffer, &line, &eof);
		free(line);
		if (size == 0 && eof)
			return ;
		if (size == -1)
			leave_gnl(game, buffer, 1);
		if (map->max_x == -1)
			map->max_x = size;
		if (size != map->max_x)
			leave_gnl(game, buffer, 2);
		map->max_y++;
	}
}

void	import_map(t_game *game, t_map *map, char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit_program(game, TRUE, file, -1);
	get_max_y(game, map, fd);
	close(fd);
	map->map = array_malloc(map->max_y + 1);
	if (!(map->map))
		exit_program(game, TRUE, "malloc error\n", 13);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit_program(game, TRUE, file, -1);
	map->origin_x = -1;
	fill_map(game, map, fd);
	close(fd);
	if (map->max_x > 100 || map->max_y > 100)
		exit_program(game, TRUE, "map too big\n", 12);
	if (map->origin_x == -1 || !(map->item) || !(map->exit))
		exit_program(game, TRUE, "missing mandatory map elements\n", 31);
	if (!is_walled(map))
		exit_program(game, TRUE, "not ended map\n", 14);
}
