# DIRECTORIES
BUILD	= .build
DEP_DIR	= $(BUILD)/dep
OBJ_DIR	= $(BUILD)/obj
DIRS	:= $(DEP_DIR) $(OBJ_DIR)

# FILES
NAME	= cub3d
CUB3D	= main.c parser.c parse_error.c parse_info.c get_next_line.c create.c \
		get_next_line_utils.c mapper.c create_ray.c raycast.c\
		create_window.c events.c destroy.c textures.c math.c create_game.c create_game1.c \
		create_game2.c create_sprite.c screenshot.c minimap.c debug.c

LIBFT	= ./libft/libft.a
MLX		= libmlx.a
SRC		= $(CUB3D)
DEP		:= $(SRC:%.c=$(DEP_DIR)/%.d)
OBJ		:= $(SRC:%.c=$(OBJ_DIR)/%.o)

# COMPILATION
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra -Ofast -fno-builtin
DFLAGS	= -MP -MMD -MF $(DEP_DIR)/$*.d -MT '$@'
LIB		= -I./include -L./libft -lft
F_MLX	= -Imlx -L./mlx -lmlx -framework OpenGL -framework AppKit -lm

$(NAME):  $(MLX) $(LIBFT) $(OBJ)
	@echo "\n\033[01mThe compilation of \033[00m"
	@echo "\033[32m	 ██████╗██╗   ██╗██████╗ ██████╗ ██████╗ \033[00m"
	@echo "\033[32m	██╔════╝██║   ██║██╔══██╗╚════██╗██╔══██╗\033[05m"
	@echo "\033[32m	██║     ██║   ██║██████╔╝ █████╔╝██║  ██║\033[00m"
	@echo "\033[32m	██║     ██║   ██║██╔══██╗ ╚═══██╗██║  ██║\033[00m"
	@echo "\033[32m	╚██████╗╚██████╔╝██████╔╝██████╔╝██████╔╝ \033[00m"
	@echo "\033[32m	 ╚═════╝ ╚═════╝ ╚═════╝ ╚═════╝ ╚═════╝ \033[00m"
	@echo "\033[32m				\033[03mHas been achieved!\n\033[00m"
	@$(CC) $(LIB) $(F_MLX) $(OBJ) $(LIBFT) -o $(NAME)

$(MLX):
	@make -C ./mlx

$(LIBFT):
	@make bonus -C ./libft

all: $(NAME)

clean:
	@rm -rf $(BUILD)
	@echo "\033[1;34mExecute:\t\033[1;33mCleaning build\t\033[0;32m[OK]\033[0m"

fclean: clean
	@rm -f $(NAME)
	@make -C ./mlx clean
	@make -C ./libft fclean
	@echo "\033[1;34mExecute:\t\033[1;33mCleaning exec\t\033[0;32m[OK]\033[0m"

re: fclean all

$(BUILD):
	@echo "\033[1;32m\nCreation of .build\033[0m \n"
	@mkdir $@ $(DIRS)

$(OBJ_DIR)/%.o: src/%.c | $(BUILD)
	@echo "\033[1;34mExecute: \t\033[1;33mCompilation of \033[1;36m$(notdir $<)\033[0m"
	@$(CC) -Iinclude $(CFLAGS) $(DFLAGS) -c $< -o $@

-include $(DEP)

.PHONY: all clean fclean re
