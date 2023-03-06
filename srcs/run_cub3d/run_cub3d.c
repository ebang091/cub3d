/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_cub3d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghwk <seunghwk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 15:12:38 by seunghwk          #+#    #+#             */
/*   Updated: 2023/03/06 20:59:27 by seunghwk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "run_cub3d/run_cub3d.h"

void	run_cub3d(t_window *window)
{
	window->mlx = mlx_init();
	window->win = mlx_new_window(window->mlx, WINDOW_X, WINDOW_Y, "cub3d");
	init_cub3d(window);
	mlx_loop_hook(window->mlx, &draw_cub3d, window);
	mlx_hook(window->win, KEY_PRESS, 0, &key_press, window->mlx);
	mlx_hook(window->win, X_BUTTON, 0, &close_win, window->mlx);
	mlx_loop(window->mlx);
}
