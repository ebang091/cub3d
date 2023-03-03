/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_window.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghwk <seunghwk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:26:59 by seunghwk          #+#    #+#             */
/*   Updated: 2023/03/03 14:44:08 by seunghwk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_WINDOW_H
# define CHECK_WINDOW_H

# include "global.h"
# include "set_window/set_window.h"
# include "queue/queue.h"
# include "utils/error.h"

// check_window.c
int	check_window(t_window *window);

// check_surrounded_by_walls.c
int	check_surrounded_by_walls(t_map map);

#endif
