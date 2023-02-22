#include "cub3d.h"

void ft_clean(char** str, int n)
{
	int		i;

	i = -1;
	while(++i < n)
	{
		free(str[i]);
	}
	free(str);
}

void free_arr(int **arr, int row)
{
	int	i;

	i = -1;
	while (++i < row)
		free(arr[i]);
	free(arr);

}