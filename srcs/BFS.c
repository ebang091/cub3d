
#include "../include/cub3d.h"

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
	{
		window->queue_isempty = 1;
		window->queue = NULL;
	}
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
		*y += 1;
	else if (flag == 4)
		*y += -1;
}

int BFS(t_window *window)
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