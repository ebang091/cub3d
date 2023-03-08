/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeselee <yeselee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:53:34 by seunghwk          #+#    #+#             */
/*   Updated: 2023/03/08 15:49:29 by yeselee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/error.h"

int	ft_put_error(char *str)
{
	printf("%s", str);
	return (FAILURE);
}

int	exit_error(char *str)
{
	printf("%s", str);
	exit (FAILURE);
}
