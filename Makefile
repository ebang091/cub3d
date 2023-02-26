NAME = cub3D
CC = cc -g
CFLAGS = -Wall -Wextra -Werror
SRCS = bfs.c check_map_shape.c error_handle.c etc.c main.c\
floor_casting.c wall_casting.c\
queue.c save_map.c save_path_and_rgb.c\
utils.c utils2.c\
save_map/gnl/get_next_line.c save_map/gnl/get_next_line_utils.c
SRCS_DIR = srcs/
SRCS_C = $(addprefix $(SRCS_DIR), $(SRCS))
OBJS = $(SRCS_C:.c=.o)
INC = include/cub3d.h
LIBFT = libft
MLX = mlx
CLIB = -L./libft -lft -Lmlx -lmlx -framework OpenGL -framework AppKit


all : $(NAME)

$(NAME) : $(OBJS)
	make -C $(LIBFT)
	make -C $(MLX)
	$(CC) $(CFLAGS) $(CLIB) -I $(INC) $(OBJS) -o $(NAME)

clean : 
	rm -rf $(OBJS)
	make -C $(LIBFT) clean
	make -C $(MLX) clean

fclean : clean
	rm -rf $(NAME)
	make -C $(LIBFT) fclean

re : fclean
	$(MAKE) all
.PHONY : all bonus clean fclean re
