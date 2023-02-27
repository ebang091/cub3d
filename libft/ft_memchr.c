/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebang <ebang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 14:16:24 by ebang             #+#    #+#             */
/*   Updated: 2022/05/18 10:56:17 by ebang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*p;
	size_t			i;

	i = 0;
	if (!s)
		return (0);
	p = (unsigned char *)s;
	while (i < n)
	{
		if (p[i] == (unsigned char) c)
			return ((void *)p + i);
		i++;
	}
	return ((void *)0);
}
