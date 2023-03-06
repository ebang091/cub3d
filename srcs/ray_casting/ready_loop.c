#include "global.h"
#include "ray_casting/ray_casting.h"

static void get_direction_vector(t_window *window);
static void malloc_buffer(t_window *window);
// static void save_wall_texture(t_window *window);
static void save_rgb(t_window *window);


void ready_loop(t_window *window)
{
	get_direction_vector(window);
	malloc_buffer(window);
	// save_wall_texture(window);
	save_rgb(window);
}

static void get_direction_vector(t_window *window)
{
	int direction;
	
	direction = window->player.direction;
	if (direction == WEST || direction == EAST)
		window->player.dir_y = 0;
	else
		window->player.dir_x = 0;
	if (direction == WEST)
		window->player.dir_x = -1;
	else if(direction == EAST)
		window->player.dir_x = 1;
	else if(direction == SOUTH)
		window->player.dir_y = -1;
	else if (direction == NORTH)
		window->player.dir_y = 1;
}


static void malloc_buffer(t_window *window)
{
	int	i;

	window->buffer = (int **)malloc(sizeof(int *) * SCREENHEIGHT + 1);
	if (!window->buffer)
		exit_error("Error\nmalloc");
	i = -1;
	while (++i  < SCREENHEIGHT)
	{
		window->buffer[i] = (int*)malloc(sizeof(int) * SCREENWIDTH);
		if (!window->buffer[i])
			exit_error("Error\nmalloc");
		ft_memset(window->buffer[i], 0, sizeof(int) * SCREENWIDTH);
	}
}
/*

static void save_wall_texture(t_window *window)
{
	for (int i=0 ;i < 4; i++)
	{
		
		window->images.texture[i].img = mlx_xpm_file_to_image(window->main_image.mlx, window->images.path[i], &window->images.width[i], &window->images.height[i]);
		window->images.texture[i].data =(unsigned int *)mlx_get_data_addr(window->images.texture[i].img, &window->images.texture[i].bpp, &window->images.texture[i].size_l, &window->images.texture[i].endian);
		mlx_destroy_image(window->main_image.mlx, window->images.texture[i].img);
	}
}
*/

static void save_rgb(t_window *window)
{
	window->floor.color = (window->floor.r << 16 ) + (window->floor.g << 8) +  window->floor.b;
	window->floor.color = (window->ceiling.r << 16) + (window->ceiling.g << 8) + window->ceiling.b;
}
