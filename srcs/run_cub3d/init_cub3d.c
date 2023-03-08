/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cub3d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebang <ebang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 17:18:51 by seunghwk          #+#    #+#             */
/*   Updated: 2023/03/08 17:44:42 by ebang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "run_cub3d/run_cub3d.h"

static void	init_vec(t_window *winidow);
static void	init_temp(t_window *window);
static void	init_texture(t_window *window);
static void	save_image_as_xpm(t_window *window, char *path, int direction);

void	init_cub3d(t_window *window)
{
	window->mlx = mlx_init();
	window->win = mlx_new_window(window->mlx, WINDOW_X, WINDOW_Y, "cub3d");
	init_vec(window);
	init_temp(window);
	init_texture(window);
	window->img.img_ptr = mlx_new_image(window->mlx, \
		WINDOW_X, WINDOW_Y);
	window->img.data = (unsigned int *)mlx_get_data_addr(window->img.img_ptr, \
		&window->img.bpp, &window->img.size_l, &window->img.endian);
}

static void	init_vec(t_window *window)
{
	window->vec.pos_x = (double) window->player.pos_x + 0.5;
	window->vec.pos_y = (double) window->player.pos_y + 0.5;
	window->vec.dir_x = 1;
	window->vec.dir_y = 1;
	window->vec.pln_x = 0.66;
	window->vec.pln_y = 0.66;
	if (window->player.direction == 'N' || window->player.direction == 'S')
	{
		window->vec.dir_x = 0;
		window->vec.pln_y = 0;
		if (window->player.direction == 'N')
			window->vec.dir_y *= -1;
		else
			window->vec.pln_x *= -1;
	}
	if (window->player.direction == 'E' || window->player.direction == 'W')
	{
		window->vec.dir_y = 0;
		window->vec.pln_x = 0;
		if (window->player.direction == 'W')
		{
			window->vec.dir_x *= -1;
			window->vec.pln_y *= -1;
		}
	}
}

static void	init_temp(t_window *window)
{
	int		i;

	window->temp = malloc(sizeof(int *) * WINDOW_Y);
	if (window->temp == NULL)
		exit_error("Error\nFailed memory allocation\n");
	i = 0;
	while (i < WINDOW_Y)
	{
		window->temp[i] = malloc(sizeof(int) * WINDOW_X);
		if (window->temp[i] == NULL)
			exit_error("Error\nFailed memory allocation\n");
		ft_memset(window->temp[i], 0, sizeof(int) * WINDOW_X);
		i++;
	}
}

static void	init_texture(t_window *window)
{
	int	direction;

	direction = 0;
	while (direction < 4)
	{
		window->texture[direction] = \
			malloc(sizeof(int) * TEXTURE_X * TEXTURE_Y);
		if (window->texture[direction] == NULL)
			exit_error("Error\nFailed memory allocation\n");
		ft_memset(window->texture[direction], 0, \
			sizeof(int) * TEXTURE_X * TEXTURE_Y);
		save_image_as_xpm(window, window->images.path[direction], direction);
		++direction;
	}
}

static void	save_image_as_xpm(t_window *window, char *path, int direction)
{
	t_img	img;
	int		width;
	int		height;
	int		x;
	int		y;

	img.img_ptr = mlx_xpm_file_to_image(window->mlx, path, &width, &height);
	if (img.img_ptr == NULL)
		exit_error("Error\nInvalid path element\n");
	img.data = (unsigned int *)mlx_get_data_addr(img.img_ptr, \
		&img.bpp, &img.size_l, &img.endian);
	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			window->texture[direction][width * y + x] = img.data[width * y + x];
			++x;
		}
		++y;
	}
	mlx_destroy_image(window->mlx, img.img_ptr);
}
