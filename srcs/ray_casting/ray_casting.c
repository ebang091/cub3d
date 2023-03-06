
#include "../mlx/mlx.h"
#include "../../includes/global.h"
#include "math.h"
#include <stdio.h>
#include "../../includes/ray_casting/ray_casting.h"

int check_key(int keycode, t_window *window);
void key_down(t_window *window);
void key_up(t_window *window);
void key_left(t_window *window);
void key_right(t_window *window);
void view_rotate(t_window *window, int keycode);


void get_direction_vector(t_window *window);
void draw_img(int x, int y, char type, t_window *window);

void ready_window(t_window *window);

void	save_wall_texture(t_window *window);
void	draw_background(t_window *window);


void save_wall_texture(t_window *window)
{
	
	for (int i=0 ;i < 4; i++)
	{
		window->images.texture[i].img = mlx_xpm_file_to_image(window->mlx, window->images.path[i], &window->images.width[i], &window->images.height[i]);
		window->images.texture[i].data =(int *)mlx_get_data_addr(window->images.texture[i].img, &window->images.texture[i].bpp, &window->images.texture[i].size_l, &window->images.texture[i].endian);
	}
}

// void	initial_malloc(t_window *window)
// {
// 	window->buffer = (unsigned int *)malloc(sizeof(unsigned int)*SCREENHEIGHT * SCREENWIDTH + 1);
// 	if(!window->buffer)
// 		exit_error("Error\nmalloc failed");
// }
// //utils


int	make_bits_rgb(int r, int g, int b)
{
	unsigned int	color;

	color = (r << 16) + (g << 8) + b;
	return (color);
}

void  my_mlx_pixel_put(t_img *image, int x, int y, int color)
{
	int *dst;

	dst = image->data + (y * SCREENWIDTH + x);
  	*(unsigned int*)dst = color;
	printf("%c ", *dst);
}


void	draw_background(t_window *window)
{

	// unsigned int	ccolor;
	// unsigned int	*line;
	int	i;
	int	j;

	// line = (unsigned int *)malloc(sizeof(unsigned int)*SCREENWIDTH);
	// if (!line)
		// exit_error("Error\nmalloc failed");
	
	// ccolor = make_bits_rgb(window->ceiling.r, window->ceiling.g, window->ceiling.b);
	
	// y * data->line_length + x * (data->bits_per_pixel / 8)
	i = -1;
	printf("hey");
	while(++i < SCREENHEIGHT)
	{
		j = -1;
		printf("hey");
		while(++j < SCREENWIDTH)
			{
				window->main_image.data[i * window->main_image.size_l + j*window->main_image.bpp]  = window->floor.color;
				printf("save: %d", window->main_image.data[i * window->main_image.size_l + j*window->main_image.bpp]);
			}
	}
	// i = -1;
	// while(++i < SCREENWIDTH)
	// 	line[i] = fcolor;
	// draw_line(window, line, 0, SCREENHEIGHT/2);
	// i = -1;
	// while(++i < SCREENWIDTH)
	// 	line[i] = ccolor;
	// draw_line(window, line, SCREENHEIGHT/2, SCREENHEIGHT);
	// free(line);
}

// void ready_window(t_window *window)
// {
// 	// initial_malloc(window);
// 	// save_wall_texture(window);
// }


int ray_casting(t_window *window)
{
	
	// mlx_clear_window(window->mlx, window->win);
	// void  my_mlx_pixel_put(t_data *data, int x, int y, int color);
	// for(int i=0; i < SCREENHEIGHT; i++)
	// {
	// 	for(int j = 0; j < SCREENWIDTH; j++)
	// 		window->main_image.data[i * SCREENWIDTH + j] = 0x00FF00;
	// }

	// save_buffer_to_image_addr (window->main_image, window->buffer);

	window->main_image.img = mlx_xpm_file_to_image(window->mlx, window->images.path[0], &window->images.width[0], &window->images.height[0]);
	window->main_image.data = (int *)mlx_get_data_addr(window->main_image.img, &window->main_image.bpp, &window->main_image.size_l, &window->main_image.endian );
	// window->main_image.img = mlx_xpm_to_image(window->mlx, )
	mlx_put_image_to_window(window->mlx, window->win, window->main_image.img, 0,0);
	
	return (0);
}

int key_exit(void)
{
	exit(0);
	return (0);
}
// void draw_img(int x, int y, char type, t_window *window)
// {
// 	int color;

