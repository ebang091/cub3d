/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_cub3d.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghwk <seunghwk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 15:11:41 by seunghwk          #+#    #+#             */
/*   Updated: 2023/03/09 11:25:02 by seunghwk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUN_CUB3D_H
# define RUN_CUB3D_H

# include <math.h>

# include "global.h"
# include "mlx.h"
# include "utils/error.h"

// run_cub3d.c
void	run_cub3d(t_window *window);

// draw_cub3d.c
int		draw_cub3d(t_window *window);

// key_press.c
int		key_press(int keycode, t_window *winodw);
int		close_win(t_window *window);

// ray_casting.c
void	get_ray_distance(t_vec vec, t_ray *ray, int x);
void	get_hit_point_using_dda(t_window *window, t_ray *ray);
void	get_draw_start_end_point(t_vec vec, t_ray *ray, t_wall *wall);

#endif // RUN_CUB3D_H
