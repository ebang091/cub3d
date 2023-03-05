#ifndef RAY_CASTING
# define RAY_CASTING

#include <stdlib.h>
#include "global.h"
#include "../utils/error.h"
#include "../libft/libft.h"
#include "../../mlx/mlx.h"

int check_key(int keycode, t_window *window);
void key_down(t_window *window);
void key_up(t_window *window);
void view_rotate(t_window *window, int keycode);

void get_direction_vector(t_window *window);
void draw_img(int x, int y, char type, t_window *window);
int ray_casting(t_window *window);
void ready_window(t_window *window);
int	make_bits_rgb(int r, int g, int b);

#endif