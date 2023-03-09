/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghwk <seunghwk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:43:05 by seunghwk          #+#    #+#             */
/*   Updated: 2023/03/09 16:26:52 by seunghwk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"
#include "set_window/set_window.h"
#include "check_window/check_window.h"
#include "init_cub3d/init_cub3d.h"
#include "run_cub3d/run_cub3d.h"
#include "utils/error.h"

static int	check_arguments(char **argv);
static void	init_window(t_window *window);

int	main(int argc, char **argv)
{
	t_window	window;

	if (argc != 2 || check_arguments(argv) == FAILURE)
		return (print_error("Invalid argument\n"));
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
	ft_memset(&window->path, 0, sizeof(char *) * 4);
	window->map.height = 0;
	window->map.width = 0;
	window->map.worldmap = NULL;
	window->player.direction = 0;
	window->floor.r = -1;
	window->ceiling.r = -1;
}
