# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Olly <Olly@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/31 15:30:47 by Olly              #+#    #+#              #
#    Updated: 2024/07/31 16:16:56 by Olly             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
SRCS = pipex.c utils.c path.c
OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

INCLUDES = -I./includes -I$(LIBFT_DIR)

all: $(LIBFT) $(NAME)

$(NAME): $(OBJS)
	gcc $(CFLAGS) $(OBJS) $(INCLUDES) -o $(NAME) $(LIBFT)

$(LIBFT):
	@echo "Making Libft.."
	@make -C $(LIBFT_DIR)

clean:
	@echo "Removing .o files"
	rm -f $(OBJS)
	@make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	@make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re
