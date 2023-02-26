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