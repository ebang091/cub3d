
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
# define NORTH 2
# define SOUTH 4
# define WEST 8
# define EAST 16
# define F	5
# define C	6

# define ERROR 1
# define SUCCESS 0


typedef struct s_image
{
	void	*img[4];
	char 	*path[4];
	int		x[4];
	int		y[4];
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
	char		**map_char;
	int			**worldmap;

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

int		is_directionnum(int c);

//queue
t_node *newnode(int y, int x);
void queue_push(t_window *window, int y, int x);
t_node *queue_pop(t_window *window);


/*

이 아래로는 

아직

정리 안된 함수들 

*/

t_image	*find_direction(t_window *window, int flag);
int		*find_rgb(t_window *window, int flag, int i);

//map_shape


int		alphatodefnum(char ch);
int		**return_array(int row, int col);

//utils2
void 	ft_clean(int** tab, int n);
void 	free_arr(int **arr, int row);

int		findmax(int a, int b);
//check map
int		check_map(t_window *window, char *path);

//check_path_and_rgb


////check map utils2
int		check_map_walls(t_window *window);
void	print_map_utils(t_window *window);
int		is_direction(int c);
int		ft_isspace(char c);
int		check_map_contents_count(t_window *window);

//check map utils3
int		Cango(t_window *window, int y, int x);


//BFS
int		bfs(t_window *window);
void	queue_push(t_window *window, int y, int x);
t_node	*queue_pop(t_window *window);

#endif