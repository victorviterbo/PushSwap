# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: victorviterbo <victorviterbo@student.42    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/01 12:45:22 by vviterbo          #+#    #+#              #
#    Updated: 2025/09/02 11:40:59 by victorviter      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = PushSwap

NAME_BONUS = checker

SRCS =	LIS.c minisort.c utils.c write_out.c push.c swap.c rotate.c revrotate.c 

OBJS = $(patsubst %.c, %.o, $(SRCS))

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
	@$(MAKE) -C libft/ all
	@$(CC) $(CFLAGS) $(SRCS) main.c -o $(NAME) -L $(LIB) -lft

bonus : re
	@$(CC) $(CFLAGS) $(SRCS) checker.c -o $(NAME_BONUS) -L $(LIB) -lft -I .

.PHONY: all clean fclean re bonus
