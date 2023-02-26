
#include "../include/cub3d.h"

//함수 개수 문제!
static int create_visited(t_window *window);
static void getdir(int *y, int *x, int flag);
static int is_directionnum(int n);
static int bfs(t_window *window);
static int free_bfs(t_window *window);

static int	check_surrounded_by_walls_bfs(t_window *window)
{
	//1로 잘 둘러싸여 있는지 확인. BFS로 구현하자. 
	//하니면 
	int	i;
	int	j;

	i = -1;
	if (create_visited(window))
		return (ft_put_error("Error\nmalloc visited\n"));
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


static int bfs(t_window *window)
{
	t_node	*ptr;
	int		y;
	int		x;
	int		i;

	while (!window->queue_isempty)
	{
		ptr = queue_pop (window);
		i = 0;
		while (++i < 5)
		{
			y = ptr->y;
			x = ptr->x;
			printf("now : %d %d\n", y,x);
			getdir (&y, &x, i);
			printf("next: %d %d\n", y, x);
			if ((Cango(window, y, x) && ((window->worldmap[y][x] == 0 && window->visited[y][x] == 0)
			 || (is_directionnum(window->worldmap[y][x]) && window->visited[y][x] == 0))))
			{
				printf("will visit: %d %d\n", y, x);
				queue_push(window, y, x);
				window->visited[y][x] = 1;
			}
			else if (window->worldmap[y][x] == -1)
			{
				printf("error: %d %d\n", y, x);
				return (1);
			}
		}
		free (ptr);
	}
	return (0);
}

static int create_visited(t_window *window)
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

static void getdir(int *y, int *x, int flag)
{
	if (flag == 1)
		*x += 1;
	else if (flag == 2)
		*x += -1;
	else if (flag == 3)
		*y += 1;
	else if (flag == 4)
		*y += -1;
}

//surrounded_by_walls_bfs에서 visited 할당 시 사용
static int	**return_array(int row, int col)
{
	int		**tmp;
	int		i;

	i = -1;
	tmp = (int **)malloc(sizeof(int*) * row);
	if(!tmp)
		return (ft_put_error("Error malloc\n"));
	while (++i <= row)
	{
		tmp[i] = (int *)malloc(sizeof(int) * col);
		if (!tmp[i])
		{
			ft_clean(tmp, i);
			return (ft_put_error("Error\n"));			
		}
	}
	return (tmp);
}

static int is_directionnum(int n)
{
	if (n == NORTH || n == SOUTH || n == WEST || n == EAST)
		return (SUCCESS);
	return (ERROR);
}

static int free_bfs(t_window *window)
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
	return (ft_put_error("Error\nnot surrounded by walls"));
}