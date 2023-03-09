/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_surrounded_by_walls.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghwk <seunghwk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:40:36 by seunghwk          #+#    #+#             */
/*   Updated: 2023/03/09 10:42:58 by seunghwk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_window/check_window.h"

static char	**init_visited(t_map map);
static int	dfs(t_map map, char **visited, int y, int x);
static void	set_next_coordinate(int *x, int *y, int direction);
static bool	check_coordinate(t_map map, int x, int y);

int	check_surrounded_by_walls(t_map map)
{
	char	**visited;
	int		i;
	int		j;

	visited = init_visited(map);
	i = 0;
	while (i < map.height)
	{
		j = 0;
		while (j < map.width)
		{
			if ((map.worldmap[i][j] == FLOOR && visited[i][j] == 'X'))
			{
				if (dfs(map, visited, i, j) == FAILURE)
					return (free_matrix(visited));
			}
			++j;
		}
		++i;
	}
	free_matrix(visited);
	return (SUCCESS);
}

static char	**init_visited(t_map map)
{
	char	**matrix;
	int		i;

	i = 0;
	matrix = (char **) malloc(sizeof(char *) * (map.height + 1));
	if (matrix == NULL)
		exit_error("Failed memory allocation\n");
	while (i < map.height)
	{
		matrix[i] = (char *) malloc(sizeof(char) * map.width);
		if (matrix[i] == NULL)
			exit_error("Failed memory allocation\n");
		ft_memset(matrix[i], 'X', map.width);
		i++;
	}
	matrix[i] = NULL;
	return (matrix);
}

static int	dfs(t_map map, char **visited, int y, int x)
{
	int		direction;
	int		ny;
	int		nx;

	visited[y][x] = 'O';
	direction = 0;
	while (direction < 4)
	{
		ny = y;
		nx = x;
		set_next_coordinate(&ny, &nx, direction);
		if (check_coordinate(map, ny, nx) == false)
			continue ;
		if (map.worldmap[ny][nx] == EMPTY)
			return (FAILURE);
		if (map.worldmap[ny][nx] == FLOOR && visited[ny][nx] == 'X')
		{
			if (dfs(map, visited, ny, nx) == FAILURE)
				return (FAILURE);
		}
		++direction;
	}
	return (SUCCESS);
}

static void	set_next_coordinate(int *ny, int *nx, int direction)
{
	if (direction == NORTH)
		*ny += -1;
	else if (direction == SOUTH)
		*ny += 1;
	else if (direction == WEST)
		*nx += -1;
	else if (direction == EAST)
		*nx += 1;
}

static bool	check_coordinate(t_map map, int ny, int nx)
{
	if (ny < 0 || ny >= map.height || nx < 0 || nx >= map.width)
		return (false);
	return (true);
}
