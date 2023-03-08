# ---------------------------------------------------------------------------- #
#   Define the compiler and flags                                              #
# ---------------------------------------------------------------------------- #

CC					:=	cc
CFLAGS				:=	-Wall -Wextra -Werror
CPPFLAGS			=	-I includes -I $(LIBFT) -I $(MLX)
DEPFLAGS			=	-MMD -MP -MF $(BUILD_DIR)/$(DEP_DIR)/$*.d
LDFLAGS				=	-L$(LIBFT) -L$(MLX)
LDLIBS				=	-lft -lmlx

# ---------------------------------------------------------------------------- #
#	Define the libraries													   #
# ---------------------------------------------------------------------------- #

LIBFT				:= libft
MLX					:= mlx

# ---------------------------------------------------------------------------- #
#   Define the directories                                                     #
# ---------------------------------------------------------------------------- #

LIBFT_DIR			:=	libft
MLX_DIR				:=	mlx
SRC_DIR				:=	srcs
SET_WINDOW_DIR		:=	set_window
CHECK_WINDOW_DIR	:=	check_window
RUN_CUB3D_DIR		:=	run_cub3d
UTILS_DIR			:=	utils
BUILD_DIR			:=	build
OBJ_DIR				:=	objs
DEP_DIR				:=	deps

# ---------------------------------------------------------------------------- #
#   Define the source files                                                    #
# ---------------------------------------------------------------------------- #

SRCS				:=	$(addprefix $(SRC_DIR)/, main.c)
SRCS				+=	$(addprefix $(SRC_DIR)/$(SET_WINDOW_DIR)/, set_window.c set_path_rgb_map.c utils_0.c utils_1.c)
SRCS				+=	$(addprefix $(SRC_DIR)/$(CHECK_WINDOW_DIR)/, check_window.c check_surrounded_by_walls.c)
SRCS				+=	$(addprefix $(SRC_DIR)/$(RUN_CUB3D_DIR)/, run_cub3d.c init_cub3d.c draw_cub3d.c key_press.c ray_casting.c)
SRCS				+=	$(addprefix $(SRC_DIR)/$(UTILS_DIR)/, error.c get_next_line.c get_next_line_utils.c)
OBJS				:=	$(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/$(OBJ_DIR)/%.o, $(SRCS))
DEPS				:=	$(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/$(DEP_DIR)/%.d, $(SRCS))

# ---------------------------------------------------------------------------- #
#   Define the target                                                          #
# ---------------------------------------------------------------------------- #

NAME				:=	cub3d

# ---------------------------------------------------------------------------- #
#   Define the rules                                                           #
# ---------------------------------------------------------------------------- #

all :
	@$(MAKE) -C $(LIBFT)
	@$(MAKE) -C $(MLX)
	@$(MAKE) -j $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(LDFLAGS) -framework OpenGl -framework AppKit $^ -o $@ $(LDLIBS)
	@printf "\n[$(NAME)] Linking Success\n"

$(BUILD_DIR)/$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c | dir_guard
	@$(CC) $(CFLAGS) $(CPPFLAGS) $(DEPFLAGS) -c $< -o $@

clean :
	@$(MAKE) -C $(LIBFT) fclean
	@$(MAKE) -C $(MLX) clean
	@$(RM) -r $(BUILD_DIR)

fclean : clean
	@$(RM) $(NAME)

re : fclean
	@$(MAKE)

dir_guard :
	@mkdir -p $(addprefix $(BUILD_DIR)/$(OBJ_DIR)/, $(SET_WINDOW_DIR) \
	$(CHECK_WINDOW_DIR) $(RUN_CUB3D_DIR) $(UTILS_DIR))
	@mkdir -p $(addprefix $(BUILD_DIR)/$(DEP_DIR)/, $(SET_WINDOW_DIR) \
	$(CHECK_WINDOW_DIR) $(RUN_CUB3D_DIR) $(UTILS_DIR))

.PHONY : all clean fclean re dir_guard

-include $(DEPS)
