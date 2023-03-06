/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjungbang <eunjungbang@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:43:05 by seunghwk          #+#    #+#             */
/*   Updated: 2023/03/06 14:31:02 by eunjungbang      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"
#include "set_window/set_window.h"
#include "utils/error.h"
#include "../mlx/mlx.h"
#include "../includes/ray_casting/ray_casting.h"

static int	check_arguments(char **argv);
static void	init_window(t_window *window);
static void	print_window(t_window window);
int	press_key(int key_code, t_window *window);

#include <stdio.h>
int	main(int argc, char **argv)
{
	t_window	window;

	if (argc != 2)
		return (ft_put_error("Error\nargument\n"));
	if(check_arguments(argv) == FAILURE)
		return (ft_put_error("Error\nargument\n"));
	init_window(&window);
	if (set_window(&window, argv[1]) == FAILURE)
		return (ft_put_error("fail\n"));
	print_window(window);
	
	
	// window.floor.color = make_bits_rgb(window.floor.r, window.floor.b, window.floor.b);
	// get_direction_vector(&window);
	printf("start!\n");
	// ready_window(&window);
	
	mlx_hook(window.win, 17, 0, key_exit, &window);
	mlx_hook(window.win, X_EVENT_KEY_PRESS, 0, check_key, &window);
	mlx_loop_hook(window.win, ray_casting, &window);
	if(window.mlx == 0)
		{
			printf("wrong mlx!\n");
			return (0);
		}
	mlx_loop(window.mlx);
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
	
	window->mlx = mlx_init();
	window->win = mlx_new_window(window->mlx, SCREENWIDTH,
			SCREENHEIGHT, "cub_3d");
	window->main_image.img = mlx_new_image(window->mlx, SCREENWIDTH, SCREENHEIGHT);
	// window->main_image.data = (int *)mlx_get_data_addr(window->main_image.img, &window->main_image.bpp, &window->main_image.size_l, &window->main_image.endian);
	printf("size of addr: %lu\n", sizeof(window->main_image.data));
	printf("%p %p\n", window->main_image.img, window->main_image.data);
	window->player.pos_x = -1;
	window->player.pos_y = -1;
	window->player.direction = -1;
	window->map.height = 0;
	window->map.width = 0;
	window->map.worldmap = NULL;
	window->floor.r = -1;
	window->floor.g = -1;
	window->floor.b = -1;
	window->ceiling.r = -1;
	window->ceiling.g = -1;
	window->ceiling.b = -1;
}

static void	print_window(t_window window)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		printf("%s\n", window.images.path[i]);
		++i;
	}
	printf("ceiling : %d, %d, %d\n", window.ceiling.r, window.ceiling.g, window.ceiling.b);
	printf("floor : %d, %d, %d\n", window.floor.r, window.floor.g, window.floor.b);
	i = 0;
	while (i < window.map.height)
	{
		printf("%s\n", window.map.worldmap[i]);
		++i;
	}
}
