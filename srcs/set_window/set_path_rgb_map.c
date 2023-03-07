/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_path_rgb_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebang <ebang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 14:58:52 by seunghwk          #+#    #+#             */
/*   Updated: 2023/03/07 21:39:44 by ebang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set_window/set_window.h"

static int	check_type(t_window *window, char *line);
static int	set_path(t_window *window, char *line);
static int	set_rgb(t_window *window, char *line);
static int	set_map(t_window *window, char *line);

int	set_path_rgb_map(t_window *window, int fd)
{
	char		*line;
	int			type;
	static int	(*set_type[3])(t_window *window, char *line) = {set_path, \
				set_rgb, set_map};

	while (42)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		type = check_type(window, line);
		if ((type == PATH || type == RGB || type == MAP) && \
			set_type[type](window, line) == FAILURE)
		{
			free(line);
			return (FAILURE);
		}
		else if (type == INVALID || (type == NEW_LINE && window->map.height))
		{
			free(line);
			return (ft_put_error("Error\nInvalid argument\n"));
		}
		free(line);
	}
	return (SUCCESS);
}

static int	check_type(t_window *window, char *line)
{
	if (line[0] == '\n')
		return (NEW_LINE);
	else if (ft_strncmp(line, "EA ", 3) == 0 && window->map.height == 0)
		return (set_path_type(window, EAST));
	else if (ft_strncmp(line, "WE ", 3) == 0 && window->map.height == 0)
		return (set_path_type(window, WEST));
	else if (ft_strncmp(line, "SO ", 3) == 0 && window->map.height == 0)
		return (set_path_type(window, SOUTH));
	else if (ft_strncmp(line, "NO ", 3) == 0 && window->map.height == 0)
		return (set_path_type(window, NORTH));
	else if ((line[0] == 'F' || line[0] == 'C') && window->map.height == 0)
		return (RGB);
	else if (is_map_line(line) == true)
	{
		if ((int) ft_strlen(line) - 1 > window->map.width)
			window->map.width = (int) ft_strlen(line) - 1;
		++window->map.height;
		return (MAP);
	}
	else
		return (INVALID);
}

static int	set_path(t_window *window, char *line)
{
	char		**splited_line;
	t_images	*images;
	int			type;

	images = &window->images;
	type = images->type;
	if (images->path[type] != NULL)
		return (ft_put_error("Error\nInvalid path element\n"));
	splited_line = ft_split(line, ' ');
	if (matrix_row_len(splited_line) != 2)
	{
		free_matrix(splited_line);
		return (ft_put_error("Error\nInvalid path element\n"));
	}
	images->path[type] = ft_strdup(splited_line[1]);
	images->path[type][ft_strlen(images->path[type]) - 1] = '\0';
	free_matrix(splited_line);
	return (SUCCESS);
}

static int	set_rgb(t_window *window, char *line)
{
	char	**rgb_strings;
	int		*rgb;
	int		i;

	if (set_rgb_strings(window, &rgb, &rgb_strings, line) == FAILURE)
		return (FAILURE);
	i = 0;
	while (i < 3)
	{
		rgb[i] = atoi_rgb(rgb_strings[i]);
		if (rgb[i] == -1)
		{
			free_matrix(rgb_strings);
			return (ft_put_error("Error\nInvalid rgb element - set rgb\n"));
		}
		++i;
	}
	free_matrix(rgb_strings);
	return (SUCCESS);
}

static int	set_map(t_window *window, char *line)
{
	t_map	*map;
	char	**temp_map;
	int		i;

	map = &window->map;
	temp_map = map->worldmap;
	map->worldmap = (char **) malloc(sizeof(char *) * (map->height + 1));
	if (map->worldmap == NULL)
		exit_error("Error\nFailed memory allocation\n");
	i = 0;
	while (i < map->height - 1)
	{
		map->worldmap[i] = temp_map[i];
		++i;
	}
	line[ft_strlen(line) - 1] = '\0';
	map->worldmap[i++] = ft_strdup(line);
	map->worldmap[i] = NULL;
	free(temp_map);
	return (SUCCESS);
}
