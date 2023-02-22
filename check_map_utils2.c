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

int free_BFS(t_window *window)
{
	//queue를 모두 free하고 1 return.
}

int is_direction(int c)
{
	if (c == 'E' || c == 'W' || c == 'S' || c == 'N')
		return(1);
	else
		return(0);
}

#include <stdio.h>
void print_map_utils(t_window *window)
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
	printf("character position : dir: %c, posx: %d, posy : %d\n", window->direction, window->pos_x, window->pos_y);

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