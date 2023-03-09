/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghwk <seunghwk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 11:47:35 by seunghwk          #+#    #+#             */
/*   Updated: 2023/03/09 16:01:45 by seunghwk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/free.h"

static void	free_path(char	*path[4]);

int	free_matrix(char **matrix)
{
	int	i;

	if (matrix == NULL)
		return (FAILURE);
	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		matrix[i] = NULL;
		++i;
	}
	free(matrix);
	matrix = NULL;
	return (FAILURE);
}

void	free_window(t_window *window)
{
	free_matrix(window->map.worldmap);
	free_path(window->path);
}


static void	free_path(char	*path[4])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (path[i] != NULL)
			free(path[i]);
		++i;
	}
}

