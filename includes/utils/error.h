/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeselee <yeselee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:55:13 by seunghwk          #+#    #+#             */
/*   Updated: 2023/03/08 18:24:05 by yeselee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include <stdio.h>
# include <stdlib.h>

# include "libft.h"
# include "global.h"

int	ft_put_error(char *str);
int	exit_error(char *str);

#endif
