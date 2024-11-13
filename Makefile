# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/01 12:45:22 by vviterbo          #+#    #+#              #
#    Updated: 2024/11/13 08:44:16 by vviterbo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

NAME_BONUS = checker

SRCS =	push.c swap.c rotate.c revrotate.c utils.c write_out.c print.c

SRCS_BONUS = checker.c

OBJS = $(patsubst %.c, %.o, $(SRCS))

OBJS_BONUS = checker.o

LIB = libft/

CFLAGS = -Wall -Wextra -Werror

CC = cc

all: $(NAME)

clean :
	@$(MAKE) -C libft/ clean
	@rm -f $(OBJS)
	@rm -f $(OBJS_BONUS)

fclean : clean
	@$(MAKE) -C libft/ fclean
	@rm -f $(NAME)
	@rm -f $(NAME_BONUS)

re : fclean all

$(NAME): 
	@$(MAKE) -C libft/ xtra
	@$(CC) $(CFLAGS) $(SRCS) radixsort.c usort.c minisort.c mergesort.c -o $(NAME) -L $(LIB) -lft

bonus : re
	@$(CC) $(CFLAGS) $(SRCS) $(SRCS_BONUS) -o $(NAME_BONUS) -L $(LIB) -lft -I .

.PHONY: all clean fclean re bonus
