
#include "../include/cub3d.h"

void ft_put_error(char *str)
{
	write(1, str, ft_strlen(str));
	exit(1);
}