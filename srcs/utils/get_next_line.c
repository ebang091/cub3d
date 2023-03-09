/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghwk <seunghwk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 17:37:12 by seunghwk          #+#    #+#             */
/*   Updated: 2023/03/09 10:52:41 by seunghwk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/get_next_line.h"

static void	read_line(int fd, char **backup);
static int	search_nl(char *backup);
static char	*get_line(char *backup);
static void	backup_update(char *backup);

char	*get_next_line(int fd)
{
	char		*line;
	static char	*backup;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	read_line(fd, &backup);
	if (!backup)
		return (0);
	line = get_line(backup);
	backup_update(backup);
	return (line);
}

static void	read_line(int fd, char **backup)
{
	char	buf[BUFFER_SIZE + 1];
	int		size;

	while (1)
	{
		size = read(fd, buf, BUFFER_SIZE);
		if (!size)
			break ;
		if (size == -1)
		{
			if (*backup)
				free(*backup);
			*backup = 0;
			return ;
		}
		buf[size] = 0;
		*backup = backup_join(*backup, buf);
		if (search_nl(*backup))
			break ;
	}
}

static int	search_nl(char *backup)
{
	int	i;

	i = 0;
	while (backup[i])
		if (backup[i++] == '\n')
			return (1);
	return (0);
}

static char	*get_line(char *backup)
{
	char	*res;
	int		i;

	if (!backup[0])
		return (0);
	i = 0;
	while (backup[i] && backup[i] != '\n')
		i++;
	res = (char *)malloc(i + 1 + (backup[i] == '\n'));
	i = 0;
	while (backup[i] && backup[i] != '\n')
	{
		res[i] = backup[i];
		i++;
	}
	if (backup[i] == '\n')
		res[i++] = '\n';
	res[i] = 0;
	return (res);
}

static void	backup_update(char *backup)
{
	int	i;
	int	j;

	i = 0;
	while (backup[i] && backup[i] != '\n')
		i++;
	if (backup[i] == '\n')
		i++;
	j = 0;
	while (backup[i])
		backup[j++] = backup[i++];
	backup[j] = 0;
}
