# ---------------------------------------------------------------------------- #
#   Define the compiler and flags                                              #
# ---------------------------------------------------------------------------- #
CC					:=	cc
CFLAGS				:=	-Wall -Wextra -Werror -fsanitize=address
CPPFLAGS			:=	-I includes #-I $(libft) -I $(mlx)
#DEPFLAGS			:=	-MMD -MP -MF $(BUILD_DIR)/$(DEP_DIR)/$*.d
#LDFLAGS			:=	-L libft/libft.a -L $mlx/mlx.a
#LDLIBS				:=	-l $(libft) -l $(mlx)
#----------------------	------------------------------------------------------- #
#   Define the libraries                                                       #
# ---------------------------------------------------------------------------- #
libft				:=	libft
mlx					:=	mlx
# ---------------------------------------------------------------------------- #
#   Define the directories                                                     #
# ---------------------------------------------------------------------------- #
SRC_DIR				:=	srcs
SET_WINDOW_DIR		:=	set_window
UTILS_DIR			:=	utils
BUILD_DIR			:=	build
OBJ_DIR				:=	obj
DEP_DIR				:=	dep
RAY_CASTING_DIR		:=	ray_casting
# ---------------------------------------------------------------------------- #
#   Define the source files                                                    #
# ---------------------------------------------------------------------------- #
SRCS				:=	$(addprefix $(SRC_DIR)/, main.c)
SRCS				+=	$(addprefix $(SRC_DIR)/$(SET_WINDOW_DIR)/, set_window.c set_images_rgb_map.c utils_0.c utils_1.c)
SRCS				+=	$(addprefix $(SRC_DIR)/$(UTILS_DIR)/, error.c get_next_line.c get_next_line_utils.c)
SRCS				+=	$(addprefix $(SRC_DIR)/$(RAY_CASTING_DIR)/, ray_casting.c key_hook.c loop.c loop_utils.c ready_loop.c)
OBJS				:=	$(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/$(OBJ_DIR)/%.o, $(SRCS))
DEPS				:=	$(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/$(DEP_DIR)/%.d, $(SRCS))
# ---------------------------------------------------------------------------- #
#   Define the variables for progress bar                                      #
# ---------------------------------------------------------------------------- #
TOTAL_FILES			:=	$(shell echo $(SRCS) | wc -w)
COMPILED_FILES		:=	0
STEP				:=	100
# ---------------------------------------------------------------------------- #
#   Define the target                                                          #
# ---------------------------------------------------------------------------- #
NAME				:=	cub3d
# ---------------------------------------------------------------------------- #
#   Define the rules                                                           #
# ---------------------------------------------------------------------------- #
all: $(libft) $(mlx)
	@$(MAKE) -C $(libft)
	@$(MAKE) -C $(mlx)
	@$(MAKE) -j $(NAME)
$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $^ -o $@  -L./libft/ -lft -L./mlx/ -lmlx -framework OpenGL -framework AppKit
	@printf "\n$(MAGENTA)[$(NAME)] Linking Success\n$(DEF_COLOR)"

$(BUILD_DIR)/$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c | dir_guard
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@ $(LDLIBS)
	@$(eval COMPILED_FILES = $(shell expr $(COMPILED_FILES) + 1))
	@$(eval PROGRESS = $(shell expr $(COMPILED_FILES) "*" $(STEP) / $(TOTAL_FILES)))
	@printf "                                                                                                   \r"
	@printf "$(YELLOW)[$(NAME)] [%02d/%02d] ( %3d %%) Compiling $<\r$(DEF_COLOR)" $(COMPILED_FILES) $(TOTAL_FILES) $(PROGRESS)
clean:
	@$(MAKE) -C $(libft) clean
	@$(MAKE) -C $(mlx) clean
	@$(RM) -r $(BUILD_DIR)
	@printf "$(BLUE)[$(NAME)] obj. dep. files$(DEF_COLOR)$(GREEN)  => Cleaned!\n$(DEF_COLOR)"
fclean:
	@$(MAKE) -C $(libft) fclean
	@$(MAKE) -C $(mlx) clean
	@$(RM) -r $(BUILD_DIR) $(NAME)
	@printf "$(BLUE)[$(NAME)] obj. dep. files$(DEF_COLOR)$(GREEN)  => Cleaned!\n$(DEF_COLOR)"
	@printf "$(CYAN)[$(NAME)] exec. files$(DEF_COLOR)$(GREEN)  => Cleaned!\n$(DEF_COLOR)"
re: fclean
	@$(MAKE) -C $(libft)
	@$(MAKE) all
	@printf "$(GREEN)[$(NAME)] Cleaned and rebuilt everything!\n$(DEF_COLOR)"
dir_guard:
	@mkdir -p $(addprefix $(BUILD_DIR)/$(OBJ_DIR)/, $(SET_WINDOW_DIR) \
	$(UTILS_DIR) $(RAY_CASTING_DIR))
	@mkdir -p $(addprefix $(BUILD_DIR)/$(DEP_DIR)/, $(SET_WINDOW_DIR) \
	$(UTILS_DIR) $(RAY_CASTING_DIR))
norm:
	@(norminette | grep Error) || (printf "$(GREEN)[$(NAME)] Norminette Success\n$(DEF_COLOR)")
.PHONY: all clean fclean re dir_guard norm
# ---------------------------------------------------------------------------- #
#   Define the colors                                                          #
# ---------------------------------------------------------------------------- #
DEF_COLOR   =   \033[1;39m
GRAY        =   \033[1;90m
RED         =   \033[1;91m
GREEN       =   \033[1;92m
YELLOW      =   \033[1;93m
BLUE        =   \033[1;94m
MAGENTA     =   \033[1;95m
CYAN        =   \033[1;96m
WHITE       =   \033[1;97m
-include $(DEPS)
