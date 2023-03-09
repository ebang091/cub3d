/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghwk <seunghwk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:53:34 by seunghwk          #+#    #+#             */
/*   Updated: 2023/03/09 15:37:58 by seunghwk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/error.h"

int	print_error(char *str)
{
	printf("Error\n%s", str);
	return (FAILURE);
}

int	exit_error(char *str)
{
	printf("Error\n%s", str);
	exit (FAILURE);
}
