/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghwk <seunghwk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:01:22 by seunghwk          #+#    #+#             */
/*   Updated: 2023/02/27 16:48:10 by seunghwk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing/parsing.h"

static int	mapchar_to_worldmap(t_window *window);
static int check_map_character(t_window *window);
static int check_map_contents_count(t_window *window);
static int	**return_array(int row, int col);
static int is_direction(char c);

int	parsing(t_window *window, char *file)
{
	int		fd;
	char	**raw_map;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (ft_put_error("Map Error\n"));
	//parse_element;
	//parse_map;
	if (check_path_and_rgb(window, fd) == FAILURE)
		return (FAILURE);
	if (mapchar_to_worldmap(window) == FAILURE)
		return (FAILURE);
	if (check_map_character(window) == FAILURE)
		return (FAILURE);
	if (check_map_contents_count(window) == FAILURE)
		return (FAILURE);
	print_map_utils(window);
	return (SUCCESS);
}

static int	mapchar_to_worldmap(t_window *window)
{
	int		i;
	int		j;

	i = -1;
	window->worldmap = return_array(window->map_row, window->map_col);
	if (!window->worldmap)
		exit_error("Error\nmalloc worldmap\n");
	//norm 때문에 이 아래 -1로 초기화 하는 거 memset 으로 바꾸고 싶습니당
	while (++i < window->map_row)
	{
		j = -1;
		while(++j < window->map_col)
			window->worldmap[i][j] = -1;
	}
	i = -1;
	//그 다음 복사 시작
	while (++i < window->map_row)
	{
		j = -1;
		while (window->map_char[i][++j] != '\0')
			if (ft_isdigit(window->map_char[i][j]))
				window->worldmap[i][j] = window->map_char[i][j] - '0';
			else if (ft_isalpha(window->map_char[i][j]))
				window->worldmap[i][j] = window->map_char[i][j];// WNES는 그대로 받아서 저장
			else
				continue;
	}
	return (SUCCESS);
}

static int check_map_character(t_window *window)
{
	int		i;
	int		j;
	int		flag;

	i = -1;
	flag = 0;
	while (++i < window->map_row)
	{
		j = -1;
		while (++j < window->map_col)
		{
			if (window->worldmap[i][j] == 1 || window->worldmap[i][j] == 0 || ft_isspace(window->worldmap[i][j]) || window->worldmap[i][j] == -1)
				continue;
			else if (is_direction(window->worldmap[i][j]) == TRUE && !flag)
			{
				window->pos_x = j;
				window->pos_y = i;
				window->direction = window->worldmap[i][j];
				window->character_count++;
				window->worldmap[i][j] = CHARACTER;

				flag = 1;
			}
		}
	}
	return (SUCCESS);
}

static int check_map_contents_count(t_window *window)
{
	//return 으로 바꾸기
	if (window->exist_flag != 4)
		return (ft_put_error("Error\n map argument\n"));
	if (window->floor.r == -1 || window->floor.b == -1 || window->floor.g == -1)
		return (ft_put_error("Error\n floor rgb"));
	if (window->floor.r >= 256 || window->floor.b >= 256 || window->floor.g >= 256)
		return (ft_put_error("Error\n floor rgb more than 255"));
	if (window->ceiling.r == -1 || window->ceiling.g == -1 || window->ceiling.b == -1)
		return (ft_put_error("Error\n ceiling rgb\n"));
	if (window->ceiling.r >= 256 || window->ceiling.g >= 256 || window->ceiling.b >= 256)
		return (ft_put_error("Error\n ceiling rgb more than 255"));
	if (window->pos_x== -1 || window->pos_y == -1 || window->character_count != 1)
		{
			printf("\n pos: %d %d %d\n", window->pos_x, window->pos_y, window->character_count);
			return (ft_put_error("Error\n character"));
		}
	if (window->map_col == 0 || window->map_row == 0)
		return (ft_put_error("Error\n map shape\n"));
	if (window->direction == -1)
		return (ft_put_error("Error\n character direction"));
	if (window->worldmap == 0)
		return (ft_put_error("Error\nmap"));
	return (SUCCESS);
}

static int	**return_array(int row, int col)
{
	int		**tmp;
	int		i;

	i = -1;
	tmp = (int **)malloc(sizeof(int*) * row);
	if(!tmp)
		exit_error("Error malloc\n");
	while (++i <= row)
	{
		tmp[i] = (int *)malloc(sizeof(int) * col);
		if (!tmp[i])
		{
			ft_clean(tmp, i);
			exit_error("Error\nmalloc");
		}
	}
	return (tmp);
}

static int is_direction(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (TRUE);
	return (FALSE);
}
