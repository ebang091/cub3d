
#include "./cub3d.h"


int check_map_components_utils(t_window *window, char *str)
{
	char	tmp[1000];
	int		i;

	i = -1;
	while(str[++i] != '\0')
	{
		if (str[i] == 'w' || str[i] == 'W' && window->map_row == 0)
			get_path(window, &str[i], WEST);
		else if (str[i] == 's' || str[i] == 'S' && window->map_row == 0)
			get_path(window, &str[i], SOUTH);
		else if (str[i] == 'n' || str[i] == 'N' && window->map_row == 0)
			get_path(window, &str[i], NORTH);
		else if (str[i] == 'e' || str[i] == 'E' && window->map_row == 0)
			get_path(window, &str[i], EAST);
		else if (str[i] == 'F' && window->map_row == 0)
			get_rgb(window, &str[i], F && window->map_row == 0);
		else if (str[i] == 'C')
			get_rgb(window, &str[i], C);
		else if(i == 0 && ft_isdigit(str[i]))
		{
			window->map_col = findmax(window->map_col, (int)ft_strlen(str));
			window->map_row++;
			return (1);
		}
		return (0);
	}

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

void get_path(t_window *window, char *path, int flag)
{
	int	i;

	i = -1;
	while (path[++i] != '\0')
	{
		if((path[i] == '.' && path[i + 1] == '/') || path[i] == '/')
			break;
	}
	if (path != 0)
	{
		find_direction(flag)->path = path + i;
		if(window->exist_flag != flag -1)
			ft_put_error("Error\n");
		window->exist_flag++;
		return;
	}
	else
		ft_put_error("Error\n");
}

void  get_rgb(t_window *window, char *str, int flag)
{
	int i;
	int j;
	int ret;
	int cnt;

	i = -1;
	cnt = 0;
	while(str[++i] != '\0')
	{	
		j = 0;
		ret = 0;
		while(isspace(str[i + j]) || str[i + j] == ',')
			j++;
		i += j;
		if(!isdigit(str[i]))
			ft_put_error("Error\n");
		while(!(isspace(str[i]) || str[i] == ','))
		{
			ret = ret * 10 + str[i++] - '0';
		}
		*(find_rgb(window, flag, cnt))= ret;
		cnt++;
	}
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

void	check_map_walls(t_window *window)
{
	//1로 잘 둘러싸여 있는지 확인. BFS로 구현하자. 
	//하니면 
	int	i;
	int	j;

	i = -1;
	if (create_visited(window))
		ft_put_error("Error\n");
	while (++i < window->map_row)
	{
		j = -1;
		while(++j < window->map_col)
		{
			if(window->worldmap[i][j] == 0 && window->visited[i][j] == 0
			|| is_direction(window->worldmap[y][x]) && window->visited[y][x] == 0)
			{
				queue_push(window, i, j);
				if (BFS(window, i, j))
					return(free_BFS(window));//남아있는 큐 비우고 끝내기. return 1
			}
		}
	}
	free_arr(window->visited, window->map_row);
	return(0);
}