/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjungbang <eunjungbang@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 11:16:56 by seunghwk          #+#    #+#             */
/*   Updated: 2023/03/03 22:01:16 by eunjungbang      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLOBAL_H
# define GLOBAL_H

# define SUCCESS 0
# define FAILURE 1
# define SCREENHEIGHT 640
# define SCREENWIDTH 480


enum e_keys
{
	KEY_RELEASE = 3,
	KEY_PRESSS = 2,
	X_BUTTON = 17,
	KEY_MAP = 10,
	KEY_ESC = 53,
	KEY_W = 13,
	KEY_A = 0,
	KEY_S = 1,
	KEY_D = 2,
	KEY_RIGHT = 11,
	KEY_LEFT = 12
};

enum e_directions
{
	NORTH = 0,
	SOUTH = 1,
	WEST = 2,
	EAST = 3
};

enum e_objects
{
	WALL = 49,
	FLOOR = 48,
	EMPTY = 32,
	N = 78,
	S = 83,
	W = 87,
	E = 69,
	F = 'F',
	C = 'C'
};

typedef struct s_map
{
	int		height;
	int		width;
	char	**worldmap;
}	t_map;

typedef struct s_images
{
	void	*img[4];
	char	*path[4];
	int		width[4];
	int		height[4];
	int		type;
	int		bpp[4];
	int		size_l[4];
	int		endian[4];
}	t_images;

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	int	direction;
	double rot_speed;
	double dir_x;
	double dir_y;
	double plane_x;
	double plane_y;

}	t_player;

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}	t_rgb;

typedef struct s_window
{
	void		*mlx;
	void		*win;
	int			win_height;
	int			win_width;
	t_map		map;
	t_images	images;
	t_player	player;
	t_rgb		ceiling;
	t_rgb		floor;
	int			queue_isempty;	//삭제 가능
	int			**visited;		//삭제 가능
	int			buffer[1924][100];
}	t_window;
int check_key(int keycode, t_window *window);
#endif // GlOBAL_H
