/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebang <ebang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 21:52:32 by ebang             #+#    #+#             */
/*   Updated: 2022/05/15 15:21:27 by ebang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	int		i1;
	int		i2;
	int		j;

	i1 = 0;
	i2 = 0;
	j = 0;
	if (!s1 || !s2)
		return (0);
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
