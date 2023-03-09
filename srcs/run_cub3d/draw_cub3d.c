/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_cub3d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghwk <seunghwk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 15:46:44 by seunghwk          #+#    #+#             */
/*   Updated: 2023/03/09 16:26:35 by seunghwk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "run_cub3d/run_cub3d.h"

static void	draw_floor_ceiling(t_window *window);
static void	draw_window(t_window *window);
static void	draw_buffer_one(t_window *window, t_wall wall, t_ray *ray, int x);

int	draw_cub3d(t_window *window)
{
	int		x;
	t_ray	ray;
	t_wall	wall;

	draw_floor_ceiling(window);
	x = 0;
	while (x < WINDOW_X)
	{
		get_ray_distance(window->vec, &ray, x);
		get_hit_point_using_dda(window, &ray);
		get_draw_start_end_point(window->vec, &ray, &wall);
		draw_buffer_one(window, wall, &ray, x);
		++x;
	}
	draw_window(window);
	return (SUCCESS);
}

static void	draw_floor_ceiling(t_window *window)
{
	int	ceiling_rgb;
	int	floor_rgb;
	int	x;
	int	y;

	ceiling_rgb = (window->ceiling.r << 16) + (window->ceiling.g << 8) \
		+ window->ceiling.b;
	floor_rgb = (window->floor.r << 16) + (window->floor.g << 8) \
		+ window->floor.b;
	x = 0;
	while (x < WINDOW_X)
	{
		y = 0;
		while (y < WINDOW_Y / 2)
		{
			window->temp[y][x] = ceiling_rgb;
			window->temp[WINDOW_Y - y - 1][x] = floor_rgb;
			y++;
		}
		x++;
	}
}

static void	draw_window(t_window *window)
{
	int	x;
	int	y;

	y = 0;
	while (y < WINDOW_Y)
	{
		x = 0;
		while (x < WINDOW_X)
		{
			window->img.data[y * WINDOW_X + x] = window->temp[y][x];
			++x;
		}
		++y;
	}
	mlx_put_image_to_window(window->mlx, window->win, \
		window->img.img_ptr, 0, 0);
}

static void	draw_buffer_one(t_window *window, t_wall wall, t_ray *ray, int x)
{
	double	step;
	double	tex_pos;
	int		i;
	int		tex_y;
	int		color;

	step = 1.0 * TEXTURE_SIZE / wall.line_h;
	tex_pos = (wall.draw_start - WINDOW_Y / 2 + wall.line_h / 2) * step;
	i = wall.draw_start;
	while (i <= wall.draw_end)
	{
		tex_y = (int)tex_pos & (TEXTURE_SIZE - 1);
		tex_pos += step;
		color = window->texture[ray->side][TEXTURE_SIZE * tex_y + wall.tex_x];
		if (ray->side == WEST || ray->side == SOUTH)
			color = (color >> 1) & 8355711;
		window->temp[i][x] = color;
		i++;
	}
}
