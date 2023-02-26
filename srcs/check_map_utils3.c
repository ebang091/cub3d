/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjungbang <eunjungbang@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 21:51:36 by eunjungbang       #+#    #+#             */
/*   Updated: 2023/02/24 22:14:59 by eunjungbang      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	Cango(t_window *window, int y, int x)
{
	if (0 <= y && y <= window->map_row && 0 <= x && x <= window->map_col)
		return (1);
	return (0);
}

int is_directionnum(int c)
{
	if (c == NORTH || c == SOUTH || c == WEST || c == EAST)
		return (1);
	return (0);
}