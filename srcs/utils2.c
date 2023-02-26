#include "../include/cub3d.h"

void ft_clean(int** tab, int n)
{
	int		i;

	i = -1;
	while(++i < n)
	{
		if (tab[i])
			free(tab[i]);
	}
	free(tab);
}

void free_arr(int **arr, int row)
{
	int	i;

	i = -1;
	while (++i < row)
		free(arr[i]);
	free(arr);

}

int ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\r' || c == '\n' || c == '\f' || c == '\v')
		return (1);
	return (0);
}

int is_direction(int c)
{
	if (c == 'E' || c == 'W' || c == 'S' || c == 'N')
		return(1);
	else
		return(0);
}

int	Cango(t_window *window, int y, int x)
{
	if (0 <= y && y < window->map_row && 0 <= x && x < window->map_col)
		return (1);
	return (0);
}
