/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebang <ebang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 16:19:46 by ebang             #+#    #+#             */
/*   Updated: 2022/05/02 17:21:32 by ebang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t			i;
	size_t			len;
	char			*tmp;

	if (!s || !f)
		return (NULL);
	len = ft_strlen((char *)s);
	tmp = (char *)malloc(sizeof(char) * (len + 1));
	if (!tmp)
		return (NULL);
	i = 0;
	while (i < len)
	{
		tmp[i] = f(i, s[i]);
		i++;
	}
	tmp[i] = 0;
	return (tmp);
}
