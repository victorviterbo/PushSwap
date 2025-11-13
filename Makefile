# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: victorviterbo <victorviterbo@student.42    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/01 12:45:22 by vviterbo          #+#    #+#              #
#    Updated: 2025/11/13 17:01:01 by victorviter      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

MS = merge_sort

BONUS = checker

SDIR		=	srcs/
IDIR		=	include/
LDIR		=	lib/
ODIR		=	objs/

SRC_LIS		=	main.c LIS.c minisort.c utils.c \
				write_out.c push.c swap.c rotate.c revrotate.c 
				
SRC_MS		=	main_ms.c usort.c mergesort.c minisort.c utils.c \
				write_out.c push.c swap.c rotate.c revrotate.c 
				
SRC_BONUS	=	checker.c utils.c write_out.c push.c swap.c rotate.c revrotate.c 

OBJS_LIS	=	$(addprefix $(ODIR), $(SRC_LIS:.c=.o))
OBJS_MS		=	$(addprefix $(ODIR), $(SRC_MS:.c=.o))
OBJS_BONUS	=	$(addprefix $(ODIR), $(SRC_BONUS:.c=.o))
SRCS_LIS	=	$(addprefix $(SDIR), $(SRC_LIS))
SRCS_MS		=	$(addprefix $(SDIR), $(SRC_MS))
SRCS_BONUS	=	$(addprefix $(SDIR), $(SRC_BONUS))

LIBFT		=	$(LDIR)libft/libft.a

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror

IFLAGS		=	-I $(IDIR)

LFLAGS	=	-L $(LDIR)libft/ -lft

RM			=	rm -rf

all			:	$(NAME)

bonus		:	$(BONUS)

merge_sort	:	$(MS)

$(NAME)		:	$(LIBFT) $(ODIR) $(OBJS_LIS)
				@$(CC) $(CFLAGS) $(IFLAGS) $(OBJS_LIS) $(LFLAGS) -o $(NAME)
				@make -s header
				@printf "$(COLOR_G)[OK] $(NAME) is ready!$(C_RESET)\n" || \
				printf "$(COLOR_R)[KO] Something went wrong.$(C_RESET)\n"

$(MS)		:	$(LIBFT) $(ODIR) $(OBJS_MS)
				@$(CC) $(CFLAGS) $(IFLAGS) $(OBJS_MS) $(LFLAGS) -o $(MS)
				make -s header
				@printf "$(COLOR_G)[OK] $(MS) is ready!$(C_RESET)\n" || \
				printf "$(COLOR_R)[KO] Something went wrong.$(C_RESET)\n"

$(BONUS)	:	$(LIBFT) $(ODIR) $(OBJS_BONUS)
				@$(CC) $(CFLAGS) $(IFLAGS) $(OBJS_BONUS) $(LFLAGS) -o $(BONUS)
				@make -s header
				@printf "$(COLOR_G)[OK] $(BONUS) is ready!$(C_RESET)\n" || \
				printf "$(COLOR_R)[KO] Something went wrong.$(C_RESET)\n"

$(ODIR)		:
				@mkdir -p $(ODIR)
				@printf "Object directory created.\n"

$(ODIR)%.o	:	$(SDIR)%.c
				@echo "Compiling $<..."
				@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@ || \
				(printf "$(COLOR_R)[KO] Compilation failed.$(C_RESET)\n" && false)

$(LIBFT)	:	
				@printf "$(COLOR_B)Building libft...$(C_RESET)\n"
				@make -sC $(LDIR)libft
				@printf "$(COLOR_G)[OK] libft is ready!$(C_RESET)\n" || \
				(printf "$(COLOR_R)[KO] Failed to build libft.$(C_RESET)\n" && false)

clean		:
				@echo "Removing object files..."
				$(RM) $(ODIR)
				@printf "$(COLOR_O)[OK] All object files have been removed.$(C_RESET)\n"

fclean		:
				@echo "Removing object and binary files..."
				@$(RM) $(ODIR)
				@$(RM) $(NAME)
				@printf "$(COLOR_O)[OK] All binary files have been removed.$(C_RESET)\n"

re			:	fclean all

.PHONY		:	all clean fclean re bonus merge_sort
.SILENT		:	all bonus $(NAME) $(ODIR) $(OBJS) clean fclean re norm header

COLOR_R		= \033[31m
COLOR_O		= \033[38;5;214m
COLOR_Y		= \033[33m
COLOR_G		= \033[32m
COLOR_B		= \033[34m
COLOR_V		= \033[38;5;93m
COLOR_I		= \033[3m
C_RESET		= \033[0m

header	:
			printf "=====================================================\n"
			printf "$(COLOR_O) ____  _   _ ____  _   _   ______        ___    ____  $(C_RESET)\n"
			printf "$(COLOR_R)|  _ \| | | / ___|| | | | / ___\ \      / / \  |  _ \ $(C_RESET)\n"
			printf "$(COLOR_G)| |_) | | | \___ \| |_| | \___ \\ \ /\ / / _ \ | |_) |$(C_RESET)\n"
			printf "$(COLOR_B)|  __/| |_| |___) |  _  |  ___) |\ V  V / ___ \|  __/ $(C_RESET)\n"
			printf "$(COLOR_V)|_|    \___/|____/|_| |_| |____/  \_/\_/_/   \_\_|    $(C_RESET)\n"
			printf "$(COLOR_I)          				  by vviterbo$(C_RESET)\n"
			printf "=====================================================\n"
