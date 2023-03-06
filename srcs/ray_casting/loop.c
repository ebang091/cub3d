#include "global.h"
#include "ray_casting/ray_casting.h"

static void buffer_to_image(t_window *window);

int loop_function(t_window *window)
{
	draw_background(window);
	ray_casting(window);
	buffer_to_image(window);
	mlx_put_image_to_window(window->main_image.mlx, window->main_image.win, window->main_image.img, 0,0);
	
	return (0);
}

int check_key(int keycode, t_window *window)
{

	if (keycode == KEY_W)
		key_up(window);
	if (keycode == KEY_S)
		key_down(window);
	else if(keycode == KEY_A)
		key_left(window);
	else if(keycode == KEY_D)
		key_right(window);
	else if(keycode == KEY_LEFT || keycode == KEY_RIGHT)
		view_rotate(window, keycode);
	return (0);
}

int key_exit(void)
{
	exit(0);
	return (0);
}


static void buffer_to_image(t_window *window)
{
	int	i;
	int	j;

	i = -1;
	while (++i < SCREENHEIGHT)
	{
		j = -1;
		while (++j < SCREENWIDTH)
			window->main_image.data[i * SCREENHEIGHT + j] = window->buffer[i][j];
	}
}

