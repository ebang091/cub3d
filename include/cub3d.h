
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
# define MAP 10
# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2

/*

111111
100001
1N0011
111111


111111
100001
100011
111111
*/
# define NORTH 0
# define SOUTH 1
# define WEST 2
# define EAST 3
# define F	5
# define C	6

# define CHARACTER 9
# define ERROR 1
# define SUCCESS 0
# define TRUE 1
# define FALSE 0


typedef struct s_image
{
	//배열로 바꿀 예정.
	void	*img;
	char 	*path;
	int		x;
	int		y;
	int		width;
	int		height;
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
	//window -> casting
	void		*mlx;
	void		*win;
	int			win_height;
	int			win_width;

	//map
	int 		map_col;
	int			map_row;
	char		**map;
	char		**worldmap;

	//player - global - casting.
	int			character_count;
	int			pos_x;
	int			pos_y;
	int			direction;



	//BFS
	t_node		*queue;
	int			queue_isempty;
	int			**visited;

	//	array 0 1 2 3
	t_image		W_img;
	t_image		E_img;
	t_image		N_img;
	t_image		S_img;

	int			exist_flag;


	//array  0 1
	t_rgb		ceiling;
	t_rgb		floor;
}	t_window;

//error_handle
int	ft_put_error(char *str);
int exit_error(char *str);

//save map
int 	save_map(t_window *window, char *path);
int		check_path_and_rgb(t_window *window, int fd);


//check map shape
int check_map_shape(t_window *window);

//queue

t_node *newnode(int y, int x);
void queue_push(t_window *window, int y, int x);
t_node *queue_pop(t_window *window);

//BFS

int		check_surrounded_by_walls_bfs(t_window *window);
void 	ft_clean(int** tab, int n);
void 	free_arr(int **arr, int row);

//utils
t_image	*find_direction(t_window *window, int flag);
int		*find_rgb(t_window *window, int flag, int i);
int		alphatodefnum(char ch);
int		findmax(int a, int b);
int		ft_isspace(char c);

//save_map, bfs에서 사용
int is_directionnum(int n);

//etc
void	print_map_utils(t_window *window);

#endif
