/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeselee <yeselee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 17:38:26 by seunghwk          #+#    #+#             */
/*   Updated: 2023/03/08 18:24:10 by yeselee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"

# define BUFFER_SIZE 42

// get_next_line.c
char	*get_next_line(int fd);

// get_next_line_utils.c
void	backup_init(char **backup);
char	*backup_join(char *backup, char *buf);

#endif
