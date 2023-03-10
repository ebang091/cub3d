/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghwk <seunghwk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 19:53:46 by seunghwk          #+#    #+#             */
/*   Updated: 2023/03/09 11:23:03 by seunghwk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "run_cub3d/run_cub3d.h"

static void	move_front_or_back(t_window *window, double sign);
static void	move_left_or_right(t_window *window, double sign);
static void	rotate(t_window *window, double sign);

int	key_press(int keycode, t_window *window)
{
	if (keycode == KEY_W)
		move_front_or_back(window, 1);
	if (keycode == KEY_S)
		move_front_or_back(window, -1);
	if (keycode == KEY_A)
		move_left_or_right(window, -1);
	if (keycode == KEY_D)
		move_left_or_right(window, 1);
	if (keycode == KEY_LEFT)
		rotate(window, -1);
	if (keycode == KEY_RIGHT)
		rotate(window, 1);
	if (keycode == KEY_ESC)
		close_win(window->mlx);
	return (0);
}

int	close_win(t_window *window)
{
	mlx_clear_window(window->mlx, window->win);
	mlx_destroy_window(window->mlx, window->win);
	exit(0);
}

static void	move_front_or_back(t_window *window, double sign)
{
	t_vec	vec;
	double	des_x;
	double	des_y;

	vec = window->vec;
	des_x = vec.pos_x + (vec.dir_x * (double)MOVE_SPEED / 10 * sign);
	des_y = vec.pos_y + (vec.dir_y * (double)MOVE_SPEED / 10 * sign);
	if (window->map.worldmap[(int)vec.pos_y][(int)des_x] == FLOOR)
		window->vec.pos_x = des_x;
	if (window->map.worldmap[(int)des_y][(int)vec.pos_x] == FLOOR)
		window->vec.pos_y = des_y;
}

static void	move_left_or_right(t_window *window, double sign)
{
	t_vec	vec;
	double	des_x;
	double	des_y;

	vec = window->vec;
	des_x = vec.pos_x + (vec.pln_x * (double)MOVE_SPEED / 10 * sign);
	des_y = vec.pos_y + (vec.pln_y * (double)MOVE_SPEED / 10 * sign);
	if (window->map.worldmap[(int)vec.pos_y][(int)des_x] == FLOOR)
		window->vec.pos_x = des_x;
	if (window->map.worldmap[(int)des_y][(int)vec.pos_x] == FLOOR)
		window->vec.pos_y = des_y;
}

static void	rotate(t_window *window, double sign)
{
	double	dir_x;
	double	pln_x;
	double	rot;

	dir_x = window->vec.dir_x;
	pln_x = window->vec.pln_x;
	rot = (double)ROTATE_SPEED / 10 * sign;
	window->vec.dir_x = (dir_x * cos(rot)) - (window->vec.dir_y * sin(rot));
	window->vec.dir_y = (dir_x * sin(rot)) + (window->vec.dir_y * cos(rot));
	window->vec.pln_x = (pln_x * cos(rot)) - (window->vec.pln_y * sin(rot));
	window->vec.pln_y = (pln_x * sin(rot)) + (window->vec.pln_y * cos(rot));
}
