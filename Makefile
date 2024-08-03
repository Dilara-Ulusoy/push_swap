NAME = push_swap
SRCS = main.c error_handling.c parsing.c stack_utils.c parsing_utils.c algorithm.c big_sort_utils.c stack_init.c sort.c stack_b_manage.c swap_op.c rotate_op.c push_op.c
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT_DIR = Libft/
LIBFT = $(LIBFT_DIR)libft.a
PRINTF_DIR = Printf/
PRINTF = $(PRINTF_DIR)libftprintf.a
INCLUDES = -I$(LIBFT_DIR) -I$(PRINTF_DIR)

OBJS = $(SRCS:.c=.o)

all: $(NAME)

# Ensure both regular and bonus parts of libft.a are built
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR) bonus

# Build push_swap executable
$(NAME): $(OBJS) $(LIBFT) $(PRINTF)
	$(CC) $(OBJS) $(LIBFT) $(PRINTF) -o $(NAME)

# Build object files from source files
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Build the printf library
$(PRINTF):
	$(MAKE) -C $(PRINTF_DIR)

# Clean object files and libraries
clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(PRINTF_DIR) clean

# Full clean, including libraries and executable
fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(PRINTF_DIR) fclean

# Recompile everything
re: fclean all

.PHONY: all clean fclean re
