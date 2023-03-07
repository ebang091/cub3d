/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_cub3d.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghwk <seunghwk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 15:11:41 by seunghwk          #+#    #+#             */
/*   Updated: 2023/03/06 20:21:40 by seunghwk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUN_CUB3D_H
# define RUN_CUB3D_H

# include <math.h>

# include "global.h"
# include "../mlx/mlx.h"
# include "utils/error.h"

// run_cub3d.c
void	run_cub3d(t_window *window);

// init_cub3d.c
void	init_cub3d(t_window *window);

// draw_cub3d.c
int		draw_cub3d(t_window *window);

// key_press.c
int		key_press(int keycode, t_window *winodw);
int		close_win(t_window *window);

// ray_casting.c
void	set_ray(t_vec vec, t_ray *ray, int x);
void	calc_ray(t_vec vec, t_ray *ray, int x);
void	dda(t_window *window, t_ray *ray);
double	calc_dis(t_vec vec, t_ray *ray);
void	calc_wall(t_vec vec, t_ray *ray, t_wall *wall);
void	map_line(t_window *window, t_wall wall, int x);

#endif // RUN_CUB3D_H
