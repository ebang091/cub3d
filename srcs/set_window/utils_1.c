/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghwk <seunghwk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:27:13 by seunghwk          #+#    #+#             */
/*   Updated: 2023/03/09 15:46:58 by seunghwk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set_window/set_window.h"

int	atoi_rgb(const char *str)
{
	int	num;

	num = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		++str;
	if (*str == '+')
		++str;
	if (*str == '-')
		return (-1);
	while (*str >= '0' && *str <= '9')
		num = (num * 10) + *str++ - '0';
	if ((*str == '\0' || *str == '\n') && num <= 255)
		return (num);
	else
		return (-1);
}

int	set_rgb_strings(t_window *window, int **rgb, \
	char ***rgb_strings, char *line)
{
	char		**splited_line;

	splited_line = ft_split(line, ' ');
	if (matrix_row_len(splited_line) != 2)
		return (free_matrix(splited_line));
	if (ft_strncmp(splited_line[0], "C", 2) == 0 && window->ceiling.r == -1)
		*rgb = (int *) &window->ceiling;
	else if (ft_strncmp(splited_line[0], "F", 2) == 0 && window->floor.r == -1)
		*rgb = (int *) &window->floor;
	else
		return (free_matrix(splited_line));
	*rgb_strings = ft_split(splited_line[1], ',');
	if (matrix_row_len(*rgb_strings) != 3)
	{
		free_matrix(*rgb_strings);
		return (free_matrix(splited_line));
	}
	free_matrix(splited_line);
	return (SUCCESS);
}
