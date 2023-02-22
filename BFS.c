
#include "./cub3d.h"

t_node *newnode(int y, int x)
{
	t_node	*n;

	n = (t_node*)malloc(sizeof(t_node));
	n->y = y;
	n->x = x;
	n->next = NULL;
	return n;
}

void queue_push(t_window *window, int y, int x)
{
	t_node *node;

	node = window->queue;
	if (!node)
	{
		node = newnode(y, x);
		window->queue = node;
		window->queue_isempty = 0;
		return ;
	}
	while (node->next != NULL)
		node = node->next;
	node->next = newnode(y,x);
}

t_node *queue_pop(t_window *window)
{
	t_node	*ptr;

	ptr = window->queue;
	if (!ptr)
		ft_put_error("queue Error\n");
	if (ptr->next == NULL) //큐에 하나만 들어있는 경우
		window->queue_isempty = 1;
	window->queue = ptr->next;
	return ptr;
}

void getdir(int *y, int *x, int flag)
{
	if (flag == 1)
		*x += 1;
	else if (flag == 2)
		*x += -1;
	else if (flag == 3)
		*y = 1;
	else if (flag == 4)
		*y = -1;
}

int BFS(t_window *window)
{
	t_node	*ptr;
	int		y;
	int		x;
	int		i;
	int		flag;

	while (!window->queue_isempty)
	{
		ptr = queue_pop(window);
		i = 0;
		flag = 0;
		while (++i < 4)
		{
			y = ptr->y;
			x = ptr->x;
			getdir (&y, &x, i);
			if (window->worldmap[y][x] == 0 && window->visited[y][x] == 0)
			{
				queue_push(window, y, x);
				window->visited[y][x] = 1;
				flag = 1;
			}
			else if()
				return(0);
		}
		if	(!flag)
			return(1);
		//종료되지 않는 조건에서 어떻게 확인? 모두 갈 수 없는 경우
	}
}