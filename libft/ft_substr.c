/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebang <ebang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 11:43:42 by ebang             #+#    #+#             */
/*   Updated: 2022/05/14 20:37:49 by ebang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*ret;
	size_t			i;
	unsigned int	j;

	j = -1;
	if (s == 0)
		return (0);
	i = ft_strlen((char *)s);
	if (i <= (size_t)start)
	{
		ret = (char *)malloc(sizeof(char) * 1);
		ret[0] = '\0';
		return (ret);
	}
	if (len > i)
		len = i;
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (0);
	while (++j < len && s[j + start])
		ret[j] = s[j + start];
	ret[j] = '\0';
	return (ret);
}
