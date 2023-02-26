
#ifndef CUB3D_H
# define CUB3D_H
#include "../mlx/mlx.h"
#include "../libft/libft.h"
#include "./get_next_line.h"


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

# define NORTH 2
# define SOUTH 4
# define WEST 8
# define EAST 16
# define F	5
# define C	6

typedef struct s_image
{
	void	*img;
	char 	*path;
	int		width;
	int		height;
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
	int			character_count;
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
void	ft_put_error(char *str);

//utils

t_image	*find_direction(t_window *window, int flag);
int		*find_rgb(t_window *window, int flag, int i);
int		findmax(int a, int b);
int		alphatodefnum(char ch);
int		**return_array(int row, int col);

//utils2
void 	ft_clean(int** tab, int n);
void 	free_arr(int **arr, int row);
int		free_BFS(t_window *window);

//check map
int		check_map(t_window *window, char *path);
int		check_map_walls_edge(t_window *window);

//check map utils
int		get_path(t_window *window, char *path, int flag);
int 	get_rgb(t_window *window, char *str, int flag);
int		check_map_components_utils(t_window *window, char *str);

////check map utils2
int		check_map_walls(t_window *window);
void	print_map_utils(t_window *window);
int		is_direction(int c);
int		ft_isspace(char c);
int		check_map_contents_count(t_window *window);

//check map utils3
int		Cango(t_window *window, int y, int x);
int		is_directionnum(int c);

//BFS
int		BFS(t_window *window);
void	queue_push(t_window *window, int y, int x);
t_node	*queue_pop(t_window *window);

#endif