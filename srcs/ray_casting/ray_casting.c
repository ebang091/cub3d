
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
		window->images.texture[i].addr = (unsigned int*)mlx_get_data_addr(window->images.texture[i].img, &window->images.texture[i].bpp, &window->images.texture[i].size_l, &window->images.texture[i].endian);
	}
}

void	initial_malloc(t_window *window)
{
	window->buffer = (unsigned int *)malloc(sizeof(unsigned int)*SCREENHEIGHT * SCREENWIDTH + 1);
	if(!window->buffer)
		exit_error("Error\nmalloc failed");
}
//utils

void	draw_line(t_window *window, unsigned int *line, int startline, int endline)
{
	int	drawstart;
	int	drawend;
	int	w;
	int	i;
	int	j;

	drawstart = startline;
	drawend = endline;
	i = drawstart-1;
	w = SCREENWIDTH;
	line = line + 0;
	while (++i < drawend)
	{
		j = -1;
		while(++j < w)
			window->buffer[i * w + j] = line[i * w + j];
	}
}

unsigned int	make_bits_rgb(int r, int g, int b)
{
	unsigned int	color;

	color = (r << 16) + (g << 8) + b;
	return (color);
}
void	draw_background(t_window *window)
{
	unsigned int	fcolor;
	unsigned int	ccolor;
	unsigned int	*line;
	int	i;

	line = (unsigned int *)malloc(sizeof(unsigned int)*SCREENWIDTH);
	if (!line)
		exit_error("Error\nmalloc failed");
	fcolor = make_bits_rgb(window->floor.r, window->floor.b, window->floor.b);
	ccolor = make_bits_rgb(window->ceiling.r, window->ceiling.g, window->ceiling.b);
	i = -1;
	while(++i < SCREENWIDTH)
		line[i] = fcolor;
	draw_line(window, line, 0, SCREENHEIGHT/2);
	i = -1;
	while(++i < SCREENWIDTH)
		line[i] = ccolor;
	draw_line(window, line, SCREENHEIGHT/2, SCREENHEIGHT);
	free(line);
}

void ready_window(t_window *window)
{
	initial_malloc(window);
	printf("st");
	save_wall_texture(window);
}

void	save_buffer_to_image_addr(t_img img, unsigned int *buffer)
{
	unsigned int	*ret;
	int				i;
	int				j;

	
	i = -1;
	ret = img.addr;
	while (++i < SCREENHEIGHT)
	{
		j = -1;
		while (++j < SCREENWIDTH)
			ret[i * SCREENWIDTH + j] = buffer[i * SCREENWIDTH + j];
	}
	
}

