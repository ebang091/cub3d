/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghwk <seunghwk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:53:34 by seunghwk          #+#    #+#             */
/*   Updated: 2023/03/06 20:25:09 by seunghwk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/error.h"

int ft_put_error(char *str)
{
	printf("%s", str);
	return (FAILURE);
}

int exit_error(char *str)
{
	printf("%s", str);
	exit (FAILURE);
}
