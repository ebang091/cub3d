
#include "../include/cub3d.h"

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

int free_bfs(t_window *window)
{
	t_node	*ptr;
	t_node 	*sptr;

	ptr = window->queue;
	sptr = ptr;
	while (ptr != NULL)
	{
		sptr = ptr->next;
		free(ptr);
		ptr = sptr;
	}
	ft_put_error("Error\n");
	return (1);
}

int	check_map_bfs(t_window *window)
{
	//1로 잘 둘러싸여 있는지 확인. BFS로 구현하자. 
	//하니면 
	int	i;
	int	j;

	i = -1;
	if (create_visited(window))
		ft_put_error("Error\nmalloc visited\n");
	while (++i < window->map_row)
	{
		j = -1;
		while(++j < window->map_col)
		{
			if ((window->worldmap[i][j] == 0 && window->visited[i][j] == 0)
			|| (is_directionnum(window->worldmap[i][j]) && window->visited[i][j] == 0))
			{
				printf("BFS : %d, %d\n", i,j);
				queue_push(window, i, j);
				window->visited[i][j] = 1;
				if (bfs(window))//1반환하면 오류 : 빈칸(0)을 돌다가 공백쪽으로 튀어나왔다는 뜻.
					return (free_bfs(window));//남아있는 큐 비우고 끝내기. return 1
			}
		}
	}
	free_arr(window->visited, window->map_row);
	return(0);
}

int check_map_edge(t_window *window)
{
	int	i;
	int	j;

	i = -1;
	while (++i < window->map_row)
	{
		if (i == 0 || i == window->map_row - 1)
		{
			j = -1;
			while (++j < window->map_col)
				if (window->worldmap[i][j] != 1 && window->worldmap[i][j] != -1)
					return (1);
		}
		else
		{
			if (window->worldmap[i][0] != 1 && window->worldmap[i][0] != -1)
				return (1);
			else if (window->worldmap[i][window->map_col - 1] != 1 && window->worldmap[i][window->map_col -1] != -1)
				return (1);
		}
	}
	return (0);
}