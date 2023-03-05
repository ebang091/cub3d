/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeselee <yeselee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 11:16:56 by seunghwk          #+#    #+#             */
/*   Updated: 2023/03/05 23:12:39 by yeselee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLOBAL_H
# define GLOBAL_H

# define SUCCESS 0
# define FAILURE 1
# define SCREENHEIGHT 640
# define SCREENWIDTH 480
# define PIX 64
# define X_EVENT_KEY_PRESS 2

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
	KEY_D = 2
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

typedef struct s_window
{
	void			*mlx;
	void			*win;
	int				win_height;
	int				win_width;
	unsigned int	*buffer;
	t_map			map;
	t_images		images;
	t_player		player;
	t_rgb			ceiling;
	t_rgb			floor;
}	t_window;

#endif // GlOBAL_H
