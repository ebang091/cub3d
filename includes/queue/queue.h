/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghwk <seunghwk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:01:28 by seunghwk          #+#    #+#             */
/*   Updated: 2023/03/03 15:47:10 by seunghwk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_H
# define QUEUE_H

# include <stdlib.h>

typedef struct s_node
{
	int				x;
	int				y;
	struct s_node	*next;
}	t_node;

typedef struct s_queue
{
	t_node	*head;
}	t_queue;

// queue.c
t_node	*new_node(int y, int x);
t_queue	*queue_init(void);
t_queue	*queue_push(t_queue *queue, t_node *node);
t_node	queue_pop(t_queue *queue);
int		free_queue(t_queue *queue);

#endif // QUEUE_H
