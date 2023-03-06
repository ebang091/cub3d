/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baekgang <baekgang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 11:52:07 by baekgang          #+#    #+#             */
/*   Updated: 2023/03/05 12:05:09 by baekgang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "run/run.h"

void	run(t_window *window)
{
	window->mlx = mlx_init();
	if (window->mlx == NULL)
		exit_error("Error\nFailed mlx_init\n");
	window->win = mlx_new_window(window->mlx, SCREENWIDTH, SCREENHEIGHT, "cub3d");
	if (window->win == NULL)
		exit_error("Error\nFailed mlx_new_window");
	init_mlx(window);
}
