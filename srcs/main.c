/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baekgang <baekgang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:43:05 by seunghwk          #+#    #+#             */
/*   Updated: 2023/03/04 00:14:57 by baekgang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"
#include "set_window/set_window.h"
#include "check_window/check_window.h"
#include "utils/error.h"

static int	check_arguments(char **argv);
static void	init_window(t_window *window);
//static void	print_window(t_window window);

int	main(int argc, char **argv)
{
	t_window	window;

	if (argc != 2 || check_arguments(argv) == FAILURE)
		return (ft_put_error("Error\nInvalid argument\n"));
	init_window(&window);
	if (set_window(&window, argv[1]) == FAILURE)
		return (FAILURE);
	if (check_window(&window) == FAILURE)
	 	return (FAILURE);
//	print_window(window);
	return (0);
}

static int	check_arguments(char **argv)
{
	int	len;

	len = (int)ft_strlen(argv[1]);
	if (ft_strncmp(argv[1] + len - 4, ".cub", 4) != 0)
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

// #include <stdio.h>
// static void	print_window(t_window window)
// {
// 	int	i;

// 	i = 0;
// 	while (i < 4)
// 	{
// 		printf("%s\n", window.images.path[i]);
// 		++i;
// 	}
// 	printf("ceiling\t: %d, %d, %d\n", window.ceiling.r, window.ceiling.g, window.ceiling.b);
// 	printf("floor\t: %d, %d, %d\n", window.floor.r, window.floor.g, window.floor.b);
// 	printf("player\t: %d, %d, %c\n", window.player.pos_x, window.player.pos_y, window.player.direction);
// 	i = 0;
// 	printf("map width : %d, height : %d\n", window.map.width, window.map.height);
// 	while (i < window.map.height)
// 	{
// 		printf("%s\n", window.map.worldmap[i]);
// 		++i;
// 	}
// }
