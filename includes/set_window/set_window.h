/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_window.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghwk <seunghwk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:02:20 by seunghwk          #+#    #+#             */
/*   Updated: 2023/03/09 15:56:09 by seunghwk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_WINDOW_H
# define SET_WINDOW_H

# include <fcntl.h>
# include <stdbool.h>

# include "global.h"
# include "libft.h"
# include "utils/error.h"
# include "utils/free.h"
# include "utils/get_next_line.h"

enum e_types
{
	PATH = 0,
	RGB = 1,
	MAP = 2,
	NEW_LINE = 3,
	INVALID = 4
};

// set_window.c
int		set_window(t_window *window, char *file);

// set_image_rgb_map.c
int		set_path_rgb_map(t_window *window, int fd);

// utils_0.c
bool	is_map_line(char *line);
int		set_path_type(t_window *window, int type);
int		matrix_row_len(char **matrix);
bool	is_direction(char element);

// utils_1.c
int		atoi_rgb(const char *str);
int		set_rgb_strings(t_window *window, int **rgb, \
		char ***rgb_strings, char *line);

#endif // SET_WINDOW_H