// 	if (type == F)
// 	{
// 		color = mlx_get_color_value(window->mlx, (window->floor.r << 16) + (window->floor.g << 8) + window->floor.b);
// 		mlx_pixel_put(window->mlx, window->win, x, y, color);
// 	}
// 	else if(type == C)
// 	{
// 		color = mlx_get_color_value(window->mlx, (window->ceiling.r << 16) + (window->ceiling.g << 8) + window->ceiling.b);
// 		mlx_pixel_put(window->mlx, window->win, x, y, color);
// 	}
// 	else if(type == WEST)
// 		mlx_put_image_to_window(window->mlx, window->win, window->images.img[WEST], x, y);
// 	else if(type == EAST)
// 		mlx_put_image_to_window(window->mlx, window->win, window->images.img[EAST], x, y);
// 	else if(type == SOUTH)
// 		mlx_put_image_to_window(window->mlx, window->win, window->images.img[SOUTH], x, y);
// 	else if(type == NORTH)
// 		mlx_put_image_to_window(window->mlx, window->win, window->images.img[NORTH], x, y);

// }

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

void key_left(t_window *window)//코드 수정 필요
{
	char **worldmap;
	double *pos_x;
	double *pos_y;
	double plane_x;
	double plane_y;

	printf("key left\n!\n");
	worldmap = window->map.worldmap;
	pos_x = &window->player.pos_x;
	pos_y = &window->player.pos_y;
	plane_x = window->player.plane_x;
	plane_y = window->player.plane_y;
	if (worldmap[(int)(*pos_x + plane_x)][(int)(*pos_y)] != WALL) *pos_x -= plane_x;
	if (worldmap[(int)(*pos_x)][(int)(*pos_y + plane_y)] != WALL) *pos_y -= plane_y;
}

void key_right(t_window *window)//코드 수정 필요
{
	char **worldmap;
	double *pos_x;
	double *pos_y;
	double plane_x;
	double plane_y;

	printf("key right\n!\n");
	worldmap = window->map.worldmap;
	pos_x = &window->player.pos_x;
	pos_y = &window->player.pos_y;
	plane_x = window->player.plane_x;
	plane_y = window->player.plane_y;
	if (worldmap[(int)(*pos_x + plane_x)][(int)(*pos_y)] != WALL) *pos_x += plane_x;
	if (worldmap[(int)(*pos_x)][(int)(*pos_y + plane_y)] != WALL) *pos_y += plane_y;

}

void key_up(t_window *window)
{
	char **worldmap;
	double *pos_x;
	double *pos_y;
	double dir_x;
	double dir_y;

	printf("key up!\n");
	worldmap = window->map.worldmap;
	pos_x = &window->player.pos_x;
	pos_y = &window->player.pos_y;
	dir_x = window->player.dir_x;
	dir_y = window->player.dir_y;
	if (worldmap[(int)(*pos_x + dir_x)][(int)(*pos_y)] != WALL) *pos_x += dir_x;
	if (worldmap[(int)(*pos_x)][(int)(*pos_y + dir_y)] != WALL) *pos_y += dir_y;
}

void key_down(t_window *window)
{
	char **worldmap;
	double *pos_x;
	double *pos_y;
	double dir_x;
	double dir_y;

	printf("key down!\n");
	worldmap = window->map.worldmap;
	pos_x = &window->player.pos_x;
	pos_y = &window->player.pos_y;
	dir_x = window->player.dir_x;
	dir_y = window->player.dir_y;
	if (worldmap[(int)(*pos_x + dir_x)][(int)(*pos_y)] != WALL) *pos_x -= dir_x;
	if (worldmap[(int)(*pos_x)][(int)(*pos_y + dir_y)] != WALL) *pos_y -= dir_y;
}

void get_direction_vector(t_window *window)
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

void view_rotate(t_window *window, int keycode)
{
	double rot_speed;
	double *dir_x;
	double *dir_y;
	double *plane_x;
	double *plane_y;

	printf("key rotate!\n");
	rot_speed = window->player.rot_speed;
	dir_x = &window->player.dir_x;
	dir_y = &window->player.dir_y;
	plane_x = &window->player.plane_x;
	plane_y = &window->player.plane_y;

	if (keycode == KEY_RIGHT)
	{
		double old_dir_x = *dir_x;
		*dir_x = *dir_x * cos(-rot_speed) - *dir_y * sin(-rot_speed);
		*dir_y = old_dir_x * sin(-rot_speed) + *dir_y * cos(-rot_speed);
		double old_plane_x = *plane_x;
		*plane_x = *plane_x * cos(rot_speed) - *plane_y * sin(rot_speed);
		*plane_y = old_plane_x * sin(rot_speed) + *plane_y * cos(rot_speed);
	}
	if (keycode == KEY_LEFT)
	{
		double old_dir_x = *dir_x;
		*dir_x = *dir_x * cos(rot_speed) - *dir_y * sin(rot_speed);
		*dir_y = old_dir_x * sin(rot_speed) + *dir_y * cos(-rot_speed);
		double old_plane_x = *plane_x;
		*plane_x = *plane_x * cos(-rot_speed) - *plane_y * sin(-rot_speed);
		*plane_y = old_plane_x * sin(rot_speed) + *plane_y * cos(-rot_speed);
	}
}	


