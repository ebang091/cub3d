/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghwk <seunghwk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 11:16:56 by seunghwk          #+#    #+#             */
/*   Updated: 2023/03/06 20:03:57 by seunghwk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLOBAL_H
# define GLOBAL_H

# define SUCCESS 0
# define FAILURE 1
# define WINDOW_X 640
# define WINDOW_Y 640
# define TEXTURE_X 64
# define TEXTURE_Y 64
# define MOVE_SPEED 1
# define ROTATE_SPEED 1

enum e_keys
{
	KEY_RELEASE = 3,
	KEY_PRESS = 2,
	X_BUTTON = 17,
	KEY_MAP = 10,
	KEY_ESC = 53,
	KEY_W = 13,
	KEY_A = 0,
	KEY_S = 1,
	KEY_D = 2,
	KEY_LEFT = 123,
	KEY_RIGHT = 124
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
	E = 69
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
	int		width;
	int		height;
	int		type;
}	t_images;

typedef struct s_player
{
	int	pos_x;
	int	pos_y;
	int	direction;
}	t_player;

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}	t_rgb;

typedef struct s_img
{
	void			*img_ptr;
	int				bpp;
	int				size_l;
	int				endian;
	unsigned int	*data;
}	t_img; // 추가

typedef struct s_vec {
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	pln_x;
	double	pln_y;
}	t_vec; // 추가

typedef struct s_ray {
	double	cam_x;
	double	raydir_x;
	double	raydir_y;
	int		map_x;
	int		map_y;
	double	deltadist_x;
	double	deltadist_y;
	double	sidedist_x;
	double	sidedist_y;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	double	wall_dist;
}	t_ray; //추가

typedef struct s_wall {
	int	side;
	int	tex_x;
	int	line_h;
	int	draw_start;
	int	draw_end;
}	t_wall; //추가

typedef struct s_window
{
	void		*mlx;
	void		*win;
	t_map		map;
	t_images	images;
	t_player	player;
	t_rgb		ceiling;
	t_rgb		floor;

	// 추가
	int			**temp;
	int			*texture[4];
	t_img		img;
	t_vec		vec;
}	t_window;

#endif // GlOBAL_H
