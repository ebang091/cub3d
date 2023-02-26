#include "../include/cub3d.h"

int check_map_walls_edge(t_window *window)
{
	int	i;
	int	j;

	i = -1;
	while (++i < window->map_row)
	{
		if (i == 0 || i == window->map_row - 1)
		{
			j = -1;
			while (++j < window->map_col)
				if (window->worldmap[i][j] != 1 && window->worldmap[i][j] != -1)
					return (1);
		}
		else
		{
			if (window->worldmap[i][0] != 1 && window->worldmap[i][0] != -1)
				return (1);
			else if (window->worldmap[i][window->map_col - 1] != 1 && window->worldmap[i][window->map_col -1] != -1)
				return (1);
		}
	}
	return (0);
}