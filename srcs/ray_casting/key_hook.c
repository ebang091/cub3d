#include "global.h"
#include "ray_casting/ray_casting.h"

void key_down(t_window *window);
void key_up(t_window *window);
void key_left(t_window *window);
void key_right(t_window *window);
void view_rotate(t_window *window, int keycode);


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

