#include "./cub3d.h"

void check_all_walls(t_window *window, int *arr)
{
	int		i;

	i = -1;
	while (++i < window->map_col && arr[i] != -1)
	{
		if (arr[i] != 1)
			ft_put_error("Error\n");
	}
}

