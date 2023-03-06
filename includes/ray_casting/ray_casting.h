#ifndef RAY_CASTING
# define RAY_CASTING

#include <stdlib.h>
#include "global.h"
#include <math.h>
#include "../utils/error.h"
#include "../libft/libft.h"
#include "../../mlx/mlx.h"

int check_key(int keycode, t_window *window);
void key_down(t_window *window);
void key_up(t_window *window);
void key_left(t_window *window);
void key_right(t_window *window);
void view_rotate(t_window *window, int keycode);

int check_key(int keycode, t_window *window);
int loop_function(t_window *window);
int	key_exit(void);

void ready_loop(t_window *window);

void	draw_background(t_window *window);
void ray_casting(t_window *window);

#endif