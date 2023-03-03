/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghwk <seunghwk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 14:27:50 by seunghwk          #+#    #+#             */
/*   Updated: 2023/03/03 16:03:21 by seunghwk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue/queue.h"

t_node	*new_node(int y, int x)
{
	t_node	*new_node;

	new_node = (t_node *) malloc(sizeof(t_node));
	new_node->y = y;
	new_node->x = x;
	new_node->next = NULL;
	return (new_node);
}

t_queue	*queue_init(void)
{
	t_queue	*queue;

	queue = (t_queue *) malloc(sizeof (t_queue));
	queue->head = NULL;
	return (queue);
}

t_queue	*queue_push(t_queue *queue, t_node *node)
{
	t_node	*current;

	if (queue->head == NULL)
	{
		queue->head = node;
		return (queue);
	}
	current = queue->head;
	while (current->next)
		current = current->next;
	current->next = node;
	return (queue);
}

t_node	queue_pop(t_queue *queue)
{
	t_node	pop_node;
	t_node	*temp;

	temp = queue->head;
	pop_node.y = temp->y;
	pop_node.x = temp->x;
	if (queue->head->next == NULL)
		queue->head = NULL;
	else
		queue->head = queue->head->next;
	free(temp);
	return (pop_node);
}

int	free_queue(t_queue *queue)
{
	t_node	*current;
	t_node	*temp;

	if (queue->head == NULL)
	{
		free(queue);
		return (1);
	}
	current = queue->head;
	while (current->next)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
	free(current);
	free(queue);
	return (1);
}
