/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghwk <seunghwk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 16:42:14 by seunghwk          #+#    #+#             */
/*   Updated: 2023/03/09 15:55:22 by seunghwk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set_window/set_window.h"

int	set_path_type(t_window *window, int type)
{
	window->path_type = type;
	return (PATH);
}

bool	is_map_line(char *line)
{
	int		i;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] == WALL || line[i] == FLOOR || line[i] == EMPTY || \
			line[i] == N || line[i] == S || line[i] == W || \
			line[i] == E || line[i] == ' ')
			++i;
		else
			return (false);
	}
	return (true);
}

int	matrix_row_len(char **matrix)
{
	int	len;

	len = 0;
	while (matrix[len])
		++len;
	return (len);
}

bool	is_direction(char element)
{
	return (element == N || element == S || element == W || element == E);
}
