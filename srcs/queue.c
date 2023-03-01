
#include "../include/cub3d.h"

t_node	*new_node(int y, int x)
{
	t_node	*new_node;

	new_node = (t_node *) malloc(sizeof(t_node));
	new_node->y = y;
	new_node->x = x;
	new_node->next = NULL;
	return (new_node);
}

void	queue_push(t_window *window, int y, int x)
{
	t_node	*node;

	node = window->queue;
	if (node == NULL)
	{
		node = newnode(y, x);
		window->queue = node;
		window->queue_isempty = 0;
		return ;
	}
	while (node->next)
		node = node->next;
	node->next = newnode(y, x);
}

t_node	*queue_pop(t_window *window)
{
	t_node	*pop_node;

	pop_node = window->queue;
	if (pop_node == NULL)
		ft_put_error("queue Error\n");
	if (pop_node->next == NULL)
	{
		window->queue_isempty = 1;
		window->queue = NULL;
	}
	window->queue = ptr->next;
	return (ptr);
}
