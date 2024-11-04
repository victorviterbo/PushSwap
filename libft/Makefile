# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/01 12:45:22 by vviterbo          #+#    #+#              #
#    Updated: 2024/11/04 09:14:53 by vviterbo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS =	ft_strnstr.c ft_isdigit.c ft_putstr_fd.c ft_strlcpy.c ft_strlen.c ft_memcmp.c \
		ft_putnbr_fd.c ft_strchr.c ft_striteri.c ft_bzero.c ft_strjoin.c ft_isascii.c \
		ft_memcpy.c ft_isprint.c ft_putendl_fd.c ft_toupper.c ft_split.c ft_strrchr.c \
		ft_isalpha.c ft_memchr.c ft_putchar_fd.c ft_memset.c ft_substr.c ft_strncmp.c \
		ft_strmapi.c ft_strtrim.c ft_memmove.c ft_strlcat.c ft_calloc.c ft_strdup.c \
		ft_atoi.c ft_isalnum.c ft_itoa.c ft_tolower.c

SRCS_BONUS =	ft_lstadd_front_bonus.c ft_lstdelone_bonus.c ft_lstadd_back_bonus.c \
				ft_lstmap_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstlast_bonus.c \
				ft_lstsize_bonus.c ft_lstnew_bonus.c

SRCS_XTRA = ft_strjoin_ip.c ft_isnumber.c get_next_line_bonus.c

OBJS = $(patsubst %.c, %.o, $(SRCS))

OBJS_BONUS = $(patsubst %.c, %.o, $(SRCS_BONUS))

OBJS_XTRA = $(patsubst %.c, %.o, $(SRCS_XTRA))

HEADER = libft.h

CFLAGS = -Wall -Wextra -Werror

CC = cc

all: $(NAME)

clean :
	@rm -f $(OBJS)
	@rm -f $(OBJS_BONUS)
	@rm -f $(OBJS_XTRA)

fclean : clean
	@rm -f $(NAME)

re : fclean all

bonus : re $(OBJS_BONUS)
	@ar rcs $(NAME) $(OBJS)
	@ar rcs $(NAME) $(OBJS_BONUS)

xtra : bonus $(OBJS_XTRA)
	@ar rcs $(NAME) $(OBJS_XTRA)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)

$(OBJS) : $(SRCS)
	@$(CC) $(CFLAGS) -c $(SRCS) -I$(HEADER)

$(OBJS_BONUS) : $(OBJS) $(SRCS_BONUS)
	@$(CC) $(CFLAGS) -c $(SRCS_BONUS) -I$(HEADER)

$(OBJS_XTRA) : $(OBJS) $(OBJS_BONUS) $(SRCS_XTRA)
	@$(CC) $(CFLAGS) -c $(SRCS_XTRA) -I$(HEADER)

.PHONY: all clean fclean re bonus xtra
