/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsstmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebang <ebang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 20:09:58 by ebang             #+#    #+#             */
/*   Updated: 2022/05/16 14:20:16 by ebang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del) (void *))
{
	t_list	*ptr;
	t_list	*ret;
	t_list	*newnode;

	ret = 0;
	if (!lst || !f)
		return (0);
	ptr = lst;
	while (ptr != NULL)
	{	
		newnode = ft_lstnew((f)(ptr->content));
		if (!newnode)
		{
			if (del)
				ft_lstclear (&ret, free);
			return (0);
		}
		ft_lstadd_back (&ret, newnode);
		ptr = ptr -> next;
	}
	return (ret);
}
