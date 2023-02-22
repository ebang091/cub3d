
#ifndef CUB3D_H
# define CUB3D_H
#include "minilibx_opengl_20191021/mlx.h"
#include "minilibx_opengl_20191021/mlx_int.h"
#include "minilibx_opengl_20191021/mlx_png.h"

# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <unistd.h>

# define KEY_RELEASE 3
# define KEY_PRESS 2
# define X_BUTTON 17

# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2

#define NORTH 1
#define SOUTH 2
#define WEST 3
#define EAST 4
#define F	5
#define C	6

typedef struct s_image
{
	void	*img;
	char 	*path;
	int		width;
	int		height;
	int		count;
	int		x;
	int		y;
}	t_image;

typedef struct s_rgb{
	int r;
	int g;
	int b;
}t_rgb;

typedef struct s_node
{
	int y;
	int x;
	struct s_node *next;
}t_node;

typedef struct s_window
{
	void		*mlx;
	void		*win;
	int			win_height;
	int			win_width;
	int 		map_col;
	int			map_row;
	int			pos_x;
	int			pos_y;
	int			direction;
	char		**map;
	int			**worldmap;
	char		**map_char;
	int			exist_flag;
	t_node		*queue;
	int			queue_isempty;
	int			**visited;

	t_image		W_img;
	t_image		E_img;
	t_image		N_img;
	t_image		S_img;
	t_rgb		ceiling;
	t_rgb		floor;
}	t_window;


//error_handle
void	ft_put_error(char **str);

//utils
t_image	*find_direction(t_window *window, int flag);
int		*find_rgb(t_window *window, int flag, int i);
int		findmax(int a, int b);
int		alphatodefnum(char ch);
int	**return_array(int row, int col);

//utils2
void ft_clean(char** str, int n);
void free_arr(int **arr, int row)

//check map
int		check_map(t_window *window, char *argv);

//check map utils
void	get_path(t_window *window, char *path, int flag);
void 	get_rgb(t_window *window, char *str, int flag);
int		check_map_components_utils(t_window *window, char *str);

////check map utils2
void	check_map_walls(t_window *window);


//BFS
int		BFS(t_window *window, int starty, int startx);
void	queue_push(t_window *window, int y, int x);

#endif