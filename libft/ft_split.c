/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebang <ebang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 16:13:08 by ebang             #+#    #+#             */
/*   Updated: 2022/05/15 18:14:40 by ebang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wordlen(char const *str, char charset)
{
	int		i;

	i = 0;
	while (str[i] && str[i] != charset)
		i++;
	return (i);
}

static int	ft_wordcount(char const *str, char charset)
{
	int	i;
	int	j;

	j = 0;
	while (*str)
	{
		while (*str && *str == charset)
			str++;
		i = ft_wordlen(str, charset);
		str += i;
		if (i)
			j++;
	}
	return (j);
}

static char	*ft_strdup1(char const *str, int j)
{
	char	*ret;
	int		i;

	i = 0;
	ret = (char *)malloc(sizeof(char) * (j + 1));
	if (!ret)
		return (0);
	while (i < j)
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = 0;
	return (ret);
}

static void	ft_free(char **dest, int n)
{
	int		i;

	i = 0;
	while (i <= n)
		free(dest[i++]);
	free(dest);
}

char	**ft_split(char const *str, char c)
{
	char	**dest;
	int		size;
	int		i;

	i = -1;
	if (!str)
		return (0);
	size = ft_wordcount(str, c);
	dest = malloc((size + 1) * sizeof(char *));
	if (!dest)
		return (0);
	while (++i < size)
	{
		while (*str == c)
			str++;
		dest[i] = ft_strdup1(str, ft_wordlen(str, c));
		if (!dest[i])
		{
			ft_free(dest, i);
			return (0);
		}
		str += ft_wordlen(str, c);
	}
	dest[size] = 0;
	return (dest);
}
