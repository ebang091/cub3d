#include "../include/cub3d.h"

//return array -> surrounded_by_walls_bfs에서 visited 할당 시 사용
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
//save map 쪽에서 사용
int ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\r' || c == '\n' || c == '\f' || c == '\v')
		return (1);
	return (0);
}

int is_directionnum(int n)
{
	if (n == NORTH || n == SOUTH || n == WEST || n == EAST)
		return (TRUE);
	return (FALSE);
}