/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjungbang <eunjungbang@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 16:22:31 by eunjungbang       #+#    #+#             */
/*   Updated: 2023/02/26 19:49:08 by eunjungbang      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/cub3d.h"

static void save_map_char(t_window *window, char *str)
{
	//map의 몇번째 줄인지 window->map_row에 저장되어있다. 
	int		i;
	char	**tmp;

	i = 0;
	tmp = (char **)malloc(sizeof(char *) * window->map_row);
	if (!tmp)
		ft_put_error("malloc Error\n");
	while (i < window->map_row - 1)
	{
		tmp[i] = ft_strdup(window->map_char[i]);
		free(window->map_char[i++]);
	}
	tmp[i] = ft_strdup(str);
	if (window->map_row != 1)
		free(window->map_char);
	window->map_char = tmp;
}

static void	mapchar_to_worldmap(t_window *window)
{
	int		i;
	int		j;

	i = -1;
	window->worldmap = return_array(window->map_row, window->map_col);
	while (++i < window->map_row)
	{
		j = -1;
		while(++j < window->map_col)
			window->worldmap[i][j] = -1;
	}
	i = -1;
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
}

static void	check_path_and_rgb(t_window *window, int fd)
{
	char *str;
	
	while (1)
	{
		str = get_next_line(fd);
		if (str == 0)
			break;
		if (is_direction_or_rgb(window, str) == MAP)//N,S,W,E, F,C값이면 RGB혹은 경로 저장, 맵 부분이면 2반환
			save_map_char(window, str);//맵일 때 window->map_char 에 문자열 형태로 저장.
	}
	free(str);
}

static void	check_map_character(t_window *window)
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
}

int check_map_contents_count(t_window *window)
{
	if (window->exist_flag != 16)
		ft_put_error("Error\n map argument\n");
	if (window->floor.r == -1 || window->floor.b == -1 || window->floor.g == -1)
		ft_put_error("Error\n floor rgb");
	if (window->floor.r >= 256 || window->floor.b >= 256 || window->floor.g >= 256)
		ft_put_error("Error\n floor rgb more than 255");
	if (window->ceiling.r == -1 || window->ceiling.g == -1 || window->ceiling.b == -1)
		ft_put_error("Error\n ceiling rgb\n");
	if (window->ceiling.r >= 256 || window->ceiling.g >= 256 || window->ceiling.b >= 256)
		ft_put_error("Error\n ceiling rgb more than 255");
	if (window->pos_x== -1 || window->pos_y == -1 || window->character_count != 1)
		ft_put_error("Error\n character");
	if (window->map_col == 0 || window->map_row == 0)
		ft_put_error("Error\n map shape\n");
	if (window->direction == -1) 
		ft_put_error("Error\n character direction");
	if (window->worldmap == 0)
		ft_put_error("Error\nmap");
	return (0);
}

int save_map(t_window *window, char *path)
{
	int fd;
	fd = open(path , O_RDONLY);
	if (fd == -1)
		ft_put_error("Map Error\n");
	check_path_and_rgb(window, fd);//path, rgb값을 떼와서 저장한다. 이때 map_col, map_row를 센다. 
	
	mapchar_to_worldmap(window);//map_char 문자열을 int 형으로 저장. 

	check_map_character(window);//캐릭터 위치를 찾아서 window구조체의 posx, posy, direction에 저장.

	check_map_contents_count(window); //저장된 값들이 정상인지 확인 : 초기 값과 같지 않도록. , rgb의 경우 256초과하지 않도록. (음수인 경우는 '-'때문에 check_map_components 내부의 get_rgb함수의 ft_isdigit()함수에서 걸러진다.)
	
	print_map_utils(window);// etc - 확인용 함수 : 저장된 값들을 출력한다. 
	
	
	//TODO 
	/*
	1. map file open
	2. map components 확인 
		2.0.
		- map 이전에 components 확인 : 
		- NO , WE, SO, EA 와 함께 이미지 파일의 경로 
		- F ,C 와 함께 RGB 값 (r,g,b)
		- 개행의 수, space의 수는 상관없이 읽을 수 있어야 한다.

		- 읽으면서 map의 최대 행의 수 : map_col
		- 읽으면서 map의 최대 열의 수 : map_row에 저장.
		- 그걸로 malloc 뜨고, (에러체크) 초기화 -1로 해둔다. 


		2.1.
		- N, S , W, E 중 하나 (캐릭터)만 있는지
		- 위 제외 map의 구성 요소 중 0, 1을 제외한 다른 요소가 있다면 에러

		2.2.
		- map이 벽 1로 둘러싸여있는지 확인 (BFS -> 1이면 계속 가는데 map을 뚫고가는 경우 에러)

		
		필요한 데이터 구조:
		1. t_window 구조체
		2. t_map 구조체
			- NO WE SO EA 의 경로
			- t_image : 각 NO, WE, SO ,EA를 담을 구조체 : 위치, 크기
			- t_RGB : F, C의 rgb 값
			- 구성 요소에 대한 정보: 캐릭터 위치, 캐릭터 시작 방향
			- worldmap : 필요한 만큼 동적할당 하여 사용. buffer로 사용. 
			- 

	*/

	//map
	return (0);
}