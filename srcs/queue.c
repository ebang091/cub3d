
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
