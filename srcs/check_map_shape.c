/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_shape.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjungbang <eunjungbang@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 19:51:15 by eunjungbang       #+#    #+#             */
/*   Updated: 2023/02/26 21:49:24 by eunjungbang      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/cub3d.h"
static int	check_surrounded_by_walls_bfs(t_window *window);
static int create_visited(t_window *window);
static int free_bfs(t_window *window);
static int check_map_edge(t_window *window);

int check_map_shape(t_window *window)
{
	if (check_map_bfs(window) == ERROR)//벽으로 둘러싸여 있는지 확인 : 빈칸일 때 BFS를 수행해서 밖으로 나가지 않는가.
		return (ERROR);
	if (check_map_edge(window) == ERROR)//벽 확인: 가장자리만 따로: -1 혹은 1로만 이루어져 있나.
		return (ERROR);// : 가장자리가 1또는 -1이면 ok
	return (SUCCESS);
}

static int check_map_edge(t_window *window)
{
	int	i;
	int	j;

	i = -1;
	while (++i < window->map_row)
	{
		if (i == 0 || i == window->map_row - 1)
		{
			j = -1;
			while (++j < window->map_col)
				if (window->worldmap[i][j] != 1 && window->worldmap[i][j] != -1)
					return (1);
		}
		else
		{
			if (window->worldmap[i][0] != 1 && window->worldmap[i][0] != -1)
				return (1);
			else if (window->worldmap[i][window->map_col - 1] != 1 && window->worldmap[i][window->map_col -1] != -1)
				return (1);
		}
	}
	return (0);
}


