/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebang <ebang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 19:16:00 by seunghwk          #+#    #+#             */
/*   Updated: 2023/03/07 22:41:09 by ebang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "run_cub3d/run_cub3d.h"

static void	set_ray(t_vec vec, t_ray *ray, int x);
static double	get_wall_x(t_vec vec, t_ray *ray);

void	get_ray_distance(t_vec vec, t_ray *ray, int x)
{
	set_ray(vec, ray, x);
	if (ray->raydir_x < 0)
	{
		ray->step_x = -1;
		ray->sidedist_x = (vec.pos_x - ray->map_x) * ray->deltadist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->sidedist_x = (ray->map_x + 1.0 - vec.pos_x) * ray->deltadist_x;
	}
	if (ray->raydir_y < 0)
	{
		ray->step_y = -1;
		ray->sidedist_y = (vec.pos_y - ray->map_y) * ray->deltadist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->sidedist_y = (ray->map_y + 1.0 - vec.pos_y) * ray->deltadist_y;
	}
}

static void	set_ray(t_vec vec, t_ray *ray, int x)
{
	ray->cam_x = 2 * x / (double)WINDOW_X - 1;
	ray->raydir_x = vec.dir_x + vec.pln_x * ray->cam_x;
	ray->raydir_y = vec.dir_y + vec.pln_y * ray->cam_x;
	ray->map_x = (int) vec.pos_x;
	ray->map_y = (int) vec.pos_y;
	ray->deltadist_x = fabs(1 / ray->raydir_x);
	ray->deltadist_y = fabs(1 / ray->raydir_y);
	ray->hit = 0;
}

void	get_hit_point_using_dda(t_window *window, t_ray *ray)
{
	while (ray->hit == 0)
	{
		if (ray->sidedist_x < ray->sidedist_y)
		{
			ray->sidedist_x += ray->deltadist_x;
			ray->map_x += ray->step_x;
			if (ray->step_x == 1)
				ray->side = EAST;
			else
				ray->side = WEST;
		}
		else
		{
			ray->sidedist_y += ray->deltadist_y;
			ray->map_y += ray->step_y;
			if (ray->step_y == 1)
				ray->side = SOUTH;
			else
				ray->side = NORTH;
		}
		if (window->map.worldmap[ray->map_y][ray->map_x] == WALL)
			ray->hit = 1;
	}
}

void	get_draw_start_end_point(t_vec vec, t_ray *ray, t_wall *wall)
{
	double	wall_x;

	wall_x = get_wall_x(vec, ray);
	wall_x -= floor(wall_x);
	wall->line_h = (WINDOW_Y / ray->perp_wall_dist);
	wall->side = ray->side;
	wall->tex_x = (int)(wall_x * (double)TEXTURE_X);
	if(ray->side == SOUTH)
		wall->tex_x = TEXTURE_X - wall->tex_x - 1;
	wall->draw_start = -wall->line_h / 2 + WINDOW_Y / 2;
	if (wall->draw_start < 0)
		wall->draw_start = 0;
	wall->draw_end = wall->line_h / 2 + WINDOW_Y / 2;
	if (wall->draw_end >= WINDOW_Y)
		wall->draw_end = WINDOW_Y - 1;
}

static double	get_wall_x(t_vec vec, t_ray *ray)
{
	double perp_wall_dist;
	if (ray->side == EAST || ray->side == WEST)
		perp_wall_dist = (ray->map_x - vec.pos_x + \
			(1 - ray->step_x) / 2) / ray->raydir_x;
	else
		perp_wall_dist = (ray->map_y - vec.pos_y + \
			(1 - ray->step_y) / 2) / ray->raydir_y;
	ray->perp_wall_dist = perp_wall_dist;
	if (ray->side == EAST || ray->side == WEST)
		return (vec.pos_y + ray->perp_wall_dist * ray->raydir_y);
	else
		return (vec.pos_x + ray->perp_wall_dist * ray->raydir_x);
}

void	draw_buffer_one_by_one(t_window *window, t_wall wall, t_ray *ray, int x)
{
	double	step;
	double	tex_pos;
	int		i;
	int		tex_y;
	int		color;

	step = 1.0 * TEXTURE_Y / wall.line_h;
	tex_pos = (wall.draw_start - WINDOW_Y / 2 + wall.line_h / 2) * step;
	i = wall.draw_start;
	while (i <= wall.draw_end)
	{
		tex_y = (int)tex_pos & (TEXTURE_Y - 1);
		tex_pos += step;
		color = window->texture[ray->side][TEXTURE_X * tex_y + wall.tex_x];
		if(ray->side == WEST) color = (color >> 1) & 8355711;
		window->temp[i][x] = color;
		i++;
	}
}