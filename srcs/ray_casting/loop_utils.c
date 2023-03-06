#include "global.h"
#include "../../includes/ray_casting/ray_casting.h"

void	draw_background(t_window *window);

void	draw_background(t_window *window)
{

	
	int	i;
	int	j;

	i = -1;
	printf("hey");
	while(++i < SCREENHEIGHT/2)
	{
		j = -1;
		printf("hey");
		while(++j < SCREENWIDTH)
			{
				window->buffer[i][j] = window->ceiling.color;
				window->buffer[SCREENHEIGHT - i - 1][j] = window->floor.color;
			}
	}

}

void ray_casting(t_window *window)
{
	window = window + 0;
	return ;	
}



