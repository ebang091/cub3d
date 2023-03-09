/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghwk <seunghwk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:26:16 by seunghwk          #+#    #+#             */
/*   Updated: 2023/03/09 16:04:00 by seunghwk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_window/check_window.h"

static int	check_path(t_window *window);
static int	check_rgb(t_window *window);
static int	check_map(t_window *window);
static int	check_edge(t_map map);

int	check_window(t_window *window)
{
	if (check_path(window) == FAILURE || \
		check_rgb(window) == FAILURE || \
		check_map(window) == FAILURE)
	{
		free_window(window);
		return (FAILURE);
	}
	return (SUCCESS);
}

static int	check_path(t_window *window)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (window->path[i] == NULL)
			return (print_error("Invalid path element\n"));
		++i;
	}
	return (SUCCESS);
}

static int	check_rgb(t_window *window)
{
	if (window->floor.r == -1 || window->ceiling.r == -1)
		return (print_error("Invalid rgb element\n"));
	return (SUCCESS);
}

static int	check_map(t_window *window)
{
	if (check_edge(window->map) == FAILURE || \
		check_surrounded_by_walls(window->map) == FAILURE)
		return (print_error("Invalid map element\n"));
	return (SUCCESS);
}

static int	check_edge(t_map map)
{
	int		i;
	char	**worldmap;

	worldmap = map.worldmap;
	i = 0;
	while (i < map.width)
	{
		if ((worldmap[0][i] != EMPTY && worldmap[0][i] != WALL) || \
			(worldmap[map.height - 1][i] != EMPTY && \
			worldmap[map.height - 1][i] != WALL))
			return (FAILURE);
		++i;
	}
	i = 0;
	while (i < map.height)
	{
		if ((worldmap[i][0] != EMPTY && worldmap[i][0] != WALL) || \
			(worldmap[i][map.width - 1] != EMPTY && \
			worldmap[i][map.width - 1] != WALL))
			return (FAILURE);
		++i;
	}
	return (SUCCESS);
}
