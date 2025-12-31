# Name
NAME = pipex

# Flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 -I.
INCLUDES = -I./includes -I./mylibft

# Paths
SRC_DIR = srcs
OBJ_DIR = objs
LIBFT_DIR = mylibft

LIBFT = $(LIBFT_DIR)/libft.a

# Srcs
SRCS = $(SRC_DIR)/main.c\
	$(SRC_DIR)/commands.c\
	$(SRC_DIR)/execution.c\
	$(SRC_DIR)/parsing.c\
	$(SRC_DIR)/child.c\
	$(SRC_DIR)/utils.c\
	$(SRC_DIR)/heredoc.c

# Obj
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

GREEN = \033[0;32m
RED = \033[0;31m
BLUE = \033[0;34m
RESET = \033[0m

all: $(NAME)

# Compilation program
$(NAME): $(LIBFT) $(OBJS)
	@echo "$(BLUE)Linking $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "$(GREEN)✓ $(NAME) compiled successfully!$(RESET)"

# Compilation files obj
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@echo "$(BLUE)Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Compilation mylibft
$(LIBFT):
	@echo "$(BLUE)Compiling libft...$(RESET)"
	@make -C $(LIBFT_DIR)
	@echo "$(GREEN)✓ libft compiled!$(RESET)"

# Clean obj files
clean:
	@echo "$(RED)Cleaning object files...$(RESET)"
	@rm -rf $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean
	@echo "$(GREEN)✓ Object files cleaned!$(RESET)"

# Complete clean
fclean: clean
	@echo "$(RED)Cleaning executables...$(RESET)"
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@echo "$(GREEN)✓ Full clean completed!$(RESET)"

# Complete recompilation
re: fclean all

# Leaks
valgrind: $(NAME)
	@echo "$(BLUE)Checking for memory leaks with valgrind...$(RESET)"
	@valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)

# Rule .PHONY
.PHONY: all clean fclean re test leaks valgrind
