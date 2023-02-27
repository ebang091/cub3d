/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebang <ebang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:03:42 by ebang             #+#    #+#             */
/*   Updated: 2022/05/16 14:21:16 by ebang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int				sign;
	char			*ptr;
	unsigned long	ab_value;

	sign = 1;
	if (!str)
		return (0);
	ptr = (char *)str;
	ab_value = 0;
	while (*ptr == '\t' || *ptr == '\n' || *ptr == '\v'
		|| *ptr == '\f' | *ptr == '\r' || *ptr == ' ')
		ptr++;
	if (*ptr == '-' || *ptr == '+')
	{
		if (*ptr++ == '-')
			sign *= -1;
	}
	while (*ptr >= '0' && *ptr <= '9')
		ab_value = ab_value * 10 + *ptr++ - '0';
	if (ab_value > 9223372036854775807UL && sign < 0)
		return (0);
	if (ab_value > 9223372036854775807UL && sign > 0)
		return (-1);
	ab_value = (int)(ab_value)*sign;
	return (ab_value);
}
