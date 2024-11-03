# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/01 12:45:22 by vviterbo          #+#    #+#              #
#    Updated: 2024/11/03 17:22:11 by vviterbo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

NAME_BONUS = checker

SRCS =	push.c swap.c main.c rotate.c revrotate.c utils.c simplify.c exit.c print.c

SRCS_BONUS = checker.c

OBJS = $(patsubst %.c, %.o, $(SRCS))

OBJS_BONUS = checker.o

LIB = libft/

CFLAGS = -Wall -Wextra -Werror

CC = cc

all: $(NAME)

clean :
	@rm -f $(OBJS)
	@rm -f $(OBJS_BONUS)

fclean : clean
	@rm -f $(NAME)
	@rm -f $(NAME_BONUS)

re : fclean all

$(NAME): 
	@$(MAKE) -C libft/ xtra
	@$(CC) $(CFLAGS) $(SRCS) -o $(NAME) -L $(LIB) -lft

bonus : all
	$(CC) $(CFLAGS) $(SRCS_BONUS) -o $(NAME_BONUS) -L $(LIB) -lft

.PHONY: all clean fclean re bonus
