/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebang <ebang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 11:37:25 by ebang             #+#    #+#             */
/*   Updated: 2022/05/15 22:34:19 by ebang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	int		j;
	char	*ret;

	i = 0;
	j = 0;
	if (!s1)
		return (0);
	while (s1[i] != '\0')
		i++;
	i++;
	ret = malloc(sizeof(char) * i);
	if (!ret)
		return (0);
	while (j < i)
	{
		ret[j] = s1[j];
		j++;
	}
	return (ret);
}
