/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_shape.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjungbang <eunjungbang@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 19:51:15 by eunjungbang       #+#    #+#             */
/*   Updated: 2023/02/26 19:51:23 by eunjungbang      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/cub3d.h"

int map_shape(t_window *window)
{
	if (check_map_bfs(window))//벽으로 둘러싸여 있는지 확인 : 빈칸일 때 BFS를 수행해서 밖으로 나가지 않는가.
		return(1);
	if (check_map_edge(window))//벽 확인: 가장자리만 따로: -1 혹은 1로만 이루어져 있나.
		return (1);// : 가장자리가 1또는 -1이면 ok
}