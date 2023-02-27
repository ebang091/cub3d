/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebang <ebang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 22:14:47 by ebang             #+#    #+#             */
/*   Updated: 2022/05/14 19:20:27 by ebang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		i;
	char	*p;

	if (str == 0)
		return (0);
	p = (char *) str;
	i = 0;
	while (p[i] != '\0')
		i++;
	while (i >= 0)
	{
		if (p[i] == (unsigned char)c)
			return (&p[i]);
		i--;
	}
	return (0);
}
