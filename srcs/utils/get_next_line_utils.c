/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghwk <seunghwk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 13:02:43 by ebang             #+#    #+#             */
/*   Updated: 2023/02/28 17:35:53 by seunghwk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/get_next_line.h"

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
	{
		ret[j] = s[j + start];
	}
	ret[j] = '\0';
	return (ret);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	int		j;
	char	*ret;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
		i++;
	i++;
	ret = malloc(sizeof(char) * i);
	while (j < i)
	{
		ret[j] = s1[j];
		j++;
	}
	return (ret);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	int		i1;
	int		i2;
	int		j;

	i1 = 0;
	i2 = 0;
	j = 0;
	while (s1[i1] != '\0')
		i1++;
	while (s2[i2] != '\0')
		i2++;
	ret = (char *)malloc(sizeof(char) * (i1 + i2 + 1));
	if (!ret)
		return (0);
	while (j < i1)
		ret[j++] = *s1++;
	while (j < i1 + i2)
		ret[j++] = *s2++;
	ret[j] = '\0';
	return (ret);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	size_t	len;
	char	*p;

	p = (char *)s;
	if (s == 0)
		return (0);
	len = ft_strlen((const char *)s);
	i = 0;
	while (i <= (int)len)
	{
		if (p[i] == (unsigned char)c)
			return (&p[i]);
		i++;
	}
	return (0);
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}
