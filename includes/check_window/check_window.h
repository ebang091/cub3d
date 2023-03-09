/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_window.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghwk <seunghwk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:26:59 by seunghwk          #+#    #+#             */
/*   Updated: 2023/03/09 12:10:37 by seunghwk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_WINDOW_H
# define CHECK_WINDOW_H

# include <stdbool.h>

# include "global.h"
# include "utils/error.h"
# include "utils/free.h"

// check_window.c
int	check_window(t_window *window);

// check_surrounded_by_walls.c
int	check_surrounded_by_walls(t_map map);

#endif
