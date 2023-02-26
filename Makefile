NAME = cub3D
CC = cc -g
CFLAGS = -Wall -Wextra -Werror
SRCS = bfs.c utils.c main.c utils2.c check_map.c error_handle.c\
wall_casting.c check_map_utils.c check_map_utils2.c check_map_utils3.c\
check_wall.c\
gnl/get_next_line.c gnl/get_next_line_utils.c
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
