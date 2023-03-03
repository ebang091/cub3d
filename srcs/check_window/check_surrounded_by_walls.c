/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_surrounded_by_walls.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghwk <seunghwk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:40:36 by seunghwk          #+#    #+#             */
/*   Updated: 2023/03/03 16:36:27 by seunghwk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_window/check_window.h"

static char	**init_visited(t_map map);
static int	bfs(t_map map, char **visited, t_queue *queue);
static bool	set_next_coordinate(t_map map, int *x, int *y, int direction);
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
				visited[i][j] = 'O';
				if (bfs(map, visited, \
					queue_push(queue_init(), new_node(i, j))) == FAILURE)
					return (ft_put_error("Error\nInvalid map element\n"));
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
	matrix = (char **) malloc(sizeof(char *) * (map.height));
	if (matrix == NULL)
		exit_error("Error\nFailed memory allocation\n");
	while (i < map.height)
	{
		matrix[i] = (char *) malloc(sizeof(char) * map.width);
		if (matrix[i] == NULL)
			exit_error("Error\nFailed memory allocation\n");
		ft_memset(matrix[i], 'X', map.width);
		i++;
	}
	return (matrix);
}
#include <stdio.h>
static int	bfs(t_map map, char **visited, t_queue *queue)
{
	t_node	pop_node;
	int		direction;
	int		y;
	int		x;

	while (queue->head)
	{
		pop_node = queue_pop(queue);
		direction = -1;
		while (++direction < 4)
		{
			y = pop_node.y;
			x = pop_node.x;
			printf("check!\n");
			if (set_next_coordinate(map, &y, &x, direction) && \
				map.worldmap[y][x] == FLOOR && visited[y][x] == 'X')
			{
				visited[y][x] = 'O';
				queue_push(queue, new_node(y, x));
			}
			if (check_coordinate(map, y, x) && map.worldmap[y][x] == EMPTY)
				return (free_queue(queue));
		}
	}
	free(queue);
	return (SUCCESS);
}

static bool	set_next_coordinate(t_map map, int *y, int *x, int direction)
{
	if (direction == NORTH)
		*y -= 1;
	else if (direction == SOUTH)
		*y += -1;
	else if (direction == WEST)
		*x -= 1;
	else if (direction == EAST)
		*x += -1;
	return (check_coordinate(map, *y, *x));
}

static bool	check_coordinate(t_map map, int y, int x)
{
	if (x < 0 || x >= map.width || y < 0 || y >= map.height)
		return (false);
	return (true);
}
