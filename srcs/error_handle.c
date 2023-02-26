
#include "../include/cub3d.h"

int ft_put_error(char *str)
{
	write(1, str, ft_strlen(str));
	return (ERROR);
}

int exit_error(char *str)
{
	write(1, str, ft_strlen(str));
	exit (ERROR);
}