# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lupin <lupin@student.42malaga.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/18 20:40:00 by lupin             #+#    #+#              #
#    Updated: 2026/05/25 22:15:18 by lupin            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = complete_test_moves.c lists/build_list.c lists/build_list_utils.c lists/linked_list_utils.c lists/linked_list.c lists/error_list.c \
		moves/push.c moves/rotate.c moves/rev_rotate.c moves/swap.c \
		algorithms/insertion_sort.c	algorithms/chunk_sort.c algorithms/disorder_index.c algorithms/radix_sort.c \
		moves/orchestor.c
	
OBJ_DIR = obj
OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)
HEADER = push_swap.h
NAME = push_swap
LIBFT = libft/libft.a

RM = rm -rf

# All needs to be always the first rule
all: $(LIBFT) $(NAME)

# Compiling at the beggining the libft
$(LIBFT):
	@$(MAKE) -C libft

# Creating the executable
$(NAME): $(OBJS) $(LIBFT) $(HEADER)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

# Object compilation in a hide directory
$(OBJ_DIR)/%.o: %.c $(HEADER)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Run the executable with the args given
run: all
	@./$(NAME) $(ARGS)

# Run the executable with the args given and using valgrind
valgrind: all
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME) $(ARGS)

# Cleaning objects
clean:
	@$(RM) $(OBJ_DIR)
	@$(MAKE) -C libft clean
	@echo "Objects removed"

# Full clean
fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(LIBFT)
	@echo "Full clean done"

re: fclean all

.PHONY: all run valgrind clean fclean re
