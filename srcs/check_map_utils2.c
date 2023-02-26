#include "../include/cub3d.h"

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

int free_BFS(t_window *window)
{
	t_node	*ptr;
	t_node 	*sptr;

	ptr = window->queue;
	sptr = ptr;
	while(ptr != NULL)
	{
		sptr = ptr->next;
		free(ptr);
		ptr = sptr;
	}
	ft_put_error("Error\n");
	return (1);
}

int is_direction(int c)
{
	if (c == 'E' || c == 'W' || c == 'S' || c == 'N')
		return(1);
	else
		return(0);
}

void	print_map_utils(t_window *window)
{
	/*
	1. NWSE path
	2. F, C RGB value
	3. map NSWE count, position
	4. map input
	5. error check
	*/
	printf("path : N : %s\n", window->N_img.path);
	printf("path : S : %s\n", window->S_img.path);
	printf("path : W : %s\n", window->W_img.path);
	printf("path : E : %s\n", window->E_img.path);

	printf("\n");
	printf("F R:%d G:%d B:%d\n", window->floor.r, window->floor.g, window->floor.b);
	printf("C R:%d G:%d B:%d\n", window->ceiling.r, window->ceiling.g, window->ceiling.b);

	printf("\n");
	printf("character position - dir: %d, posx: %d, posy : %d\n", window->direction, window->pos_x, window->pos_y);

	printf("********************map check********************\n");
	for(int i=0;i<window->map_row;i++)
	{
		for(int j=0; j < window->map_col;j++)
		{
			if(window->worldmap[i][j] == -1)
				printf(" ");
			else
				printf("%d", window->worldmap[i][j]);
		}
		printf("\n");
	}

}

int ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\r' || c == '\n' || c == '\f' || c == '\v')
		return (1);
	return (0);
}

int check_map_contents_count(t_window *window)
{
	if (window->exist_flag != 4 || window->floor.r == -1 || window->floor.b == -1
		 || window->floor.g == -1)
	{
		printf("%d %d %d\n", window->exist_flag , window->floor.r, window->floor.b);
					ft_put_error("Error: map argument\n");
	}
	if (window->ceiling.r == -1 || window->ceiling.g == -1 || window->ceiling.b == -1)
		ft_put_error("Error: map argument\n");
	if (window->pos_x== -1 || window->pos_y == -1)
		ft_put_error("Error: character position");
	if (window->map_col == 0 || window->map_row == 0)
		ft_put_error("Error: map shape\n");
	if (window->direction == -1 || window->worldmap == 0)
		ft_put_error("Error: map");
	return (0);
}