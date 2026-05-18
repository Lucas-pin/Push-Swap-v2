# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lupin <lupin@student.42malaga.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/18 20:40:00 by lupin             #+#    #+#              #
#    Updated: 2026/05/18 20:46:16 by lupin            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = initial_test.c build_list.c linked_list_utils.c linked_list.c
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
