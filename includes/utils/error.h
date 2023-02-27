/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghwk <seunghwk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:55:13 by seunghwk          #+#    #+#             */
/*   Updated: 2023/02/27 14:58:29 by seunghwk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include <unistd.h>

# define FAILURE 1

int	ft_put_error(char *str);
int	exit_error(char *str);

#endif // ERROR_H
