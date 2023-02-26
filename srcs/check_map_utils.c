
#include "../include/cub3d.h"


int check_map_components_utils(t_window *window, char *str)
{
	int		i;

	i = -1;
	printf("str: %s\n", str);
	while (str[++i] != '\0')
	{
		if ((str[i] == 'w' || str[i] == 'W') && window->map_row == 0)
			return (get_path(window, &str[i + 1], WEST));
		else if ((str[i] == 's' || str[i] == 'S') && window->map_row == 0)
			return (get_path(window, &str[i + 1], SOUTH));
		else if ((str[i] == 'n' || str[i] == 'N') && window->map_row == 0)
			return (get_path(window, &str[i + 1], NORTH));
		else if ((str[i] == 'e' || str[i] == 'E') && window->map_row == 0)
			return (get_path(window, &str[i + 1], EAST));
		else if (str[i] == 'F' && window->map_row == 0)
			return (get_rgb(window, &str[i + 1], F));
		else if (str[i] == 'C' && window->map_row == 0)
			return (get_rgb(window, &str[i + 1], C));
		else if(i == 0 && ft_isdigit(str[i]))
		{
			window->map_col = findmax(window->map_col, (int)ft_strlen(str));
			window->map_row++;
			return (2);
		}
	}
	return (0);
	//TODO : 
	//맵을 읽고, window 구조체에 올바르게 경로가 입력되었는지 확인한다. 
	/*
	N ./
	S ./
	W ./
	E ./  (경로 이상하게 입력되는 건 mlx에서 사용시 에러 뜨나?)
	
	F
	C

	1. 순서다르게 입력
	2. 스페이스바가 사이에 많을때
	3. F 255, 255, 255 대신
		 255, 255,, 255
		255 255 255 (쉼표 없거나 너무 많을 때)
		255. 255. 255(반점이 아니라 온점, 다른 문자들 섞여있을 때.)
	*/
	
}

int get_path(t_window *window, char *path, int flag)
{
	int	i;
	t_image	*node;

	i = 0;
	while (path[i] != '\0' && ft_isspace(path[i]))
		i++;
	
	printf("path in getpath : %s\n", path + i);
	if (path[i] != 0)
	{
		node = find_direction(window, flag);
		printf("%d, %d\n", window->exist_flag, flag);
		node->path = path + i;
		if (window->exist_flag != flag / 2)
			ft_put_error("Error: direction order\n");
		window->exist_flag *= 2;
		return (0);
	}
	else
		ft_put_error("Error: map\n");
	return (1);
}

int  get_rgb(t_window *window, char *str, int flag)
{
	int i;
	int j;
	int ret;
	int cnt;
	int	*ptr;

	i = -1;
	cnt = 0;
	while (str[++i] != '\0')
	{	
		j = 0;
		ret = 0;
		while ((ft_isspace(str[i + j]) || str[i + j] == ',') && str[i+j] != '\0')
			j++;
		i += j;
		printf("str : %s\n", str + i);
		if(!ft_isdigit(str[i]))
			ft_put_error("Error: get rgb\n");
		while (ft_isdigit(str[i]) && (str[i] != '\0'))
			ret = ret * 10 + str[i++] - '0';
		ptr = find_rgb(window, flag, cnt);
		// printf("ret: %d\n",ret);
		*ptr = ret;
		// printf("value :  %d= %d\n", ret, *ptr);
		cnt++;
	}
	return (0);
}

int create_visited(t_window *window)
{
	int		i;
	
	i = -1;
	window->visited = (int **)malloc(sizeof(int*)*window->map_row);
	while (++i < window->map_row)
	{
		window->visited[i] = (int*)malloc(sizeof(int)*window->map_col);
		if (!window->visited[i])
				return (1);
		ft_memset(window->visited[i], 0, window->map_col);
	}
	return (0);
}

int	check_map_walls(t_window *window)
{
	//1로 잘 둘러싸여 있는지 확인. BFS로 구현하자. 
	//하니면 
	int	i;
	int	j;

	i = -1;
	if (create_visited(window))
		ft_put_error("Error: malloc visited\n");
	while (++i < window->map_row)
	{
		j = -1;
		while(++j <= window->map_col)
		{
			printf("check :%d,%d  ", i,j);
			if ((window->worldmap[i][j] == 0 && window->visited[i][j] == 0)
			|| (is_direction(window->worldmap[i][j]) && window->visited[i][j] == 0))
			{
				printf("BFS : %d, %d\n", i,j);
				queue_push(window, i, j);
				window->visited[i][j] = 1;
				if (BFS(window))
					return (free_BFS(window));//남아있는 큐 비우고 끝내기. return 1
			}
		}
	}
	free_arr(window->visited, window->map_row);
	return(0);
}