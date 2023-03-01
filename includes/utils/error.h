/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghwk <seunghwk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:55:13 by seunghwk          #+#    #+#             */
/*   Updated: 2023/03/01 20:39:46 by seunghwk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include <unistd.h>
# include <stdlib.h>

# include "../libft/libft.h"
# include "global.h"

int	ft_put_error(char *str);
int	exit_error(char *str);

#endif // ERROR_H
