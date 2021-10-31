/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   import_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 16:52:50 by rsanchez          #+#    #+#             */
/*   Updated: 2021/10/31 17:20:55 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

static void	map_malloc2(t_map *map, int size, char **array, int *arr_x)
{
	int	i;

	i = 0;
	while (i <= size)
	{
		if (i < size / 2 && map->map)
		{
			array[i] = map->map[i];
			arr_x[i] = map->x[i];
		}
		else
		{
			array[i] = NULL;
			arr_x[i] = -1;
		}
		i++;
	}
}

static int	map_malloc(t_game *game, t_map *map, int size)
{
	char	**array;
	int		*arr_x;

	array = malloc(sizeof(char *) * (size + 1));
	if (!array)
		exit_program(game, TRUE, "malloc error\n", 13);
	arr_x = malloc(sizeof(int) * (size + 1));
	if (!arr_x)
	{
		free(array);
		exit_program(game, TRUE, "malloc error\n", 13);
	}
	map_malloc2(map, size, array, arr_x);
	if (map->map)
		free(map->map);
	map->map = array;
	if (map->x)
		free(map->x);
	map->x = arr_x;
	return (size);
}

static void	check_elements(t_game *game, t_map *map, int y, char *line)
{
	int		x;
	t_list	*new;

	x = -1;
	while (line[++x])
	{
		if (line[x] == 'P' || line[x] == 'C'
			|| line[x] == 'E' || line[x] == 'M')
		{
			new = lst_new(x, y);
			if (!new)
				exit_program(game, TRUE, "malloc error\n", 13);
			else if (line[x] == 'P')
				lst_addfront(&(map->origin), new);
			else if (line[x] == 'C')
				lst_addfront(&(map->item), new);
			else if (line[x] == 'E')
				lst_addfront(&(map->exit), new);
			else if (line[x] == 'M')
				lst_addfront(&(map->monster), new);
		}
		else if (line[x] != '0' && line[x] != '1' && line[x] != ' ')
			exit_program(game, TRUE, "unknown map char\n", 17);
	}
}

static void	read_file(t_game *game, t_map *map, int fd, int arr_size)
{
	BOOL	eof;
	char	*buffer;
	int	y;

	eof = FALSE;
	buffer = NULL;
	y = 0;
	while (!eof)
	{
		if (y == arr_size)
			arr_size = map_malloc(game, map, arr_size * 2);
		map->x[y] = get_next_line(fd, &buffer, &(map->map[y]), &eof);
		if (map->max_x < map->x[y])
			map->max_x = map->x[y];
		if (map->x[y] == -1)
		{
			free(buffer);
			exit_program(game, TRUE, "gnl error\n", 10);
		}
		check_elements(game, map, y, map->map[y]);
		y++;
	}
	map->max_y = y - 1;
}

void	import_map(t_game *game, t_map *map, char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit_program(game, TRUE, __FUNCTION__, -1);
	read_file(game, map, fd, map_malloc(game, map, 20));
	close(fd);
	if (map->max_x > 1000 || map->max_y > 1000)
		exit_program(game, TRUE, "map too big\n", 12);
	if (!(map->origin) || !(map->item) || !(map->exit))
		exit_program(game, TRUE, "missing mandatory map elements\n", 31);
	if (!is_endedmap(game, map))
		exit_program(game, TRUE, "not ended map\n", 14);
}
