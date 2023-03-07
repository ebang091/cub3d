/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebang <ebang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:43:05 by seunghwk          #+#    #+#             */
/*   Updated: 2023/03/07 22:15:58 by ebang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"
#include "set_window/set_window.h"
#include "check_window/check_window.h"
#include "run_cub3d/run_cub3d.h"
#include "utils/error.h"
#include <stdlib.h>
static int	check_arguments(char **argv);
static void	init_window(t_window *window);

void check_leak()
{
	system("leaks cub3d");
}

int	main(int argc, char **argv)
{
	t_window	window;

	atexit(check_leak);
	if (argc != 2 || check_arguments(argv) == FAILURE)
		return (ft_put_error("Error\nInvalid argument\n"));
	init_window(&window);
	if (set_window(&window, argv[1]) == FAILURE)
		return (FAILURE);
	if (check_window(&window) == FAILURE)
		return (FAILURE);
	init_cub3d(&window);
	run_cub3d(&window);
	
	return (SUCCESS);
}

static int	check_arguments(char **argv)
{
	int	len;

	len = (int)ft_strlen(argv[1]);
	if (len <= 4 || ft_strncmp(argv[1] + len - 4, ".cub", 4) != 0)
		return (FAILURE);
	return (SUCCESS);
}

static void	init_window(t_window *window)
{
	ft_memset(&window->images.path, 0, sizeof(char *) * 4);
	window->map.height = 0;
	window->map.width = 0;
	window->map.worldmap = NULL;
	window->player.direction = 0;
	window->floor.r = -1;
	window->ceiling.r = -1;
}
