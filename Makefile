# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lupin <lupin@student.42malaga.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/18 20:40:00 by lupin             #+#    #+#              #
#    Updated: 2026/05/21 21:22:39 by lupin            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = complete_test_moves.c build_list.c linked_list_utils.c linked_list.c \
		moves/push.c moves/rotate.c moves/rev_rotate.c moves/swap.c \
		algorithms/insertion_sort.c
OBJS = $(SRCS:.c=.o)

NAME = test
LIBFT = libft/libft.a

RM = rm -f

all: $(LIBFT) $(NAME)

$(LIBFT):
	@$(MAKE) -C libft

$(NAME): $(OBJS) $(LIBFT) push_swap.h
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

run: all
	@./$(NAME) $(ARGS)

valgrind: all
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME) $(ARGS)

clean:
	@$(RM) $(OBJS)
	@$(MAKE) -C libft clean
	@echo "Objects removed"

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(LIBFT)
	@echo "Full clean done"

re: fclean all

.PHONY: all run valgrind clean fclean re
