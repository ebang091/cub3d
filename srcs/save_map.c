/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjungbang <eunjungbang@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 16:22:31 by eunjungbang       #+#    #+#             */
/*   Updated: 2023/02/26 21:31:18 by eunjungbang      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/cub3d.h"
static int	mapchar_to_worldmap(t_window *window);
static int check_map_character(t_window *window);
static int check_map_contents_count(t_window *window);


int save_map(t_window *window, char *path)
{
	int fd;
	fd = open(path , O_RDONLY);
	if (fd == -1)
		return (ft_put_error("Map Error\n"));
	if (check_path_and_rgb(window, fd) == ERROR)//위치 <save_path_and_rgb.c> - path, rgb값을 떼와서 저장한다. 이때 map_col, map_row를 센다. 
		return (ERROR);
	if (mapchar_to_worldmap(window) == ERROR)//map_char 문자열을 int 형으로 저장. 
		return (ERROR);
	if (check_map_character(window) == ERROR)//캐릭터 위치를 찾아서 window구조체의 posx, posy, direction에 저장.
		return (ERROR);
	if (check_map_contents_count(window) == ERROR) //저장된 값들이 정상인지 확인 : 초기 값과 같지 않도록. , rgb의 경우 256초과하지 않도록. (음수인 경우는 '-'때문에 check_map_components 내부의 get_rgb함수의 ft_isdigit()함수에서 걸러진다.)
		return (ERROR);
	print_map_utils(window);// 위치 <etc.c> - 확인용 함수 : 저장된 값들을 출력한다. (나중에 지울 것)
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
				window->worldmap[i][j] = alphatodefnum(window->map_char[i][j]);//공백이나 WNES받아서 저장	
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
			else if (is_directionnum(window->worldmap[i][j]) && !flag)
			{
				window->pos_x = j;
				window->pos_y = i;
				window->direction = window->worldmap[i][j];
				window->character_count++;
				flag = 1;
			}	
		}
	}
	return (SUCCESS);
}

static int check_map_contents_count(t_window *window)
{
	//return 으로 바꾸기
	if (window->exist_flag != 16)
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
		return (ft_put_error("Error\n character"));
	if (window->map_col == 0 || window->map_row == 0)
		return (ft_put_error("Error\n map shape\n"));
	if (window->direction == -1) 
		return (ft_put_error("Error\n character direction"));
	if (window->worldmap == 0)
		return (ft_put_error("Error\nmap"));
	return (SUCCESS);
}
