/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebang <ebang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 19:16:00 by seunghwk          #+#    #+#             */
/*   Updated: 2023/03/07 16:27:21 by ebang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "run_cub3d/run_cub3d.h"

void	set_ray(t_vec vec, t_ray *ray, int x)
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

void	calc_ray(t_vec vec, t_ray *ray, int x)
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

void	dda(t_window *window, t_ray *ray)
{
	while (ray->hit == 0)
	{
		if (ray->sidedist_x < ray->sidedist_y)
		{
			ray->sidedist_x += ray->deltadist_x;
			ray->map_x += ray->step_x;
			if (ray->step_x == 1)
				ray->side = NORTH;
			else
				ray->side = SOUTH;
		}
		else
		{
			ray->sidedist_y += ray->deltadist_y;
			ray->map_y += ray->step_y;
			if (ray->step_y == 1)
				ray->side = WEST;
			else
				ray->side = EAST;
		}
		if (window->map.worldmap[ray->map_y][ray->map_x] == WALL)
			ray->hit = 1;
	}
}

double	calc_dis(t_vec vec, t_ray *ray)
{
	if (ray->side == 0 || ray->side == 1)
	{
		ray->wall_dist = (ray->map_x - vec.pos_x + \
			(1 - ray->step_x) / 2) / ray->raydir_x;
		if (ray->wall_dist <= 0.000001)
			ray->wall_dist = 0.00001;
		return (vec.pos_y + ray->wall_dist * ray->raydir_y);
	}
	ray->wall_dist = (ray->map_y - vec.pos_y + \
		(1 - ray->step_y) / 2) / ray->raydir_y;
	if (ray->wall_dist <= 0.000001)
		ray->wall_dist = 0.00001;
	return (vec.pos_x + ray->wall_dist * ray->raydir_x);
}

void	calc_wall(t_vec vec, t_ray *ray, t_wall *wall)
{
	double	wall_x;

	wall_x = calc_dis(vec, ray);
	wall_x -= floor(wall_x);
	wall->line_h = (WINDOW_Y / ray->wall_dist);
	wall->side = ray->side;
	wall->tex_x = (int)(wall_x * (double)TEXTURE_X);
	if (((ray->side == NORTH) || (ray->side == SOUTH)) && ray->raydir_x < 0)
		wall->tex_x = TEXTURE_X - wall->tex_x - 1;
	if (((ray->side == WEST) || (ray->side == EAST)) && ray->raydir_y > 0)
		wall->tex_x = TEXTURE_X - wall->tex_x - 1;
	wall->draw_start = -wall->line_h / 2 + WINDOW_Y / 2;
	if (wall->draw_start < 0)
		wall->draw_start = 0;
	wall->draw_end = wall->line_h / 2 + WINDOW_Y / 2;
	if (wall->draw_end >= WINDOW_Y)
		wall->draw_end = WINDOW_Y - 1;
}

void	map_line(t_window *window, t_wall wall, int x)
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
		color = window->texture[wall.side][TEXTURE_X * tex_y + wall.tex_x];
		window->temp[i][x] = color;
		i++;
	}
}
