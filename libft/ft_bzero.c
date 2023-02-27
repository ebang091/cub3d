/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebang <ebang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 16:33:35 by ebang             #+#    #+#             */
/*   Updated: 2022/05/02 14:23:47 by ebang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bzero(void *b, size_t n)
{
	size_t			i;
	unsigned char	*temp;

	if (!b)
		return (NULL);
	temp = b;
	i = 0;
	while (i < n)
	{
		temp[i] = 0;
		i++;
	}
	return (b);
}
