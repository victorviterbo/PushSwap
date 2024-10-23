# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/01 12:45:22 by vviterbo          #+#    #+#              #
#    Updated: 2024/10/23 17:17:39 by vviterbo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pushswap

SRCS =	push.c swap.c main.c print.c rotate.c revrotate.c

OBJS = $(patsubst %.c, %.o, $(SRCS))

HEADER = PushSwap.h libft/libft.h

LIB = libft

CFLAGS = -Wall -Wextra -Werror

CC = cc


all: $(NAME)

clean :
	@rm -f $(OBJS)

fclean : clean
	@rm -f $(NAME)

re : fclean all

$(NAME): 
	@$(MAKE) -C libft/ bonus
	@$(CC) $(CFLAGS) $(SRCS) -o $(NAME) -I $(LIB)/libft.h -L $(LIB) -lft

.PHONY: all clean fclean re bonus
