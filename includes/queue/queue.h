/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghwk <seunghwk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:01:28 by seunghwk          #+#    #+#             */
/*   Updated: 2023/03/01 15:28:32 by seunghwk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_H
# define QUEUE_H

# include <stdlib.h>

# include "global.h"
# include "utils/error.h"

typedef struct s_node
{
	int				y;
	int				x;
	struct s_node	*next;
}	t_node;

t_node	*newnode(int y, int x);
void	queue_push(t_window *window, int y, int x);
t_node	*queue_pop(t_window *window);

#endif // QUEUE_H
