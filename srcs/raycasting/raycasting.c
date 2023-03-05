/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeselee <yeselee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 23:05:54 by yeselee           #+#    #+#             */
/*   Updated: 2023/03/05 23:21:45 by yeselee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/raycasting/raycasting.h"
#include "stdio.h"

void	ready_window(t_window *window);
void	draw_background(t_window *window);

void	initial_malloc(t_window *window)
{
	window->buffer = (unsigned int *)malloc(sizeof(unsigned int) * SCREENHEIGHT * SCREENWIDTH + 1);
	if (!window->buffer)
		exit_error("Error\nmalloc failed");
}

void	ready_window(t_window *window)
{
	initial_malloc(window);
	printf("st");
	// save_wall_texture(window);
}
