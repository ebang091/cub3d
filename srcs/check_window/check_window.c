/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebang <ebang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:26:16 by seunghwk          #+#    #+#             */
/*   Updated: 2023/03/07 22:19:41 by ebang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_window/check_window.h"

static int	check_path(t_window *window);
static int	check_rgb(t_window *window);
static int	check_map(t_window *window);
static int	check_edge(t_map map);

int	check_window(t_window *window)
{
	if (check_path(window) == FAILURE)
		return (FAILURE);
	if (check_rgb(window) == FAILURE)
		return (FAILURE);
	if (check_map(window) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

static int	check_path(t_window *window)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (window->images.path[i] == NULL)
			return (ft_put_error("Error\nInvalid path element\n"));
		++i;
	}
	return (SUCCESS);
}

static int	check_rgb(t_window *window)
{
	if (window->floor.r == -1 || window->ceiling.r == -1)
		return (ft_put_error("Error\n - check\n"));
	return (SUCCESS);
}

static int	check_map(t_window *window)
{
	if (check_edge(window->map) == FAILURE || \
		check_surrounded_by_walls(window->map) == FAILURE )
	{
		free_matrix(window->map.worldmap);
		return (ft_put_error("Error\nInvalid map element\n"));
	}
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
