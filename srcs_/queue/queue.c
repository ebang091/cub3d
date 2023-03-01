/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghwk <seunghwk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 14:27:50 by seunghwk          #+#    #+#             */
/*   Updated: 2023/03/01 11:54:52 by seunghwk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue/queue.h"

t_node	*newnode(int y, int x)
{
	t_node	*new_node;

	new_node = (t_node *) malloc(sizeof (t_node));
	new_node->y = y;
	new_node->x = x;
	new_node->next = NULL;
	return (new_node);
}

void	queue_push(t_window *window, int y, int x)
{
	t_node	*node;

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
	node->next = newnode(y, x);
}

t_node	*queue_pop(t_window *window)
{
	t_node	*pop_node;

	pop_node = window->queue;
	if (pop_node = NULL)
		ft_put_error("queue Error\n");
	if (pop_node->next == NULL) //큐에 하나만 들어있는 경우
	{
		window->queue_isempty = 1;
		window->queue = NULL;
	}
	window->queue = pop_node->next;
	return (pop_node);
}
