/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebang <ebang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:04:18 by ebang             #+#    #+#             */
/*   Updated: 2022/05/16 15:33:49 by ebang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (size != 0 && ((SIZE_MAX - 1) / size < count))
		return (0);
	ptr = malloc(count * size);
	if (!ptr)
		return (0);
	ptr = ft_memset(ptr, 0, count * size);
	return (ptr);
}
