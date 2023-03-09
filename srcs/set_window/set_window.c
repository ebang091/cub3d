/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghwk <seunghwk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:01:22 by seunghwk          #+#    #+#             */
/*   Updated: 2023/03/09 16:02:00 by seunghwk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set_window/set_window.h"

static int	set_worldmap(t_map *map);
static int	set_player(t_window *window);

int	set_window(t_window *window, char *file)
{
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (print_error("Invalid argument\n"));
	if (set_path_rgb_map(window, fd) == FAILURE || \
		set_worldmap(&window->map) == FAILURE || \
		set_player(window) == FAILURE)
	{
		free_window(window);
		return (FAILURE);
	}
	return (SUCCESS);
}

static int	set_worldmap(t_map *map)
{
	char	**temp_map;
	int		i;

	if (map->height == 0)
		return (print_error("Is no map\n"));
	temp_map = map->worldmap;
	map->worldmap = (char **) malloc(sizeof(char *) * (map->height + 1));
	if (map->worldmap == NULL)
		exit_error("Failed memory allocation\n");
	i = 0;
	while (i < map->height)
	{
		map->worldmap[i] = (char *) malloc(sizeof(char) * (map->width + 1));
		if (map->worldmap[i] == NULL)
			exit_error("Failed memory allocation\n");
		ft_memset(map->worldmap[i], EMPTY, map->width);
		ft_memcpy(map->worldmap[i], temp_map[i], ft_strlen(temp_map[i]));
		map->worldmap[i][map->width] = '\0';
		++i;
	}
	map->worldmap[map->height] = NULL;
	free_matrix(temp_map);
	return (SUCCESS);
}

static int	set_player(t_window *window)
{
	int	i;
	int	j;

	i = -1;
	while (window->map.worldmap[++i])
	{
		j = -1;
		while (window->map.worldmap[i][++j])
		{
			if (is_direction(window->map.worldmap[i][j]) == true)
			{
				if (window->player.direction != 0)
					return (print_error("Is no one player\n"));
				window->player.pos_x = j;
				window->player.pos_y = i;
				window->player.direction = window->map.worldmap[i][j];
				window->map.worldmap[i][j] = FLOOR;
			}
		}
	}
	if (window->player.direction == 0)
		return (print_error("Is no player\n"));
	return (SUCCESS);
}
