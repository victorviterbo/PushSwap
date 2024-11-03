# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/01 12:45:22 by vviterbo          #+#    #+#              #
#    Updated: 2024/11/03 17:03:47 by vviterbo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker

SRCS =	checker.c

OBJS = checker.o

LIB = ../libft

CFLAGS = -Wall -Wextra -Werror

CC = cc

all: $(NAME)

clean :
	@rm -f $(OBJS)

fclean : clean
	@rm -f $(NAME)

re : fclean all

$(NAME):
	@$(CC) $(CFLAGS) $(SRCS) -o $(NAME) -I $(LIB)/libft.h -L $(LIB) -lft

all: $(NAME)

clean :
	@rm -f $(OBJS)

fclean : clean
	@rm -f $(NAME)

.PHONY: all clean fclean re bonus