int ray_casting(t_window *window)
{
	
	ready_window(window);
	draw_background(window);
	
	// t_img	img;
	// int w, h;
	// img.img= mlx_new_image(window->mlx, SCREENWIDTH, SCREENHEIGHT);
	// img.img = mlx_xpm_file_to_image(window->mlx, window->images.path[0], &w, &h);
	// img.addr= mlx_get_data_addr(img.img, &img.bpp, &img.size_l, &img.endian);
	save_buffer_to_image_addr (window->main_image, window->buffer);
	mlx_put_image_to_window(window->mlx, window->win, window->main_image.img, 0,0);
	/*

	int done = 0;
	int h = SCREENHEIGHT;
	int w = SCREENWIDTH;
	double dir_x = window->player.dir_x;
	double dir_y = window->player.dir_y;
	double plane_x = window->player.plane_x;
	double plane_y = window->player.plane_y;
	double pos_x = window->player.pos_x;
	double pos_y = window->player.pos_y;

	printf("start!\n");
	while(!done)
	{
		for(int x = 0; x < w; x++)
		{
			double camera_x = 2 * x / (double)(w) - 1;
			double ray_dir_x = dir_x + plane_x * camera_x;
			double ray_dir_y = dir_y + plane_y * camera_x;

//get_ray_dir_x , y		

		int map_x = (int)(pos_x);
		int map_y = (int)(pos_y);

		double side_dist_x; //시작점~ 첫번째 x면을 만나는 점까지의 광선 이동거리
		double side_dist_y; //시작점~ 첫번째 y면을 만나는 점까지의 광선 이동거리
		//side_dist는 나중에 의미가 변할 예정


		double perp_wall_dist; //광선의 이동거리를 계산하는 데 사용
//get delta_dist_x
//get delat_dist_y

		double delta_dist_x = sqrt(1 + (ray_dir_y * ray_dir_y) / (ray_dir_x * ray_dir_x)); //첫번째 x면 ~ 바로 다음 x면 까지의 광선 이동거리
		double delta_dist_y = sqrt(1 + (ray_dir_x * ray_dir_x) / (ray_dir_y * ray_dir_y));//첫번째 y면 ~ 바로 다음 y면 까지의 광선 이동거리

		int step_x;
		int step_y;

		int hit = 0; //벽과 부딪혔는지 여부 (루프 종료 조건) 벽과 부딪혔고 x면에 부딪힌 거라면 side 0; y면에 부딪히면 1. 

		//오른쪽 시야에서 x면에 부딪혔다면 E, 왼쪽 시야에서 x면에 부딪혔다면 W, y면에 부딪혔다면 N.
		int side; //어느 쪽 벽이 부딪혔나 확인.

		//step을 계산하고 side_dist를 초기화. 
	
	//get_side_dist
		if (ray_dir_x < 0)
		{
			step_x = -1;
			side_dist_x = (pos_x - map_x) * delta_dist_x;
		}
		else
		{
			step_x = 1;
			side_dist_x = (map_x + 1.0 - pos_x) * delta_dist_x;
		}
		if (ray_dir_y < 0)
		{
			step_y = -1;
			side_dist_y = (pos_y - map_y) * delta_dist_y;
		}
		else
		{
			step_y = 1;
			side_dist_y = (map_y + 1.0 - pos_y) * delta_dist_y;
		}

	//DDA 알고리즘 시작
	//DDA
		while (hit == 0)
		{
			if (side_dist_x < side_dist_y)//x면에 광선이 먼저 부딪혔는지 (벽은 아님)
			{
				if (ray_dir_x > 0)
					side = EAST;
				else
					side = WEST;
				side_dist_x += delta_dist_x;
				map_x += step_x;
			}
			else
			{
				if (ray_dir_y > 0)
					side = NORTH;
				else
					side = SOUTH;
				side_dist_y += delta_dist_y;
				map_y += step_y;
			}
			//벽에 부딪혔는지 확인
			if (window->map.worldmap[map_y][map_x] == WALL) hit = 1;
		}
	
		
		궁극적인 목표 : side_dist_x 구하고, side 값 구한뒤
		이를 이용해서 perp_wall_dist 구하기: 그릴 길이만큼의 값을 구한다.

		line_height : 맵의 '벽'픽셀 하나에서 벽이 그려질 끝 위치.

		
	

		if (side == EAST || side == WEST) perp_wall_dist = (map_x - pos_x + (1 - step_x) /2) / ray_dir_x;
		else	perp_wall_dist = (map_y - pos_y + (! -step_y) / 2 ) / ray_dir_y;
		
		//스크린에 그릴 크기 그리기
		int line_height = (int)(h / perp_wall_dist);

		//현재 줄ㅇ에서 가장 낮고 높은 픽셀(?) 지정하기
		int draw_start = -line_height / 2 + h /2;
		if (draw_start < 0) draw_start = 0;
		int draw_end = line_height / 2 + h / 2;
		if (draw_end >= h) draw_end = h - 1;

  int tex_num = side;
  double wallX; //where exactly the wall was hit
      if (side == 0) wallX = pos_y + perp_wall_dist * ray_dir_y;
      else           wallX = pos_x + perp_wall_dist * ray_dir_x;
      wallX -= floor((wallX));

 	int tex_x = (int)(wallX * (double)(window->images.width[tex_num]));
 	int tex_width = window->images.width[tex_num];
	int tex_height = window->images.height[tex_num];
      if(side == 0 && ray_dir_x> 0) tex_x = tex_width - tex_x - 1;
      if(side == 1 && ray_dir_y < 0) tex_x = tex_width - tex_x - 1;

 double step = 1.0 * tex_height / line_height;
      // Starting texture coordinate
      double tex_pos = (draw_start - h / 2 + line_height / 2) * step;
      for(int y = draw_start; y<draw_end; y++)
      {
        // Cast the texture coordinate to integer, and mask with (texHeight - 1) in case of overflow
        int tex_y = (int)tex_pos & (tex_height - 1);
        tex_pos += step;
		unsigned int color =  window->images.texture[tex_num].addr[tex_y * PIX + tex_x];
		if(side == 1) color = (color >> 1) & 8355711;
        //make color darker for y-sides: R, G and B byte each divided through two with a "shift" and an "and"
        window->buffer[y * w + x]= color;
      }
    }
	

//tex_X, tex_Y :  그림의 어느 부분을 그릴거냐!






}
	*/
	return (0);
}



// int draw_map( t_window *window)
// {
// 	char *str;
// 	int x;
// 	int y;
// 	int n;

// 	n = 0;
// 	x = 0;
// 	y = 0;
// 	mlx_clear_window(window->mlx, window->win);
// 	while (n < window->map_height)
// 	{
// 		str  = window->buffer[n];
// 		while(*str)
// 		{
// 			draw_img(x, y, *str, window);
// 			x += window->imges.width;
// 			str++;
// 		}
// 		x = 0;
// 		y += window->imges.height;
// 		n++;
// 	}
// 	return (0);
// }

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

	get_direction_vector(window);
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
	
	// draw_map(window);
	return (0);
}

void key_left(t_window *window)//코드 수정 필요
{
	char **worldmap;
	double *pos_x;
	double *pos_y;
	double plane_x;
	double plane_y;

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


