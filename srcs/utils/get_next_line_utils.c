/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjungbang <eunjungbang@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 17:37:59 by seunghwk          #+#    #+#             */
/*   Updated: 2023/03/08 00:36:36 by eunjungbang      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils/get_next_line.h"

void	backup_init(char **backup)
{
	char	*init;

	init = (char *)malloc(1);
	if (!init)
		return ;
	*init = 0;
	*backup = init;
}

char	*backup_join(char *backup, char *buf)
{
	char	*res;
	int		i;
	int		j;

	if (!backup)
		backup_init(&backup);
	if (!backup || !buf)
		return (0);
	res = (char *)malloc(ft_strlen(backup) + ft_strlen(buf) + 1);
	i = 0;
	while (backup[i])
	{
		res[i] = backup[i];
		i++;
	}
	j = 0;
	while (buf[j])
		res[i++] = buf[j++];
	res[i] = 0;
	free(backup);
	return (res);
}
