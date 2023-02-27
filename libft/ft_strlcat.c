/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebang <ebang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 14:24:36 by ebang             #+#    #+#             */
/*   Updated: 2022/05/14 18:58:24 by ebang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	len_dest;
	size_t	len_src;
	size_t	i;

	i = 0;
	if (!src && !dest)
		return (0);
	len_src = ft_strlen(src);
	len_dest = ft_strlen(dest);
	if (size == 0)
		return (len_src + size);
	if (len_dest >= size)
		return (len_src + size);
	while (i < size - len_dest - 1 && src[i] != '\0')
	{
		dest[len_dest + i] = src[i];
		i++;
	}
	dest[len_dest + i] = '\0';
	return (len_dest + len_src);
}
