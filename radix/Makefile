# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jchompoo <jchompoo@student.42bangkok.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/23 22:15:15 by jchompoo          #+#    #+#              #
#    Updated: 2024/06/29 23:59:41 by jchompoo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT_DIR = libft
INC_DIR = includes
SRCS = src/main.c \
       src/operation.c \
       src/operation_2.c \
       src/parser.c \
       src/sort.c \
       src/utils.c \
       src/ft_atol.c
OBJS = $(SRCS:.c=.o)
LIBFT = $(LIBFT_DIR)/libft.a
LIBS = -L$(LIBFT_DIR) -lft
HEADERS = -I$(INC_DIR) -I$(LIBFT_DIR)/includes/push_swap.h

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(HEADERS) $(LIBS) -o $(NAME)

$(OBJS) : %.o: %.c
	$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -rf $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -rf $(NAME)

re: fclean all
